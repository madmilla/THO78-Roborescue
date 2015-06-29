/*!
 * \brief Containing functions to detect shapes
 * \details Class with functions to detect lines and circles out of a pointcloud object
 * \author Tijmen Bruggeman - 1634346
 * \author Patrick Schoonheym - 1639598
 * \author Owen Hogenboezen - 1643103
 * \author Nick Verhaaf - 1641355
 * \version 2.1
 * \date 03-06-2015
 */

#ifndef SHAPEDETECTOR_H
#define SHAPEDETECTOR_H

#include "imgproc/imgproc.hpp"
#include "highgui/highgui.hpp"
#include "opencv.hpp"
#include <iostream>
#include <fstream>
#include "PointCloud.h"
#include "Circle.h"
#include "Line.h"

using namespace std;
using namespace cv;
class ShapeDetector{

private:
    const CvScalar CIRCLE_CENTER_COLOR = CV_RGB(255,0,0); //! The color for the center of the circle
    const CvScalar DEFAULT_IMAGE_COLOR = CV_RGB(0,0,0);   //! The default color of the image
    const CvScalar CIRCUMFERENCE_COLOR = CV_RGB(0,0,255); //! The color for the circumference of the circle
	const CvScalar LINECOLOR = CV_RGB(0, 255, 0); //! the line color
	const CvScalar LINE_BEGINPOINT_COLOR = CV_RGB(0, 0, 255); //!The color of the beginMark of a line
	const CvScalar LINE_ENDPOINT_COLOR = CV_RGB(255, 0, 0); //! the color of the endmark of a line
	const CvScalar LIDAR_MARK_COLOR = CV_RGB(255, 0, 150); //! the color of the mark for the lidarposition on the image
    const int CIRCLE_LINE_TYPE = 8; //! the line type of the circumference
    const int CENTER_THICKNESS = -1;//! the thickness of the point in the middle of the circle
    const int CIRCLE_THICKNESS = 2; //! the thickness of the circumferenc of the circle
    const int CIRCLE_CENTER_RADIUS = 1; //! the radius(size) of the point in the middle of the circle
    const int EDGE_TRESHHOLD = 50; //! the treshhold for detectecting the edges in the image
    const int RESOLUTION_INVERSERATIO = 1; //! the resolution inverseratio
    const int MIN_DISTANCE_CIRCLES = 6; //! the minimun distance between the different circles
    const int CIRCLE_CENTER_TRESHHOLD = 45; //! the treshold for detecting a circle center
    const int BLACK_PIXEL = 0; //! the value for a black pixel
    const int WHITE_PIXEL = 255; //! the value for a white pixel
    const int SMOOTH = 7; //! the value in cvSmooth
    const int RANGE_CHECK = 40; //! the range for checking inconsistent linesw
    const int CANNY_THRESHHOLD1 = 50; //! the first threshhold used in the canny function
    const int CANNY_THRESHHOLD2 = 82; //! the second threshhold used in the canny function
    const double HOUGHLINES_RHO = 1; //! The resolution of the parameter r in pixels. We use 1 pixel.
    const double HOUGHLINES_THETA = CV_PI/180; //! The resolution of the parameter theta in radians. We use 1 degree (CV_PI/180)
    const int HOUGHLINES_THRESHHOLD = 20; //! The minimum number of intersections to “detect” a line
    const double HOUGHLINES_MINLINELENGTH = 5; //! The minimum number of points that can form a line. Lines with less than this number of points are disregarded.
    const double HOUGHLINES_MAXLINEGAP = 20; //! The maximum gap between two points to be considered in the same line.
    const int LINE_THICKNESS = 1; //! the thickness of the line
	float SLOPE_THRESHOLD = 0.1; //! the Maximum difference between slope a en b in combineLines

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
    void checkLines(std::vector<Line>& lines);

	//! remove double lines
	/*!
	remove double lines from the vector, only lines who intersect 100% will be removed
	@param lines: a vector with the lines to be checked
	*/
	void removeLines(std::vector<Line> & lines);
	//! combine lines on the same line
	/*!
	combines lines which intersects for more than 0% and has the same slope
	@param lines: a vector with the lines to be checked
	*/
	void combineLines(std::vector<Line> & lines);
	//! combines two lines to one line
	/*!
	combines two specific lines to one line.
	@param line1: the first line to be combined with another line
	@param line2: the second line
	@return Line: the combined line
	*/
	Line combineTwoLines(Line &line1, Line& line2);

public:
	//! The Constructor of ShapeDetector
    ShapeDetector();
	//! THe destructor of ShapeDetector
    ~ShapeDetector();
    //! write circles on the
    /*!
    This functions writes all the circle positions and radii to a file according to the outputName paramter
    @param circles: the CvSeq with circles to be written on the console
    */
    void writeCirclesToConsole(const std::vector<Circle> circles);
    //! Draw circles on a given image
    /*!
    This function draws all the circles on the given image.
    @param circles: the CvSeq with circles to be drawn on the image
    @param image: A reference to the image where the circles should be drawn on
    */
    void drawCircles(const std::vector<Circle> circles, Mat & image);
    //! detect circles in a image
    /*!
    //This function detect circles and return a CVSEQ pointer with the detected circles
    @param image: The image to detect circles on
    */
    std::vector<Circle> detectCircles(const Mat & image);
    //! create a image from the given pointcloud source
    /*!
    This function creates a .jpg file from a .txt file with pixels and saves it as output.jpg
    @param source: The pointcloud to detect circles on
	@return mat: the created image
    */
	Mat createImage(Pointcloud & source, int DEVIDEIMAGESIZE = 1);

    //! the function search for lines in the given image and returns the lines
    /*!
    @param image: the image to detect lines on
	@return vector: Returns a vector with the found lines
    */
    std::vector<Line> searchLines(const Mat & image);

    //! write the lines container to the console
    /*!
    @param lines: the vec4i lines to draw to the console
    */
    void writeLinesToConsole(const vector<Line> & lines);

    //! draw the lines in a given matrix
    /*!
    @param lines: contains the lines to draw;
    @param final_dest: the image to draw on
	@param lidarPoint: the position of the lidar to be drawn on the image
    */
	void drawLines(const std::vector<Line> lines, Mat & final_dest, Line::Point lidarPoint = Line::Point{ 0, 0 });

    //! write the circle and line objects to the console
    /*!
     @param lines: the given lines to write
     @param circles: the given circles to write
     */
	void writeObjectsToConsole(const std::vector<Line> & lines, const std::vector<Circle> circles);

    //! show the circle and line objects in one window
    /*!
     @param lines: the given lines to show
     @param circles: the given circles to show
     @param orginal_image: the orginal input image to show
     @param custom_image: the edited image with the lines and circles to show
	 @param lidarPoint: the position of the lidar to be drawn on the screen
     */
	void showObjects(const vector<Line> & lines, const vector<Circle> circles, const Mat & orginal_image, Mat & custom_image, Line::Point lidarPoint = Line::Point{ 0, 0 });

};

#endif // SHAPEDETECTOR_H
