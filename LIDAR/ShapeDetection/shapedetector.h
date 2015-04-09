#ifndef SHAPEDETECTOR_H
#define SHAPEDETECTOR_H

#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/opencv.hpp"
#include <iostream>
#include <fstream>

using namespace std;
using namespace cv;
class ShapeDetector
{
private:
    CvScalar CIRCLE_CENTER_COLOR = CV_RGB(255,0,0); //! The color for the center of the circle
    CvScalar CIRCUMFERENCE_COLOR = CV_RGB(0,0,255); //! The color for the circumference of the circle
    const int CIRCLE_LINE_TYPE = 8; //! the line type of the circumference
    const int CENTER_THICKNESS = -1;//! the thickness of the point in the middle of the circle
    const int CIRCLE_THICKNESS = 2; //! the thickness of the circumferenc of the circle
    const int CIRCLE_CENTER_RADIUS = 3; //! the radius(size) of the point in the middle of the circle
    const int EDGE_TRESHHOLD = 50; //! the treshhold for detectecting the edges in the image
    const int RESOLUTION_INVERSERATIO = 1; //! the resolution inverseratio
    const int MIN_DISTANCE_CIRCLES = 6; //! the minimun distance between the different circles
    const int CIRCLE_CENTER_TRESHHOLD = 19; //! the treshold for detecting a circle center
    const int BLACK_PIXEL = 255; //! the value for a black pixel
    const int WHITE_PIXEL = 0; //! the value for a white pixel
    const int SMOOTH = 7; //! the value in cvSmooth
    const int RANGE_CHECK = 15; //! the range for checking inconsistent lines
    const int CANNY_THRESHHOLD1 = 50; //! the first threshhold used in the canny function
    const int CANNY_THRESHHOLD2 = 82; //! the second threshhold used in the canny function
    const double HOUGHLINES_RHO = 1; //! The resolution of the parameter r in pixels. We use 1 pixel.
    const double HOUGHLINES_THETA = CV_PI/180; //! The resolution of the parameter theta in radians. We use 1 degree (CV_PI/180)
    const int HOUGHLINES_THRESHHOLD = 20; //! The minimum number of intersections to “detect” a line
    const double HOUGHLINES_MINLINELENGTH = 50; //! The minimum number of points that can form a line. Lines with less than this number of points are disregarded.
    const double HOUGHLINES_MAXLINEGAP = 10; //! The maximum gap between two points to be considered in the same line.
    const CvScalar LINECOLOR = CV_RGB(0,255,0); //! the line color
    const int THICKNESS = 3; //! the thickness of the line

    /* this function converts a Mat object to a IplImage
     * so the function cvSmooth can be used. */
    bool callCvSmooth(const Mat & m_src, const Mat & m_dest, const int smooth_type, const int param1, const int param2);
    /*the function checks for double lines to prevent unneeded data*/
    void checkLines(vector<Vec4i> & lines);

public:
    ShapeDetector();
    ~ShapeDetector();
    //This functions writes all the circle positions and radii to a file according to the outputName paramter
    void writeCircles(const CvSeq * circles);
    //This function shows the input image with the detected circles;
    void drawCircles(const CvSeq * circles, Mat & final_dest);
    //This function detect circles and return a CVSEQ pointer with the detected circles
    CvSeq * detectCircles(const Mat & image);

    /*This function creates a .jpg file from a .txt file with pixels according to the output paramter
     * and after creation returns the picture */
    Mat createImage(const std::string & source);
    /* the function search for lines in the given image
     * and returns the lines*/
    vector<Vec4i> searchLines(const Mat & image);
    /* write the lines container to the console*/
    void writeLinesToConsole(const vector<Vec4i> & lines);
    /* draw the lines in a given matrix */
    void drawLines(const vector<Vec4i> & lines, Mat & final_dest);

    void writeObjectsToConsole(const vector<Vec4i> & lines, const CvSeq * circles);
    void showObjects(const vector<Vec4i> & lines, const CvSeq * circles, const Mat & orginal_image, Mat & custom_image);
};

#endif // SHAPEDETECTOR_H
