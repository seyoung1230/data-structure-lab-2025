#include <iostream>
#include <opencv2/opencv.hpp>

int main() {
    cv::Mat img = cv::imread("Lenna.png", cv::IMREAD_GRAYSCALE);

    if (img.empty()) {
        std::cerr << "이미지를 불러올 수 없습니다. 파일 경로를 확인하세요." << std::endl;
        return -1;
    }

    double minVal, maxVal;
    cv::minMaxLoc(img, &minVal, &maxVal);

    std::cout << static_cast<int>(maxVal) << std::endl;

    return 0;
}