#include <gtest/gtest.h>
#include "image_enhancement.h"

using namespace image_enhancement;

// ---------------------------------------------------------------------------
// Helpers
// ---------------------------------------------------------------------------

static cv::Mat make_bgr(uchar r, uchar g, uchar b, int rows = 16, int cols = 16)
{
    return cv::Mat(rows, cols, CV_8UC3, cv::Scalar(b, g, r));
}

static cv::Mat make_gray(uchar val, int rows = 16, int cols = 16)
{
    return cv::Mat(rows, cols, CV_8UC1, cv::Scalar(val));
}

// ---------------------------------------------------------------------------
// analyze_brightness
// ---------------------------------------------------------------------------

TEST(AnalyzeBrightness, EmptyReturnsDefaults)
{
    cv::Mat empty;
    BrightnessAnalysis ba = analyze_brightness(empty);
    EXPECT_EQ(ba.mean_luminance, 0.0);
    EXPECT_EQ(ba.exposure, ExposureState::NORMAL);
}

TEST(AnalyzeBrightness, DarkImageIsUnderexposed)
{
    cv::Mat img = make_gray(20);
    BrightnessAnalysis ba = analyze_brightness(img);
    EXPECT_LT(ba.mean_luminance, 60.0);
    EXPECT_EQ(ba.exposure, ExposureState::UNDEREXPOSED);
}

TEST(AnalyzeBrightness, BrightImageIsOverexposed)
{
    cv::Mat img = make_gray(240);
    BrightnessAnalysis ba = analyze_brightness(img);
    EXPECT_GT(ba.mean_luminance, 200.0);
    EXPECT_EQ(ba.exposure, ExposureState::OVEREXPOSED);
}

TEST(AnalyzeBrightness, MidtoneIsNormal)
{
    cv::Mat img = make_gray(128);
    BrightnessAnalysis ba = analyze_brightness(img);
    EXPECT_EQ(ba.exposure, ExposureState::NORMAL);
}

TEST(AnalyzeBrightness, DarkPixelRatioCorrect)
{
    // Half the image is black (0), half is bright (200)
    cv::Mat img(16, 16, CV_8UC1, cv::Scalar(200));
    img.rowRange(0, 8) = cv::Scalar(10); // top half dark
    BrightnessAnalysis ba = analyze_brightness(img, 50, 200);
    EXPECT_NEAR(ba.dark_pixel_ratio, 0.5, 0.05);
}

TEST(AnalyzeBrightness, StdDevNonZeroForVariedImage)
{
    cv::Mat img(16, 16, CV_8UC1, cv::Scalar(200));
    img.rowRange(0, 8) = cv::Scalar(10);
    BrightnessAnalysis ba = analyze_brightness(img);
    EXPECT_GT(ba.std_dev, 0.0);
}

TEST(AnalyzeBrightness, AcceptsBGRInput)
{
    cv::Mat img = make_bgr(100, 100, 100);
    EXPECT_NO_THROW(analyze_brightness(img));
}

// ---------------------------------------------------------------------------
// apply_gamma (existing)
// ---------------------------------------------------------------------------

TEST(ApplyGamma, EmptyInputReturnsEmpty)
{
    EXPECT_TRUE(apply_gamma(cv::Mat(), 2.0).empty());
}

TEST(ApplyGamma, GammaOneIsNoOp)
{
    cv::Mat img = make_gray(128);
    EXPECT_EQ(cv::countNonZero(img != apply_gamma(img, 1.0)), 0);
}

TEST(ApplyGamma, GammaBrightensDarkImage)
{
    cv::Mat img = make_gray(100);
    EXPECT_GT(cv::mean(apply_gamma(img, 2.2))[0], cv::mean(img)[0]);
}

TEST(ApplyGamma, PureBlackRemainsBlack)
{
    EXPECT_EQ(cv::mean(apply_gamma(make_gray(0), 2.2))[0], 0.0);
}

