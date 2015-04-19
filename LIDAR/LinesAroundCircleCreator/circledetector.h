#ifndef CIRCLEDETECTOR_H
#define CIRCLEDETECTOR_H
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <opencv/cv.h>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
using namespace cv;

class CircleDetector
{
private:
    CvScalar circleCenterColor = CV_RGB(0,255,0); // groen
    CvScalar circumferenceColor = CV_RGB(0,0,255); // groen
    const int black_pixel = 255;
    const int white_pixel = 0;
    const int circleLineType = 8;
    const int centerThickness = -1;
    const int circleThickness = 2;
    const int circleCenterRadius = 3;
    const int smooth = 7;
    const int edgeTreshhold = 50;
    const int resolutionInverseRatio = 1;
    const int minDistanceCircles = 6;
    const int circleCenterTreshhold = 19;

public:
    CircleDetector();
    ~CircleDetector();
    IplImage * image; // image which will contain the loaded image
    //This function creates a .jpg file from a .txt file with pixels according to the output paramter.
    void makeImage(std::string source, std::string output = "output.jpg");
    //This functions writes all the circle positions and radii to a file according to the outputName paramter
    void writeCircles(CvSeq * circles, std::string outputName = "output.txt");
    //This function shows the input image with the detected circles;
    void showCircles(CvSeq * circles, std::string sourceName = "output.jpg");
    //This function detect circles and return a CVSEQ pointer with the detected circles
    CvSeq * detectCircles(std::string sourceName);
};
#endif // CIRCLEDETECTOR_H
