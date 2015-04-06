
// First parameter is .txt file with the pixels.

// compiled with: g++ circles.cpp -o circles `pkg-config --cflags --libs opencv`
#include <iostream>
#include <stdio.h>
#include "time.h"
#include "ctime"
#include <math.h>
#include <fstream>
#include "shapedetector.h"
#include "../../deps/files/opencv/highgui/highgui.hpp"
#include "../../deps/files/opencv/imgproc/imgproc.hpp"
#include "../../deps/files/opencv/cv.h"
#include "../../deps/files/opencv/core/core.hpp"

void test(){
    ShapeDetector sD;
    clock_t Start = clock();
    CvSeq* circles = sD.detectCircles("circles400.txt");
    clock_t end = clock();
    int time = end - Start;
    printf("%d circles detected in %f sec\n\n", circles->total,(float)time /CLOCKS_PER_SEC);
    if (circles->total != 7){
        exit(-1);
    }
    sD.writeCircles(circles);
}

int main(int argc, char** argv)
{
    if(argc >1 && strcmp(argv[1], "test") == 0){
        printf("Testing CircleDetection\n\n");
        test();
        return 0;
    }
    ShapeDetector sD;
    CvSeq* circles = sD.detectCircles(argv[1]);
    sD.writeCircles(circles);
    sD.showCircles(circles);
    cv::waitKey(0);
    return 0;
}