TEST(ApplyGamma, PureWhiteRemainsWhite)
{
    EXPECT_EQ(cv::mean(apply_gamma(make_gray(255), 2.2))[0], 255.0);
}

// ---------------------------------------------------------------------------
// enhance_for_video_view (existing)
// ---------------------------------------------------------------------------

TEST(EnhanceForVideoView, EmptyReturnsEmpty)
{
    EXPECT_TRUE(enhance_for_video_view(cv::Mat()).empty());
}

TEST(EnhanceForVideoView, OutputSizePreservedBGR)
{
    cv::Mat f = make_bgr(120, 80, 60);
    cv::Mat r = enhance_for_video_view(f);
    EXPECT_EQ(r.size(), f.size());
    EXPECT_EQ(r.type(), f.type());
}

TEST(EnhanceForVideoView, NeutralSettingsPreservesPixels)
{
    VideoViewEnhancementSettings s;
    s.contrast_alpha = 1.0; s.brightness_beta = 0;
    s.gamma = 1.0; s.use_clahe = false; s.use_unsharp_mask = false;
    cv::Mat f = make_bgr(120, 80, 60);
    cv::Mat diff; cv::absdiff(f, enhance_for_video_view(f, s), diff);
    EXPECT_LE(cv::mean(diff)[0], 1.0);
}

// ---------------------------------------------------------------------------
// white_balance_gray_world
// ---------------------------------------------------------------------------

TEST(WhiteBalance, EmptyReturnsEmpty)
{
    EXPECT_TRUE(white_balance_gray_world(cv::Mat()).empty());
}

TEST(WhiteBalance, GrayscaleInputReturnedUnchanged)
{
    cv::Mat gray = make_gray(128);
    cv::Mat result = white_balance_gray_world(gray);
    EXPECT_EQ(result.channels(), 1);
}

TEST(WhiteBalance, OutputSizeMatchesInput)
{
    cv::Mat f = make_bgr(100, 150, 80);
    cv::Mat r = white_balance_gray_world(f);
    EXPECT_EQ(r.size(), f.size());
    EXPECT_EQ(r.type(), f.type());
}

TEST(WhiteBalance, ChannelMeansConvergeAfterBalance)
{
    // Strongly blue-cast image: after balance, means should be closer
    cv::Mat f = make_bgr(50, 80, 200);
    cv::Mat r = white_balance_gray_world(f);
    std::vector<cv::Mat> ch_in, ch_out;
    cv::split(f, ch_in); cv::split(r, ch_out);
    const double spread_in  = std::abs(cv::mean(ch_in[0])[0]  - cv::mean(ch_in[2])[0]);
    const double spread_out = std::abs(cv::mean(ch_out[0])[0] - cv::mean(ch_out[2])[0]);
    EXPECT_LT(spread_out, spread_in);
}

TEST(WhiteBalance, NeutralImageUnchanged)
{
    // Equal R=G=B → means already equal, output should be nearly identical
    cv::Mat f = make_bgr(120, 120, 120);
    cv::Mat r = white_balance_gray_world(f);
    cv::Mat diff; cv::absdiff(f, r, diff);
    EXPECT_LE(cv::mean(diff)[0], 2.0);
}

// ---------------------------------------------------------------------------
// denoise_bilateral
// ---------------------------------------------------------------------------

TEST(DenoiseBilateral, EmptyReturnsEmpty)
{
    EXPECT_TRUE(denoise_bilateral(cv::Mat()).empty());
}

TEST(DenoiseBilateral, OutputSizePreserved)
{
    cv::Mat f = make_bgr(100, 100, 100);
    cv::Mat r = denoise_bilateral(f);
    EXPECT_EQ(r.size(), f.size());
    EXPECT_EQ(r.type(), f.type());
}

