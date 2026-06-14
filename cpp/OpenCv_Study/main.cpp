#include <iostream>
#include <opencv2/opencv.hpp>

int main()
{
    cv::VideoCapture cap(0);

    if (!cap.isOpened()) {
        std::cerr << "Unable to open camera\n";
        return -1;
    }

    int width = static_cast<int>(cap.get(cv::CAP_PROP_FRAME_WIDTH));
    int height = static_cast<int>(cap.get(cv::CAP_PROP_FRAME_HEIGHT));

    std::cout << "Camera resolution: " << width << "x" << height << '\n';

    cv::Mat frame;
    cv::Mat img_gray;

    while (true) {
        cap >> frame;

        if (frame.empty()) {
            std::cerr << "Empty frame received\n";
            break;
        }

        cv::cvtColor(frame, img_gray, cv::COLOR_BGR2GRAY);

        cv::imshow("Gray Camera", img_gray);

        if ((cv::waitKey(1) & 0xFF) == 'q') {
            break;
        }
    }

    cap.release();
    cv::destroyAllWindows();

    return 0;
}