# Real-Time Low-Light Image Enhancement for Autonomous Driving 🚗🌙

![Language](https://img.shields.io/badge/language-C%2B%2B%20%7C%20Python-blue)
![Platform](https://img.shields.io/badge/platform-Linux%20%7C%20Embedded-lightgrey)
![License](https://img.shields.io/badge/license-MIT-green)

## 📖 Abstract
This project implements and compares various image enhancement algorithms designed to improve the perception capabilities of **autonomous vehicles** in low-light and non-uniform lighting conditions.

# Image Processing Algorithms and their implementations
### 1. Gamma Correction (Power-Law Transformation)
A non-linear operation used to encode and decode luminance or tristimulus values in video or still image systems. It is computationally efficient for real-time applications.

The transformation is defined as:

$$V_{out} = V_{in}^{\gamma}$$

For 8-bit images ($0-255$), the normalized formula used in our C++ kernel is:

$$O(x,y) = 255 \times \left( \frac{I(x,y)}{255} \right)^{\gamma}$$

Where:
* $I(x,y)$: Input pixel intensity.
* $O(x,y)$: Output pixel intensity.
* $\gamma$: Gamma coefficient. For low-light enhancement, we typically use $\gamma < 1$ (e.g., $0.4$).

### 2. CLAHE (Contrast Limited Adaptive Histogram Equalization)
CLAHE improves local contrast by dividing the image into small regions called tiles, applying histogram equalization to each tile independently, and then blending the tile boundaries smoothly. Unlike standard histogram equalization, CLAHE limits the amount of contrast amplification using a clip limit, which helps prevent over-enhancement of noise in dark regions.

It is particularly useful for road scenes captured at night because it can reveal local structures such as lane markings, pedestrians, and obstacles without excessively washing out already bright areas.

Key parameters:
* **Clip limit**: Controls how much the histogram is allowed to grow before redistribution.
* **Tile grid size**: Defines the number and size of local regions.

### 3. Histogram Equalization
Histogram Equalization is a global contrast enhancement method that redistributes the intensity values of the entire image so that the histogram becomes more uniform. This stretches the dynamic range and can make dark regions more visible.

It is simple and fast, but because it works globally, it may over-brighten some areas or amplify noise in low-light images. For autonomous driving, it can serve as a strong baseline but is often less robust than CLAHE in complex scenes with uneven illumination.

Main idea:
* Compute the image histogram.
* Derive the cumulative distribution function (CDF).
* Map old intensities to new ones using the CDF.

### 4. Log Transformation
Log Transformation expands dark pixel values more than bright ones, which makes details in shadows easier to see. It is useful when the image contains many low-intensity pixels and only a few bright pixels.

A common form is:

$$O(x,y) = c \cdot \log(1 + I(x,y))$$

Where:
* $I(x,y)$ is the input intensity.
* $O(x,y)$ is the output intensity.
* $c$ is a scaling constant.

This method enhances visibility in dark regions, but it may reduce contrast in bright areas if not carefully normalized.

### 5. Retinex-Based Enhancement
Retinex algorithms are inspired by human visual perception. They attempt to separate an image into illumination and reflectance components, then normalize the illumination while preserving reflectance details. This helps produce images that look more naturally enhanced under poor lighting.

Popular variants include:
* **Single-Scale Retinex (SSR)**
* **Multi-Scale Retinex (MSR)**
* **MSR with Color Restoration (MSRCR)**

Why it is useful:
* Enhances details in shadows.
* Handles non-uniform illumination well.
* Produces visually natural results in many night-driving scenarios.

Trade-offs:
* More computationally expensive than gamma correction or histogram equalization.
* May introduce halos or color distortion if parameters are not tuned well.

### 6. Unsharp Masking
Unsharp Masking is a sharpening technique that enhances edges and fine details by subtracting a blurred version of the image from the original image. It does not directly brighten dark scenes, but it can significantly improve perceived clarity after brightness enhancement.

Typical workflow:
* Blur the original image.
* Compute the detail mask as the difference between original and blurred image.
* Add a scaled version of this mask back to the original.

This is useful for emphasizing lane edges, signs, and object boundaries after low-light enhancement, but too much sharpening can amplify sensor noise.

### 7. Denoising Filters for Enhancement Pipelines
Low-light enhancement often boosts noise together with useful signal. For this reason, denoising is commonly included as part of the enhancement pipeline.

Common denoising methods include:
* **Gaussian filtering**: Smooths noise, but can blur edges.
* **Median filtering**: Effective for impulse noise while preserving edges better than Gaussian blur.
* **Bilateral filtering**: Reduces noise while preserving strong edges.
* **Non-Local Means (NLM)**: Uses patch similarity for better detail preservation, but is computationally heavier.

These are not brightness enhancement methods by themselves, but they are important supporting algorithms for producing cleaner outputs in real-world night scenes.

### 8. Deep Learning-Based Low-Light Enhancement
Recent approaches use convolutional neural networks or transformer-based models to directly learn enhancement from pairs of low-light and well-exposed images. These models can jointly improve brightness, contrast, color fidelity, and denoise the image.

Examples of learned approaches:
* **Zero-DCE / Zero-DCE++**
* **EnlightenGAN**
* **RetinexNet**
* **LLFormer**

Advantages:
* Often produce the best visual quality.
* Can adapt to complex real-world lighting conditions.
* May jointly solve enhancement and denoising.

Limitations:
* Require training data and GPU resources.
* Harder to deploy on resource-constrained embedded systems.
* Real-time performance may be challenging depending on model size.

### 9. White Balance and Color Correction
Low-light images often suffer not only from poor brightness but also from color casts caused by street lamps, headlights, or camera sensor limitations. White balance and color correction algorithms help restore more realistic colors.

These methods are often combined with brightness enhancement to improve downstream perception tasks such as detection and segmentation.

Examples:
* Gray-world assumption
* Learning-based white balance
* Color constancy correction

---

## ✅ Summary of Algorithm Suitability
For this project, the enhancement methods can be grouped as follows:

* **Fast and lightweight**: Gamma Correction, Histogram Equalization, Log Transformation
* **Better local contrast**: CLAHE
* **Perceptually motivated**: Retinex-based methods
* **Detail enhancement**: Unsharp Masking
* **Support methods**: Denoising filters, White Balance
* **Highest quality but heavier**: Deep learning-based methods

For embedded autonomous driving applications, a practical pipeline often combines:
1. Brightness enhancement (Gamma / CLAHE / Retinex)
2. Noise suppression (Bilateral / NLM / Median)
3. Detail refinement (Unsharp Masking)
4. Optional color correction

---

## 📊 Performance Benchmarks
Comparison of processing time per frame (1920x1080 resolution) between pure Python implementation and our Hybrid (C++) solution.

| Algorithm | Implementation | Avg. Time (ms) | FPS | Speedup |
|-----------|----------------|----------------|-----|---------|
| Gamma     | Python (NumPy) | 45.2 ms        | 22  | 1x      |
| **Gamma** | **Hybrid C++** | **2.1 ms** | **476** | **21x** |
| CLAHE     | Python (OpenCV)| 60.5 ms        | 16  | 1x      |
| **CLAHE** | **Hybrid C++** | **12.4 ms** | **80** | **5x** |