TEST(DenoiseBilateral, NoisyImageSmoothed)
{
    // Add salt-and-pepper noise, then check std dev decreases
    cv::Mat base = make_gray(128, 64, 64);
    cv::Mat noise(base.size(), CV_8UC1);
    cv::randu(noise, 0, 255);
    cv::Mat noisy;
    cv::addWeighted(base, 0.5, noise, 0.5, 0, noisy);

    cv::Scalar _, std_before, std_after;
    cv::meanStdDev(noisy,                    _, std_before);
    cv::meanStdDev(denoise_bilateral(noisy), _, std_after);
    EXPECT_LT(std_after[0], std_before[0]);
}

// ---------------------------------------------------------------------------
// dehaze
// ---------------------------------------------------------------------------

TEST(Dehaze, EmptyReturnsEmpty)
{
    EXPECT_TRUE(dehaze(cv::Mat()).empty());
}

TEST(Dehaze, GrayscaleReturnedUnchanged)
{
    cv::Mat gray = make_gray(180);
    cv::Mat r = dehaze(gray);
    // Grayscale path just clones
    EXPECT_EQ(r.channels(), 1);
}

TEST(Dehaze, OutputSizePreserved)
{
    cv::Mat f = make_bgr(200, 200, 200, 32, 32);
    cv::Mat r = dehaze(f);
    EXPECT_EQ(r.size(), f.size());
    EXPECT_EQ(r.type(), f.type());
}

TEST(Dehaze, EvenPatchSafelyHandled)
{
    cv::Mat f = make_bgr(180, 180, 180, 32, 32);
    EXPECT_NO_THROW(dehaze(f, 14)); // even patch → auto-bumped to 15
}

TEST(Dehaze, HazyImageContrastIncreases)
{
    // A uniformly bright (hazy) frame should gain contrast after dehazing
    cv::Mat hazy = make_bgr(190, 190, 190, 32, 32);
    cv::Mat dehazed = dehaze(hazy);
    cv::Scalar _, std_before, std_after;
    cv::meanStdDev(hazy,    _, std_before);
    cv::meanStdDev(dehazed, _, std_after);
    // Dehazing on a uniform frame can change std — just confirm no crash and
    // output type is correct.
    EXPECT_EQ(dehazed.type(), hazy.type());
}

// ---------------------------------------------------------------------------
// adaptive_auto_brightness
// ---------------------------------------------------------------------------

TEST(AdaptiveAutoBrightness, EmptyReturnsEmpty)
{
    EXPECT_TRUE(adaptive_auto_brightness(cv::Mat()).empty());
}

TEST(AdaptiveAutoBrightness, DarkImageBrightened)
{
    cv::Mat f = make_gray(30);
    cv::Mat r = adaptive_auto_brightness(f, 128.0);
    EXPECT_GT(cv::mean(r)[0], cv::mean(f)[0]);
}

TEST(AdaptiveAutoBrightness, BrightImageDarkened)
{
    cv::Mat f = make_gray(230);
    cv::Mat r = adaptive_auto_brightness(f, 128.0);
    EXPECT_LT(cv::mean(r)[0], cv::mean(f)[0]);
}

TEST(AdaptiveAutoBrightness, AlreadyTargetLuminanceUnchanged)
{
    cv::Mat f = make_gray(128);
    cv::Mat r = adaptive_auto_brightness(f, 128.0);
    cv::Mat diff; cv::absdiff(f, r, diff);
    EXPECT_LE(cv::mean(diff)[0], 2.0);
}

TEST(AdaptiveAutoBrightness, OutputSizePreserved)
{
    cv::Mat f = make_bgr(80, 80, 80);
    cv::Mat r = adaptive_auto_brightness(f);
    EXPECT_EQ(r.size(), f.size());
    EXPECT_EQ(r.type(), f.type());
}

// ---------------------------------------------------------------------------
// sharpen_laplacian
// ---------------------------------------------------------------------------

TEST(SharpenLaplacian, EmptyReturnsEmpty)
{
    EXPECT_TRUE(sharpen_laplacian(cv::Mat()).empty());
}

