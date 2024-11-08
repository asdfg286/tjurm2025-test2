#include "impls.h"
void findInnerContours(int idx, const std::vector<std::vector<cv::Point>>& contours, const std::vector<cv::Vec4i>& hierarchy, std::vector<std::vector<cv::Point>>& innerContours){
        if (idx < 0) return;
        if (hierarchy[idx][2] == -1) { // 没有子轮廓，说明是最内层轮廓
            double area = cv::contourArea(contours[idx]);
            if (area > 10) {
                innerContours.push_back(contours[idx]);
            }
        }
        // 递归查找下一个同级轮廓
        findInnerContours(hierarchy[idx][0], contours, hierarchy, innerContours);
        // 递归查找子轮廓
        findInnerContours(hierarchy[idx][2], contours, hierarchy, innerContours);
    };

std::vector<std::vector<cv::Point>> find_contours(const cv::Mat& input) {
    /**
     * 要求：
     * 使用cv::findContours函数，从输入图像（3个通道）中找出所有的最内层轮廓。
     * 将它们保存起来作为函数返回值就行。contours的中文意思就是轮廓。
     * 
     * 提示：
     * 1. 使用cv::imshow来查看输入图像。
     * 2. 使用cv::drawContours来在一张图上绘制轮廓。
     * 3. 直接使用原图一般而言不利于轮廓的寻找，可以做一些简单的处理。
     * 4. findContours函数可以返回轮廓的层次结构，理解层次结构的保存方式并使用它（重点）。
     * 
     * 通过条件：
     * 运行测试点，你找到的轮廓与答案的轮廓一样就行。
     */
    
    std::vector<std::vector<cv::Point>> res;
    // IMPLEMENT YOUR CODE HERE
    cv::Mat gray;
    cv::cvtColor(input, gray, cv::COLOR_BGR2GRAY);
    cv::GaussianBlur(gray, gray, cv::Size(5, 5), 0);

    cv::Mat binary;
    cv::threshold(gray, binary, 100, 255, cv::THRESH_BINARY);
    std::vector<cv::Vec4i> hierarchy;
    cv::findContours(binary, res, hierarchy, cv::RETR_TREE, cv::CHAIN_APPROX_SIMPLE);

    

    
    std::vector<std::vector<cv::Point>> innerContours;


    for (int i = 0; i < hierarchy.size(); i++) {
        if (hierarchy[i][3] == -1) { // 最外层轮廓
            findInnerContours(i, res, hierarchy, innerContours);
        }
    }

    
    cv::waitKey(0);
  

    return innerContours;
}