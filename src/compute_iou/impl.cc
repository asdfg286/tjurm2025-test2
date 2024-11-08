#include "impls.h"
#include <algorithm>

float compute_iou(const cv::Rect& a, const cv::Rect& b) {
    /**
     * 要求：
     *      有一个重要的指标叫做“交并比”，简称“IOU”，可以用于衡量
     * 两个矩形的重合程度，本练习要求自行学习交并比的计算方式，计算输入
     * 的两个矩形的交并比。
     * 
     * 提示：
     * (1) 注意OpenCV中规定的xy坐标系方向跟平常的xy坐标系不一样。
     * (2) 注意矩形的x, y, width, height四个属性在坐标系内的含义。
     * (3) 注意分母不要除以0（不过我们不会测试这一点）
     * 
     * 通过条件：
     * 运行测试点，显示通过就行，不通过会告诉你哪一组矩形错了。
    */
    // IMPLEMENT YOUR CODE HERE

      // 计算交集的坐标
    int x1 = std::max(a.x, b.x);
    int y1 = std::max(a.y, b.y);
    int x2 = std::min(a.x + a.width, b.x + b.width);
    int y2 = std::min(a.y + a.height, b.y + b.height);

    // 计算交集的宽度和高度
    int intersectionWidth = std::max(0, x2 - x1);
    int intersectionHeight = std::max(0, y2 - y1);

    // 如果有交集，计算面积
    double intersectionArea = intersectionWidth * intersectionHeight;
    

    // 计算两个矩形的面积
    double area1 = a.width * a.height;
    double area2 = b.width * b.height;

    // 计算并集面积
    double unionArea = area1 + area2 - intersectionArea;

    // 计算IoU
    if (unionArea == 0) {
        return 0.f; // 避免除以0
    } else {
        return static_cast<float>(intersectionArea / unionArea);
    }
    return 0.f;
}