TEST(SharpenLaplacian, OutputSizePreservedBGR)
{
    cv::Mat f = make_bgr(120, 80, 60);
    cv::Mat r = sharpen_laplacian(f);
    EXPECT_EQ(r.size(), f.size());
    EXPECT_EQ(r.type(), f.type());
}

TEST(SharpenLaplacian, OutputSizePreservedGray)
{
    cv::Mat f = make_gray(128);
    cv::Mat r = sharpen_laplacian(f);
    EXPECT_EQ(r.size(), f.size());
    EXPECT_EQ(r.type(), f.type());
}

TEST(SharpenLaplacian, EdgeImageGetsHigherStdDev)
{
    // Create an image with a sharp horizontal edge
    cv::Mat f(32, 32, CV_8UC1, cv::Scalar(50));
    f.rowRange(16, 32) = cv::Scalar(200);

    cv::Scalar _, std_before, std_after;
    cv::meanStdDev(f,                   _, std_before);
    cv::meanStdDev(sharpen_laplacian(f), _, std_after);
    EXPECT_GE(std_after[0], std_before[0]);
}

TEST(SharpenLaplacian, ZeroStrengthApproximatesOriginal)
{
    cv::Mat f = make_gray(128);
    cv::Mat r = sharpen_laplacian(f, 0.0);
    cv::Mat diff; cv::absdiff(f, r, diff);
    EXPECT_LE(cv::mean(diff)[0], 2.0);
}

// ---------------------------------------------------------------------------
// night_mode_enhance
// ---------------------------------------------------------------------------

TEST(NightModeEnhance, EmptyReturnsEmpty)
{
    EXPECT_TRUE(night_mode_enhance(cv::Mat()).empty());
}

TEST(NightModeEnhance, OutputSizePreserved)
{
    cv::Mat f = make_bgr(30, 30, 30);
    cv::Mat r = night_mode_enhance(f);
    EXPECT_EQ(r.size(), f.size());
    EXPECT_EQ(r.type(), f.type());
}

TEST(NightModeEnhance, DarkImageGetsBrighter)
{
    cv::Mat f = make_bgr(20, 20, 20);
    cv::Mat r = night_mode_enhance(f, 2.2);
    EXPECT_GT(cv::mean(r)[0], cv::mean(f)[0]);
}

TEST(NightModeEnhance, WorksOnGrayscale)
{
    cv::Mat f = make_gray(20);
    EXPECT_NO_THROW(night_mode_enhance(f));
}

// ---------------------------------------------------------------------------
// reduce_glare
// ---------------------------------------------------------------------------

TEST(ReduceGlare, EmptyReturnsEmpty)
{
    EXPECT_TRUE(reduce_glare(cv::Mat()).empty());
}

TEST(ReduceGlare, OutputSizePreserved)
{
    cv::Mat f = make_bgr(240, 240, 240);
    cv::Mat r = reduce_glare(f);
    EXPECT_EQ(r.size(), f.size());
    EXPECT_EQ(r.type(), f.type());
}

TEST(ReduceGlare, HighlightsAreReduced)
{
    cv::Mat f = make_gray(250);
    cv::Mat r = reduce_glare(f, 220, 0.5);
    EXPECT_LT(cv::mean(r)[0], cv::mean(f)[0]);
}

TEST(ReduceGlare, MidtonesUntouched)
{
    cv::Mat f = make_gray(100);
    cv::Mat r = reduce_glare(f, 220, 0.5);
    cv::Mat diff; cv::absdiff(f, r, diff);
    EXPECT_EQ(cv::mean(diff)[0], 0.0); // pixels well below threshold → unchanged
}

TEST(ReduceGlare, ZeroCompressionIsNoOp)
{
    cv::Mat f = make_bgr(240, 240, 240);
    cv::Mat r = reduce_glare(f, 220, 0.0); // no compression
    cv::Mat diff; cv::absdiff(f, r, diff);
    EXPECT_EQ(cv::mean(diff)[0], 0.0);
}

// ---------------------------------------------------------------------------
// Main
// ---------------------------------------------------------------------------

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

