#include "image_enhancement.h"

#include <cmath>
#include <vector>
#include <algorithm>
#include <numeric>

namespace image_enhancement {

// ---------------------------------------------------------------------------
// Internal helpers
// ---------------------------------------------------------------------------

namespace detail {

cv::Mat to_gray(const cv::Mat& src)
{
    if (src.channels() == 1) return src;
    cv::Mat gray;
    cv::cvtColor(src, gray, cv::COLOR_BGR2GRAY);
    return gray;
}

cv::Mat apply_clahe_to_luminance(const cv::Mat& bgr, double clip, cv::Size grid)
{
    cv::Mat lab;
    cv::cvtColor(bgr, lab, cv::COLOR_BGR2Lab);
    std::vector<cv::Mat> ch;
    cv::split(lab, ch);
    auto clahe = cv::createCLAHE(clip, grid);
    clahe->apply(ch[0], ch[0]);
    cv::merge(ch, lab);
    cv::Mat result;
    cv::cvtColor(lab, result, cv::COLOR_Lab2BGR);
    return result;
}

} // namespace detail

// ---------------------------------------------------------------------------
// analyze_brightness
// ---------------------------------------------------------------------------

BrightnessAnalysis analyze_brightness(
    const cv::Mat& frame,
    uchar dark_threshold,
    uchar bright_threshold
)
{
    BrightnessAnalysis result;
    if (frame.empty()) return result;

    cv::Mat gray = detail::to_gray(frame);

    cv::Scalar mean_val, stddev_val;
    cv::meanStdDev(gray, mean_val, stddev_val);
    result.mean_luminance = mean_val[0];
    result.std_dev        = stddev_val[0];

    const int total = gray.rows * gray.cols;

    // Dark pixel ratio
    cv::Mat dark_mask, bright_mask;
    cv::threshold(gray, dark_mask,   dark_threshold,   255, cv::THRESH_BINARY_INV);
    cv::threshold(gray, bright_mask, bright_threshold, 255, cv::THRESH_BINARY);

    result.dark_pixel_ratio   = static_cast<double>(cv::countNonZero(dark_mask))   / total;
    result.bright_pixel_ratio = static_cast<double>(cv::countNonZero(bright_mask)) / total;

    if (result.mean_luminance < 60.0 || result.dark_pixel_ratio > 0.6)
        result.exposure = ExposureState::UNDEREXPOSED;
    else if (result.mean_luminance > 200.0 || result.bright_pixel_ratio > 0.6)
        result.exposure = ExposureState::OVEREXPOSED;
    else
        result.exposure = ExposureState::NORMAL;

    return result;
}

// ---------------------------------------------------------------------------
// apply_gamma
// ---------------------------------------------------------------------------

cv::Mat apply_gamma(const cv::Mat& input, double gamma)
{
    if (input.empty() || gamma <= 0.0 || std::abs(gamma - 1.0) < 1e-9)
        return input.clone();

    cv::Mat lut(1, 256, CV_8U);
    for (int i = 0; i < 256; ++i) {
        lut.at<uchar>(i) = cv::saturate_cast<uchar>(
            std::pow(i / 255.0, 1.0 / gamma) * 255.0
        );
    }

    cv::Mat output;
    cv::LUT(input, lut, output);
    return output;
}

// ---------------------------------------------------------------------------
// enhance_for_video_view
// ---------------------------------------------------------------------------

cv::Mat enhance_for_video_view(const cv::Mat& frame, const VideoViewEnhancementSettings& settings)
{
    if (frame.empty()) return frame.clone();

    cv::Mat enhanced;
    frame.convertTo(enhanced, -1, settings.contrast_alpha, settings.brightness_beta);

    if (settings.use_clahe) {
        auto clahe = cv::createCLAHE(settings.clahe_clip_limit, settings.clahe_tile_grid);
        if (enhanced.channels() == 3)
            enhanced = detail::apply_clahe_to_luminance(enhanced, settings.clahe_clip_limit, settings.clahe_tile_grid);
        else
            clahe->apply(enhanced, enhanced);
    }

    enhanced = apply_gamma(enhanced, settings.gamma);

    if (settings.use_unsharp_mask && settings.unsharp_kernel_size > 1) {
        int k = settings.unsharp_kernel_size | 1; // force odd
        cv::Mat blurred;
        cv::GaussianBlur(enhanced, blurred, cv::Size(k, k), 0.0);
        cv::addWeighted(enhanced, 1.0 + settings.unsharp_amount,
                        blurred, -settings.unsharp_amount, 0.0, enhanced);
    }

    return enhanced;
}

// ---------------------------------------------------------------------------
// white_balance_gray_world
// ---------------------------------------------------------------------------

cv::Mat white_balance_gray_world(const cv::Mat& frame)
{
    if (frame.empty() || frame.channels() != 3) return frame.clone();

    cv::Mat float_img;
    frame.convertTo(float_img, CV_32F);

    std::vector<cv::Mat> channels;
    cv::split(float_img, channels);

    const double mean_b = cv::mean(channels[0])[0];
    const double mean_g = cv::mean(channels[1])[0];
    const double mean_r = cv::mean(channels[2])[0];
    const double overall_mean = (mean_b + mean_g + mean_r) / 3.0;

    if (mean_b > 1e-9) channels[0] *= (overall_mean / mean_b);
    if (mean_g > 1e-9) channels[1] *= (overall_mean / mean_g);
    if (mean_r > 1e-9) channels[2] *= (overall_mean / mean_r);

    cv::Mat result;
    cv::merge(channels, result);
    result.convertTo(result, CV_8U);
    return result;
}

// ---------------------------------------------------------------------------
// denoise_bilateral
// ---------------------------------------------------------------------------

cv::Mat denoise_bilateral(const cv::Mat& frame, int diameter, double sigma_color, double sigma_space)
{
    if (frame.empty()) return frame.clone();

    cv::Mat result;
    cv::bilateralFilter(frame, result, diameter, sigma_color, sigma_space);
    return result;
}

// ---------------------------------------------------------------------------
// dehaze  (Dark Channel Prior, simplified)
// ---------------------------------------------------------------------------

cv::Mat dehaze(const cv::Mat& frame, int patch_size, double omega)
{
    if (frame.empty() || frame.channels() != 3) return frame.clone();

    // Ensure patch is odd
    if (patch_size % 2 == 0) ++patch_size;

    cv::Mat float_img;
    frame.convertTo(float_img, CV_32F, 1.0 / 255.0);

    // --- Dark channel ---
    std::vector<cv::Mat> channels;
    cv::split(float_img, channels);

    cv::Mat dark_channel(float_img.size(), CV_32F);
    for (int y = 0; y < float_img.rows; ++y)
        for (int x = 0; x < float_img.cols; ++x)
            dark_channel.at<float>(y, x) = std::min({
                channels[0].at<float>(y, x),
                channels[1].at<float>(y, x),
                channels[2].at<float>(y, x)
            });

    cv::Mat dark_eroded;
    cv::Mat kernel = cv::getStructuringElement(
        cv::MORPH_RECT, cv::Size(patch_size, patch_size));
    cv::erode(dark_channel, dark_eroded, kernel);

    // --- Atmospheric light: top-0.1 % brightest dark-channel pixels ---
    cv::Mat flat = dark_eroded.reshape(1, 1);
    cv::Mat sorted_flat;
    cv::sort(flat, sorted_flat, cv::SORT_ASCENDING);
    const int top_idx = std::max(0, sorted_flat.cols - std::max(1, sorted_flat.cols / 1000));
    const float atm = sorted_flat.at<float>(top_idx);
    const double A  = std::max(static_cast<double>(atm), 0.1);

    // --- Transmission map ---
    cv::Mat transmission = 1.0 - omega * dark_eroded / A;
    cv::Mat trans_refined;
    cv::GaussianBlur(transmission, trans_refined, cv::Size(41, 41), 0.0);

    // --- Recover scene radiance ---
    const double t_min = 0.1;
    std::vector<cv::Mat> out_channels(3);
    for (int c = 0; c < 3; ++c) {
        out_channels[c] = cv::Mat(float_img.size(), CV_32F);
        for (int y = 0; y < float_img.rows; ++y) {
            for (int x = 0; x < float_img.cols; ++x) {
                const float t = std::max(static_cast<float>(t_min), trans_refined.at<float>(y, x));
                const float Ic = channels[c].at<float>(y, x);
                out_channels[c].at<float>(y, x) = (Ic - static_cast<float>(A)) / t + static_cast<float>(A);
            }
        }
    }

    cv::Mat result_f;
    cv::merge(out_channels, result_f);
    cv::normalize(result_f, result_f, 0.0, 1.0, cv::NORM_MINMAX);

    cv::Mat result;
    result_f.convertTo(result, CV_8U, 255.0);
    return result;
}

// ---------------------------------------------------------------------------
// adaptive_auto_brightness
// ---------------------------------------------------------------------------

cv::Mat adaptive_auto_brightness(const cv::Mat& frame, double target_luminance, double max_alpha)
{
    if (frame.empty()) return frame.clone();

    const BrightnessAnalysis ba = analyze_brightness(frame);
    if (ba.mean_luminance < 1.0) return frame.clone();

    double alpha = target_luminance / ba.mean_luminance;
    alpha = std::clamp(alpha, 0.5, max_alpha);

    const double beta = 0.0; // avoid brightness shift artefact; alpha does the job
    cv::Mat result;
    frame.convertTo(result, -1, alpha, beta);
    return result;
}

// ---------------------------------------------------------------------------
// sharpen_laplacian
// ---------------------------------------------------------------------------

cv::Mat sharpen_laplacian(const cv::Mat& frame, double strength)
{
    if (frame.empty()) return frame.clone();

    cv::Mat gray, lap;
    gray = detail::to_gray(frame);
    cv::Laplacian(gray, lap, CV_16S, 3);

    cv::Mat lap_abs;
    cv::convertScaleAbs(lap, lap_abs);

    if (frame.channels() == 1) {
        cv::Mat lap_f, frame_f, result_f;
        lap_abs.convertTo(lap_f, CV_32F);
        frame.convertTo(frame_f, CV_32F);
        result_f = frame_f + strength * lap_f;
        cv::Mat result;
        result_f.convertTo(result, CV_8U);
        return result;
    }

    // BGR: apply sharpening in luminance channel only
    cv::Mat lab;
    cv::cvtColor(frame, lab, cv::COLOR_BGR2Lab);
    std::vector<cv::Mat> ch;
    cv::split(lab, ch);

    cv::Mat L_f, lap_f;
    ch[0].convertTo(L_f, CV_32F);
    lap_abs.convertTo(lap_f, CV_32F);
    L_f = L_f + strength * lap_f;
    L_f.convertTo(ch[0], CV_8U);

    cv::merge(ch, lab);
    cv::Mat result;
    cv::cvtColor(lab, result, cv::COLOR_Lab2BGR);
    return result;
}

// ---------------------------------------------------------------------------
// night_mode_enhance
// ---------------------------------------------------------------------------

cv::Mat night_mode_enhance(const cv::Mat& frame, double gamma_lift, double clahe_clip, cv::Size tile_grid)
{
    if (frame.empty()) return frame.clone();

    // 1. Edge-preserving denoise (light params to stay real-time)
    cv::Mat denoised;
    cv::bilateralFilter(frame, denoised, 7, 50.0, 50.0);

    // 2. CLAHE on luminance
    cv::Mat enhanced;
    if (denoised.channels() == 3)
        enhanced = detail::apply_clahe_to_luminance(denoised, clahe_clip, tile_grid);
    else {
        auto clahe = cv::createCLAHE(clahe_clip, tile_grid);
        clahe->apply(denoised, enhanced);
    }

    // 3. Gamma lift to brighten shadows
    return apply_gamma(enhanced, gamma_lift);
}

// ---------------------------------------------------------------------------
// reduce_glare
// ---------------------------------------------------------------------------

cv::Mat reduce_glare(const cv::Mat& frame, uchar highlight_threshold, double compression_factor)
{
    if (frame.empty()) return frame.clone();

    // Build per-pixel LUT: pixels <= threshold are untouched;
    // pixels above threshold are compressed towards threshold.
    cv::Mat lut(1, 256, CV_8U);
    for (int i = 0; i < 256; ++i) {
        if (i <= highlight_threshold) {
            lut.at<uchar>(i) = static_cast<uchar>(i);
        } else {
            const double excess = i - highlight_threshold;
            const double compressed = highlight_threshold + excess * (1.0 - compression_factor);
            lut.at<uchar>(i) = cv::saturate_cast<uchar>(compressed);
        }
    }

    cv::Mat result;
    cv::LUT(frame, lut, result);
    return result;
}

} // namespace image_enhancement

