#include <iostream>
#include <opencv2/opencv.hpp>

int main()
{
    cv::Mat img = cv::imread("./images/dog_backpack.jpg");

    if (img.empty()) {
        std::cout << "Image could not be loaded.\n";
        return -1;
    }

    cv::Mat gray;
    cv::cvtColor(img, gray, cv::COLOR_BGR2GRAY);

    cv::Mat thresholded;

    double used_threshold = cv::threshold(
        gray,
        thresholded,
        127,
        255,
        cv::THRESH_BINARY
    );

    std::cout << "Used threshold value: " << used_threshold << '\n';

    cv::imshow("Original Image", img);
    cv::imshow("Grayscale Image", gray);
    cv::imshow("Thresholded Image", thresholded);

    cv::waitKey(0);

    return 0;
}