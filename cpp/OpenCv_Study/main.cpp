#include <iostream>
#include <opencv2/opencv.hpp>

int main() {
    cv::Mat img_bgr = cv::imread("./images/dog.jpg");
    if (img_bgr.empty()) {
        std::cout << "Image could not be loaded.\n";
        return -1;
    }
    cv::Mat img_rgb;
    cv::Mat img_gray;
    cv::Mat img_hsv;
    cv::cvtColor(img_bgr, img_rgb, cv::COLOR_BGR2RGB);
    cv::cvtColor(img_bgr, img_gray, cv::COLOR_BGR2GRAY);
    cv::cvtColor(img_bgr, img_hsv, cv::COLOR_BGR2HSV);
    cv::imshow("Original BGR Image", img_bgr);
    cv::imshow("Grayscale Image", img_gray);
    cv::imshow("HSV Image", img_hsv);
    cv::waitKey(0);
    return 0;
}