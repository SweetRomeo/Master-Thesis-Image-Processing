#pragma once

#include <opencv2/opencv.hpp>

namespace image_enhancement {

// ---------------------------------------------------------------------------
// Settings
// ---------------------------------------------------------------------------

struct VideoViewEnhancementSettings {
    double contrast_alpha = 1.15;
    int brightness_beta = 8;
    double gamma = 1.0;
    bool use_clahe = true;
    double clahe_clip_limit = 2.0;
    cv::Size clahe_tile_grid = cv::Size(8, 8);
    bool use_unsharp_mask = true;
    double unsharp_amount = 0.6;
    int unsharp_kernel_size = 5;
};

// ---------------------------------------------------------------------------
// Brightness analysis
// ---------------------------------------------------------------------------

enum class ExposureState { NORMAL, UNDEREXPOSED, OVEREXPOSED };

struct BrightnessAnalysis {
    double mean_luminance      = 0.0;  // 0-255
    double std_dev             = 0.0;  // contrast spread
    double dark_pixel_ratio    = 0.0;  // fraction of pixels below dark_threshold
    double bright_pixel_ratio  = 0.0;  // fraction of pixels above bright_threshold
    ExposureState exposure     = ExposureState::NORMAL;
};

BrightnessAnalysis analyze_brightness(
    const cv::Mat& frame,
    uchar dark_threshold  = 50,
    uchar bright_threshold = 200
);

// ---------------------------------------------------------------------------
// Core pipeline
// ---------------------------------------------------------------------------

cv::Mat apply_gamma(const cv::Mat& input, double gamma);

cv::Mat enhance_for_video_view(
    const cv::Mat& frame,
    const VideoViewEnhancementSettings& settings = VideoViewEnhancementSettings{}
);

// ---------------------------------------------------------------------------
// Autonomous-driving enhancement methods
// ---------------------------------------------------------------------------

/** Gray-World white balance — corrects color casts from tunnel/sodium lights. */
cv::Mat white_balance_gray_world(const cv::Mat& frame);

/**
 * Edge-preserving bilateral denoise.
 * @param diameter  Pixel neighbourhood diameter (e.g. 9 for real-time).
 * @param sigma_color  Filter sigma in colour space.
 * @param sigma_space  Filter sigma in coordinate space.
 */
cv::Mat denoise_bilateral(
    const cv::Mat& frame,
    int    diameter    = 9,
    double sigma_color = 75.0,
    double sigma_space = 75.0
);

/**
 * Dark-Channel-Prior-based dehazing for fog/rain/dust conditions.
 * @param patch_size  Dark channel patch size (odd, >= 3).
 * @param omega       Haze removal strength [0.0 – 1.0].
 */
cv::Mat dehaze(
    const cv::Mat& frame,
    int    patch_size = 15,
    double omega      = 0.95
);

/**
 * Adaptive auto-brightness: analyses current scene and applies the
 * minimum correction needed to reach target luminance.
 * @param target_luminance  Desired mean luminance (0-255).
 * @param max_alpha         Maximum contrast stretch multiplier.
 */
cv::Mat adaptive_auto_brightness(
    const cv::Mat& frame,
    double target_luminance = 128.0,
    double max_alpha        = 2.0
);

/**
 * Laplacian sharpening — enhances lane markings and road edges.
 * @param strength  How much of the Laplacian edge map to add back [0.0-1.0].
 */
cv::Mat sharpen_laplacian(const cv::Mat& frame, double strength = 0.7);

/**
 * Night-mode pipeline: bilateral denoise → CLAHE → gamma lift.
 * Designed for sub-50 mean luminance scenes.
 * @param gamma_lift  Gamma value > 1 to brighten (e.g. 2.2).
 */
cv::Mat night_mode_enhance(
    const cv::Mat& frame,
    double gamma_lift      = 2.2,
    double clahe_clip      = 3.0,
    cv::Size tile_grid     = cv::Size(8, 8)
);

/**
 * Highlight / glare reducer — compresses blown pixels from headlights and sun
 * without affecting the mid-tones.
 * @param highlight_threshold  Pixels above this are compressed (0-255).
 * @param compression_factor   How strongly to pull highlights down [0.0-1.0].
 */
cv::Mat reduce_glare(
    const cv::Mat& frame,
    uchar  highlight_threshold  = 220,
    double compression_factor   = 0.5
);

} // namespace image_enhancement
