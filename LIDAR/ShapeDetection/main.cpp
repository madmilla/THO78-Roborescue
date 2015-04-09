
// First parameter is .txt file with the pixels.

// compiled with: g++ circles.cpp -o circles `pkg-config --cflags --libs opencv`
#include <iostream>
#include <stdio.h>
#include "time.h"
#include "ctime"
#include <math.h>
#include <fstream>
#include "shapedetector.h"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/opencv.hpp"

void test(){
    ShapeDetector sD;
    clock_t Start = clock();
    const Mat & image = sD.createImage("circles400.txt");
    CvSeq* circles = sD.detectCircles(image);
    vector<Vec4i> lines = sD.searchLines(image);
    clock_t end = clock();
    float time = (float)(end - Start) /CLOCKS_PER_SEC;
    std::cout << (circles->total+ lines.size()) << " Objects detected in " << time << " seconds" << std::endl;

    sD.writeCircles(circles);
    sD.writeLinesToConsole(lines);
}

int main(int argc, char** argv)
{
    if(argc >1 && strcmp(argv[1], "test") == 0){
        std::cout << "running Shape Detection test" << std::endl;
        test();
        return 0;
    }
    ShapeDetector sD;
    const Mat & orginal_image = sD.createImage(argv[1]);
    Mat & customImage = orginal_image.clone();
    CvSeq* circles = sD.detectCircles(customImage);
    vector<Vec4i> lines = sD.searchLines(customImage);
    sD.writeObjectsToConsole(lines,circles);
    sD.showObjects(lines,circles, orginal_image, customImage);
    cv::waitKey(0);
    return 0;
}
