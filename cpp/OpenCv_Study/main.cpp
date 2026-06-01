#include <iostream>
#include <filesystem>
#include <opencv2/opencv.hpp>

int main() {
    std::cout << "Working directory: "
              << std::filesystem::current_path()
              << "\n";

    cv::Mat image = cv::imread("../images/dog.jpg");


    if (image.empty()) {
        std::cout << "Cannot open/read dog.jpg\n";
        return -1;
    }

    cv::imshow("image", image);
    cv::waitKey(0);

    cv::resize(image, image, cv::Size(1000, 400));
    cv::cvtColor(image, image, cv::COLOR_BGR2RGB);

    cv::imshow("image", image);
    cv::waitKey(0);

    cv::flip(image, image, 0);

    cv::imshow("image", image);
    cv::waitKey(0);

    return 0;
}