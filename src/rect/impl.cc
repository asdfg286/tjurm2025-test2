#include "impls.h"


std::pair<cv::Rect, cv::RotatedRect> get_rect_by_contours(const cv::Mat& input) {
    /**
     * 要求：
     * 使用findCountours函数找出输入图像（彩色图像）中的矩形轮廓，并且返回它的外接矩形，以及
     * 最小面积外接矩形。所需要的函数自行查找。
     * 
     * 通过条件：
     * 运行测试点，你找到的矩形跟答案一样就行。
    */
    std::pair<cv::Rect, cv::RotatedRect> res;
    // IMPLEMENT YOUR CODE HERE
    cv::Mat gray;
    cv::cvtColor(input, gray, cv::COLOR_BGR2GRAY);
    cv::GaussianBlur(gray, gray, cv::Size(5, 5), 0);

    cv::Mat binary;
    cv::threshold(gray, binary, 100, 255, cv::THRESH_BINARY_INV | cv::THRESH_OTSU);

    std::vector<std::vector<cv::Point>> contours;
    cv::findContours(binary, contours, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);

    for (const auto& contour : contours) {
        cv::Rect boundingRect = cv::boundingRect(contour);
        cv::RotatedRect minAreaRect = cv::minAreaRect(contour);

        // 检查轮廓是否为矩形（这里使用一个简单的方法，即检查矩形的长宽比）
        double aspectRatio = std::max(boundingRect.width, boundingRect.height) / std::min(boundingRect.width, boundingRect.height);
        if (aspectRatio >= 1 && aspectRatio <= 2) { // 调整这个比例以适应矩形的定义
            return {boundingRect, minAreaRect};
        }
    }

    // 如果没有找到矩形，返回空的矩形
    return {cv::Rect(), cv::RotatedRect()};
}