#include <iostream>
#include <string>
#include <functional>
#include <vector>
#include <opencv2/opencv.hpp>
#include "image_enhancement.h"

using namespace image_enhancement;

// ---------------------------------------------------------------------------
// Overlay helpers
// ---------------------------------------------------------------------------

static void draw_label(cv::Mat& img, const std::string& text, cv::Point pos,
                       double scale = 0.55, cv::Scalar color = {0, 255, 80},
                       int thickness = 1)
{
    // Dark shadow for readability over any background
    cv::putText(img, text, pos + cv::Point(1, 1),
                cv::FONT_HERSHEY_SIMPLEX, scale, {0, 0, 0}, thickness + 1, cv::LINE_AA);
    cv::putText(img, text, pos,
                cv::FONT_HERSHEY_SIMPLEX, scale, color, thickness, cv::LINE_AA);
}

static std::string exposure_str(ExposureState s)
{
    switch (s) {
        case ExposureState::UNDEREXPOSED: return "UNDER";
        case ExposureState::OVEREXPOSED:  return "OVER";
        default:                          return "NORMAL";
    }
}

static void draw_brightness_overlay(cv::Mat& img, const BrightnessAnalysis& ba)
{
    const cv::Scalar exp_color = (ba.exposure == ExposureState::NORMAL)
        ? cv::Scalar(0, 255, 80)
        : cv::Scalar(0, 80, 255);

    draw_label(img, "Lum: "  + std::to_string(static_cast<int>(ba.mean_luminance)), {8, 20});
    draw_label(img, "Std: "  + std::to_string(static_cast<int>(ba.std_dev)),        {8, 40});
    draw_label(img, "Dark: " + std::to_string(static_cast<int>(ba.dark_pixel_ratio   * 100)) + "%", {8, 60});
    draw_label(img, "Bright:"+ std::to_string(static_cast<int>(ba.bright_pixel_ratio * 100)) + "%", {8, 80});
    draw_label(img, exposure_str(ba.exposure), {8, 102}, 0.65, exp_color, 2);
}

static void draw_mode_bar(cv::Mat& img, const std::string& mode_name)
{
    // Semi-transparent bar at the bottom
    cv::Mat bar = img.rowRange(img.rows - 28, img.rows);
    bar *= 0.4;
    draw_label(img, "MODE: " + mode_name + "  |  [0-8] switch  [q] quit",
               {8, img.rows - 10}, 0.50, {255, 255, 255}, 1);
}

// ---------------------------------------------------------------------------
// Mode registry
// ---------------------------------------------------------------------------

struct Mode {
    std::string name;
    std::function<cv::Mat(const cv::Mat&)> apply;
};

static std::vector<Mode> build_modes()
{
    return {
        {
            "Original (no enhancement)",
            [](const cv::Mat& f) { return f.clone(); }
        },
        {
            "Default pipeline (contrast + CLAHE + unsharp)",
            [](const cv::Mat& f) { return enhance_for_video_view(f); }
        },
        {
            "Gray-World White Balance",
            [](const cv::Mat& f) { return white_balance_gray_world(f); }
        },
        {
            "Bilateral Denoise",
            [](const cv::Mat& f) { return denoise_bilateral(f, 9, 75, 75); }
        },
        {
            "Dehaze (Dark Channel Prior)",
            [](const cv::Mat& f) { return dehaze(f, 15, 0.95); }
        },
        {
            "Adaptive Auto-Brightness",
            [](const cv::Mat& f) { return adaptive_auto_brightness(f, 128.0); }
        },
        {
            "Laplacian Sharpening",
            [](const cv::Mat& f) { return sharpen_laplacian(f, 0.7); }
        },
        {
            "Night Mode (denoise + CLAHE + gamma lift)",
            [](const cv::Mat& f) { return night_mode_enhance(f, 2.2); }
        },
        {
            "Glare / Highlight Reduction",
            [](const cv::Mat& f) { return reduce_glare(f, 220, 0.5); }
        },
    };
}

// ---------------------------------------------------------------------------
// Main
// ---------------------------------------------------------------------------

int main()
{
    cv::VideoCapture cap(0);
    if (!cap.isOpened()) {
        std::cerr << "Unable to open camera\n";
        return -1;
    }

    const int width  = static_cast<int>(cap.get(cv::CAP_PROP_FRAME_WIDTH));
    const int height = static_cast<int>(cap.get(cv::CAP_PROP_FRAME_HEIGHT));
    std::cout << "Camera: " << width << "x" << height << "\n";
    std::cout << "Keys [0-8]: switch mode  |  [q]: quit\n\n";

    const auto modes   = build_modes();
    int current_mode   = 0;

    cv::Mat frame, enhanced;

    while (true) {
        cap >> frame;
        if (frame.empty()) { std::cerr << "Empty frame\n"; break; }

        // --- Apply selected enhancement ---
        try {
            enhanced = modes[current_mode].apply(frame);
        } catch (const cv::Exception& e) {
            std::cerr << "cv::Exception in mode " << current_mode << ": " << e.what() << "\n";
            enhanced = frame.clone();
        }

        // --- Brightness analysis (on original frame) ---
        const BrightnessAnalysis ba = analyze_brightness(frame);

        // --- Build side-by-side view: [Original | Enhanced] ---
        // Ensure both are BGR before concatenating
        cv::Mat left  = frame.clone();
        cv::Mat right = enhanced.clone();
        if (right.channels() != left.channels()) {
            if (right.channels() == 1)
                cv::cvtColor(right, right, cv::COLOR_GRAY2BGR);
        }

        // Divider line
        cv::Mat divider(height, 4, CV_8UC3, cv::Scalar(80, 80, 80));

        cv::Mat side_by_side;
        cv::hconcat(std::vector<cv::Mat>{left, divider, right}, side_by_side);

        // --- Overlays ---
        draw_brightness_overlay(side_by_side, ba);

        // Labels above each panel
        draw_label(side_by_side, "Original",                    {8,           height - 35}, 0.55);
        draw_label(side_by_side, modes[current_mode].name,      {width + 8,   height - 35}, 0.50,
                   {80, 220, 255});

        draw_mode_bar(side_by_side, modes[current_mode].name);

        cv::imshow("Image Enhancement Demo", side_by_side);

        // --- Key handling ---
        const int key = cv::waitKey(1) & 0xFF;
        if (key == 'q' || key == 27 /* ESC */) break;
        if (key >= '0' && key <= '8') {
            current_mode = key - '0';
            std::cout << "Mode " << current_mode << ": " << modes[current_mode].name << "\n";
        }
    }

    cap.release();
    cv::destroyAllWindows();

    return 0;
}