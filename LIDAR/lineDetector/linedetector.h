#ifndef LINEDETECTOR_H
#define LINEDETECTOR_H

#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/opencv.hpp"
#include <iostream>
#include <fstream>

using namespace cv;

class lineDetector
{
private:
    const int BLACK_PIXEL = 255;
    const int WHITE_PIXEL = 0;

    const int SMOOTH = 7;

    const int RANGE_CHECK = 15;
    const int CANNY_THRESHHOLD1 = 50;
    const int CANNY_THRESHHOLD2 = 82;

    const double HOUGHLINES_RHO = 1;
    const double HOUGHLINES_THETA = CV_PI/180;
    const int HOUGHLINES_THRESHHOLD = 20;
    const double HOUGHLINES_MINLINELENGTH = 50;
    const double HOUGHLINES_MAXLINEGAP = 10;

    const CvScalar LINECOLOR = CV_RGB(0,255,0);
    const int THICKNESS = 3;

    bool callCvSmooth(const Mat & m_src, const Mat & m_dest, const int smooth_type,
    const int param1, const int param2);
    void checkLines(vector<Vec4i> & lines);

public:
    lineDetector();
    ~lineDetector();
    Mat createImage(const std::string & source);
    vector<Vec4i> searchLines(const Mat & image, Mat & final_dest);
    void writeLinesToConsole(const vector<Vec4i> & lines);
    void drawLines(const vector<Vec4i> & lines, Mat & final_dest);
    void showGui(const Mat & source, const Mat & final_dest);
};

#endif // LINEDETECTOR_H
