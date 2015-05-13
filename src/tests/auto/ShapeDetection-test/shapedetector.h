/*!
 * \brief Containing functions to detect shapes
 * \details Class with functions to detect lines and circles out of a pointcloud object
 * \author Tijmen Bruggeman - 1634346
 * \author Patrick Schoonheym - 1639598
 * \version 2.0
 * \date 22-04-2015
 */

#ifndef SHAPEDETECTOR_H
#define SHAPEDETECTOR_H

#include "imgproc/imgproc.hpp"
#include "highgui/highgui.hpp"
#include "opencv.hpp"
#include <iostream>
#include <fstream>
#include "PointCloud.h"

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
    const int CIRCLE_CENTER_TRESHHOLD = 45; //! the treshold for detecting a circle center
    const int BLACK_PIXEL = 0; //! the value for a black pixel
    const int WHITE_PIXEL = 255; //! the value for a white pixel
    const int SMOOTH = 7; //! the value in cvSmooth
    const int RANGE_CHECK = 40; //! the range for checking inconsistent lines
    const int CANNY_THRESHHOLD1 = 50; //! the first threshhold used in the canny function
    const int CANNY_THRESHHOLD2 = 82; //! the second threshhold used in the canny function
    const double HOUGHLINES_RHO = 1; //! The resolution of the parameter r in pixels. We use 1 pixel.
    const double HOUGHLINES_THETA = CV_PI/180; //! The resolution of the parameter theta in radians. We use 1 degree (CV_PI/180)
    const int HOUGHLINES_THRESHHOLD = 40; //! The minimum number of intersections to “detect” a line
    const double HOUGHLINES_MINLINELENGTH = 10; //! The minimum number of points that can form a line. Lines with less than this number of points are disregarded.
    const double HOUGHLINES_MAXLINEGAP = 20; //! The maximum gap between two points to be considered in the same line.
    const CvScalar LINECOLOR = CV_RGB(0,255,0); //! the line color
    const int THICKNESS = 3; //! the thickness of the line

    //! this function converts a Mat object to a IplImage so the function cvSmooth can be used.
    /*!
     @param m_src: the source file
     @param m_dest: the destination file to save on
     @param smooth_type: the smooth value
     @param param1: value1
     @param param2: value2
     */
    bool callCvSmooth(const Mat & m_src, const Mat & m_dest, const int smooth_type, const int param1, const int param2);

    //! the function checks for double lines to prevent unneeded data
    /*!
     @param lines: the given lines to check on
     */
    void checkLines(vector<Vec4i> & lines);

public:
    ShapeDetector();
    ~ShapeDetector();
    //! write circles on the
    /*!
    This functions writes all the circle positions and radii to a file according to the outputName paramter
    @param circles: the CvSeq with circles to be written on the console
    */
    void writeCirclesToConsole(const CvSeq * circles);
    //! Draw circles on a given image
    /*!
    This function draws all the circles on the given image.
    @param circles: the CvSeq with circles to be drawn on the image
    @param image: A reference to the image where the circles should be drawn on
    */
    void drawCircles(const CvSeq * circles, Mat & image);
    //! detect circles in a image
    /*!
    //This function detect circles and return a CVSEQ pointer with the detected circles
    @param image: The image to detect circles on
    */
    CvSeq * detectCircles(const Mat & image);
    //! create a image from the given pointcloud source
    /*!
    This function creates a .jpg file from a .txt file with pixels and saves it as output.jpg
    @param source: The pointcloud to detect circles on
	@return mat: the created image
    */
    Mat createImage(Pointcloud & source);

    //! the function search for lines in the given image and returns the lines
    /*!
    @param image: the image to detect lines on
	@return vector: Returns a vector with the found lines
    */
    vector<Vec4i> searchLines(const Mat & image);

    //! write the lines container to the console
    /*!
    @param lines: the vec4i lines to draw to the console
    */
    void writeLinesToConsole(const vector<Vec4i> & lines);


    //! draw the lines in a given matrix
    /*!
    @param lines: contains the lines to draw;
    @param final_dest: the image to draw on
    */
    void drawLines(const vector<Vec4i> & lines, Mat & final_dest);

    //! write the circle and line objects to the console
    /*!
     @param lines: the given lines to write
     @param circles: the given circles to write
     */
    void writeObjectsToConsole(const vector<Vec4i> & lines, const CvSeq * circles);

    //! show the circle and line objects in one window
    /*!
     @param lines: the given lines to show
     @param circles: the given circles to show
     @param orginal_image: the orginal input image to show
     @param custom_image: the edited image with the lines and circles to show
     */
    void showObjects(const vector<Vec4i> & lines, const CvSeq * circles, const Mat & orginal_image, Mat & custom_image);
};

#endif // SHAPEDETECTOR_H
