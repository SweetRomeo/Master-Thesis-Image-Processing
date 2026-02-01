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
(Ideally, you can add a brief description here later).

---

## 📊 Performance Benchmarks
Comparison of processing time per frame (1920x1080 resolution) between pure Python implementation and our Hybrid (C++) solution.

| Algorithm | Implementation | Avg. Time (ms) | FPS | Speedup |
|-----------|----------------|----------------|-----|---------|
| Gamma     | Python (NumPy) | 45.2 ms        | 22  | 1x      |
| **Gamma** | **Hybrid C++** | **2.1 ms** | **476** | **21x** |
| CLAHE     | Python (OpenCV)| 60.5 ms        | 16  | 1x      |
| **CLAHE** | **Hybrid C++** | **12.4 ms** | **80** | **5x** |
