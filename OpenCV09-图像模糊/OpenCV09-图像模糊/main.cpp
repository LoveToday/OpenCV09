//
//  main.cpp
//  OpenCV09-图像模糊
//
//  Created by 陈江林 on 2019/9/13.
//  Copyright © 2019 陈江林. All rights reserved.
//

#include <iostream>
#include <opencv2/opencv.hpp>
#include <string>
using namespace std;
using namespace cv;
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    string filePath = "/Users/chenjianglin/Documents/C++/OpenCV09/OpenCV09-图像模糊/OpenCV09-图像模糊/three.jpg";
    Mat input = imread(filePath);
    if (input.empty()) {
        cout << "图片加载失败" << endl;
        return -1;
    }
    namedWindow("input Window");
    imshow("input Window", input);
    // 均值滤波
    Mat blur;
    cv::blur(input, blur, Size(11, 11));
    
    namedWindow("blur Window");
    imshow("blur Window", blur);
    
    
    // 高斯模糊
    Mat gaussian;
    GaussianBlur(input, gaussian, Size(11, 11), 5);
    
    namedWindow("gaussian Window");
    imshow("gaussian Window", gaussian);
    
    // 中值滤波
    Mat median;
    medianBlur(input, median, 7);
    
    namedWindow("median Window");
    imshow("median Window", median);
    
    // 双边滤波
    Mat bilateral;
    bilateralFilter(input, bilateral, 15, 100, 3);
    
    namedWindow("bilateral Window");
    imshow("bilateral Window", bilateral);
    
    /// 双边模糊的基础上加一个对比度的调整
    Mat resultImg;
    Mat kernal = (Mat_<int>(3, 3) << 0, -1, 0, -1, 5, -1, 0, -1, 0);
    filter2D(bilateral, resultImg, bilateral.depth(), kernal);
    
    namedWindow("resultImg Window");
    imshow("resultImg Window", resultImg);
    
    
    waitKey(0);
    return 0;
}
