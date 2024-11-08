#include "impls.h"


cv::Mat my_resize(const cv::Mat& input, float scale) {
    /**
     * 要求：
     *      实现resize算法，只能使用基础的语法，比如说for循环，Mat的基本操作。不能
     * 用cv::resize。resize算法的内容自行查找学习，不是很难。
     * 
     * 提示：
     * 无。
     * 
     * 通过条件：
     * 运行测试点，你的结果跟答案长的差不多就行。
     */
    int new_rows = input.rows * scale, new_cols = input.cols * scale;
    // IMPLEMENT YOUR CODE HERE

    // 创建一个新的Mat对象，用于存储缩放后的图像
    cv::Mat output(new_rows, new_cols, input.type());

    // 遍历新的图像尺寸
    for (int i = 0; i < new_rows; ++i) {
        for (int j = 0; j < new_cols; ++j) {
            // 计算最近邻插值的坐标
            int x = static_cast<int>(j / scale);
            int y = static_cast<int>(i / scale);

            // 确保坐标在原始图像的范围内
            if (x >= 0 && x < input.cols && y >= 0 && y < input.rows) {
                // 将最近邻像素值复制到输出图像
                if (input.channels() == 3) { // 彩色图像
                    output.at<cv::Vec3b>(i, j) = input.at<cv::Vec3b>(y, x);
                } else if (input.channels() == 1) { // 灰度图像
                    output.at<uchar>(i, j) = input.at<uchar>(y, x);
                }
            }
        }
    }

    return output;
}