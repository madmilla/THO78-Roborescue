#include "shapedetector.h"

ShapeDetector::ShapeDetector()
{
}

ShapeDetector::~ShapeDetector()
{

}

void ShapeDetector::writeCirclesToConsole(const CvSeq * circles){
    std::cout << "found circles: " << (circles->total) << std::endl << std::endl;
    for (int i = 0; i < circles->total; i++) // walk through the circles
    {
        // round the floats to an int
        std::cout << "Circle "<< i+1 << std::endl;
        float* p = (float*)cvGetSeqElem(circles, i);
        cv::Point center(cvRound(p[0]), cvRound(p[1]));
        int radius = cvRound(p[2]);
        std::cout << "("<< center.x << "," << center.y<< ")    \t" << radius << "\n\n";
    }
}

void ShapeDetector::drawCircles(const CvSeq * circles, Mat & image){
    for (int i = 0; i < circles->total; i++) //Walk through all the circles
    {
        // round the floats to an int
        float* p = (float*)cvGetSeqElem(circles, i);
        cv::Point center(cvRound(p[0]), cvRound(p[1]));
        int radius = cvRound(p[2]);

        // draw the circle center
        circle(image, center, CIRCLE_CENTER_RADIUS, CIRCLE_CENTER_COLOR, CENTER_THICKNESS, CIRCLE_LINE_TYPE);
        // draw the circle outline
        circle(image, center, radius, CIRCUMFERENCE_COLOR, CIRCLE_THICKNESS, CIRCLE_LINE_TYPE);
    }
    //Show Image with the detected circles
}

CvSeq * ShapeDetector::detectCircles(const Mat & image){
	Mat newImage = image.clone();
	Mat frame;
	cv::GaussianBlur(newImage, frame, cv::Size(0, 0), 3);
	cv::addWeighted(frame, 100, newImage, -100, 10, newImage);
    IplImage img = newImage;

    IplImage* gray = cvCreateImage(cvGetSize(&img), IPL_DEPTH_8U, 1); // create a new image with only black and white pixels
    CvMemStorage* storage = cvCreateMemStorage(0);

    cvCvtColor(&img, gray, CV_BGR2GRAY); // transform the created image into the black/white image

    cvSmooth(gray, gray, CV_GAUSSIAN, SMOOTH, SMOOTH); // This is done so as to prevent a lot of false circles from being detected
    IplImage* canny = cvCreateImage(cvGetSize(&img),IPL_DEPTH_8U,1); // Create a image which will only contain the edges of the objects
    cvCanny(gray, canny, EDGE_TRESHHOLD, EDGE_TRESHHOLD); // Detect edges int he image

    CvSeq* circles = cvHoughCircles(gray, storage, CV_HOUGH_GRADIENT, RESOLUTION_INVERSERATIO, gray->height/MIN_DISTANCE_CIRCLES, EDGE_TRESHHOLD*3, CIRCLE_CENTER_TRESHHOLD); // Detect circles in the gray image
    return circles;
}

bool ShapeDetector::callCvSmooth(const Mat & m_src, const Mat & m_dest, const int smooth_type, const int param1, const int param2) {
    if(m_src.empty()) {
        return false;
    }
    IplImage src = m_src;
    IplImage dst = m_dest;
    cvSmooth( &src, &dst, smooth_type, param1, param2 );
    return true;
}

Mat ShapeDetector::createImage(Pointcloud & source){

    size_t imageHeight = source.getCloudHeight();
    size_t imageWidth = source.getCloudWidth();
   
    Mat mat((int)imageWidth,(int)imageHeight,CV_8UC1); //Create a Mat object which will represent the image with all the pixels
	for (int y = 0; y < imageHeight; ++y){
		for (int x = 0; x < imageWidth; ++x){
			mat.at<uchar>(Point(y, x)) = BLACK_PIXEL;
		}
	}
	for (Pointcloud::Point p : source.getPoints()){
		mat.at<uchar>(Point(p.Y, p.X)) = WHITE_PIXEL;
	}
    imwrite("output.jpg", mat); // save the image

    Mat image(imread("output.jpg")); //read and return the image
	return image;
}

void ShapeDetector::checkLines(vector<Vec4i> & lines) {

    for( size_t i = 0; i < lines.size(); i++ ) {    //walk through the line container
        Vec4i second = lines[i];
        for (size_t j = 0; j < lines.size(); j++) {
            Vec4i current = lines[j];

            const int current_x1 = (current[0]);
            const int current_y1 = (current[1]);
            const int current_x2 = (current[2]);
            const int current_y2 = (current[3]);

            const int second_x1 = second[0];
            const int second_y1 = second[1];
            const int second_x2 = second[2];
            const int second_y2 = second[3];

            if((second_x1 - RANGE_CHECK)< current_x1&& (second_x2 + RANGE_CHECK) > current_x2) {
                if(((second_y1 < (current_y1 + RANGE_CHECK)) && second_y1 > (current_y1 - RANGE_CHECK)) &&  //compare the current and the second line
                  ((second_y2 < (current_y2 + RANGE_CHECK)) && second_y2 > (current_y2 - RANGE_CHECK))){    // coordinates in a range

                    if(j!=i){
                        lines.erase(lines.begin()+j); // erase the target line
                    }
                }
            }
        }
    }
}

vector<Vec4i> ShapeDetector::searchLines(const Mat & image) {

    if (image.empty()) { //check if there is an image
        std::cout << "could not read image" << std::endl;
        exit(-1);
    }
	Mat newImage = image.clone();
	Mat frame;
	
	cv::GaussianBlur(newImage, frame, cv::Size(3, 3), 3);										////////////////////////////
	cv::addWeighted(frame, 10, newImage, -10, 0, newImage);                                     ///////////////////////////									
	imwrite( "lines.jpg",newImage);
    Mat dest;
	if (!callCvSmooth(newImage, newImage, CV_GAUSSIAN, SMOOTH, SMOOTH)) {						///////////////////////////
       std::cout << "the source file is empty!" << std::endl;
       exit(-1);
	}
	Sobel(InputArray src, OutputArray dest, int ddepth = -1, int dx = 1, int dy = 0, int ksize = 3, double scale = 1, double delta = 0, int borderType = BORDER_DEFAULT)
	Canny(newImage, dest, CANNY_THRESHHOLD1, CANNY_THRESHHOLD2); //extracts the egdes of an image	//////////////////////
	imwrite("linesdest.jpg", dest);
    vector<Vec4i> lines;  // container to save the lines
    HoughLinesP(dest, lines, HOUGHLINES_RHO, HOUGHLINES_THETA, HOUGHLINES_THRESHHOLD,			///////////////////////////
    HOUGHLINES_MINLINELENGTH, HOUGHLINES_MAXLINEGAP);  //search the lines

    checkLines(lines); //check for double lines

    return lines;  // return the saved lines
}

void ShapeDetector::writeLinesToConsole(const vector<Vec4i> & lines) {
    std::stringstream stream;
    stream << "found lines: " << lines.size() << std::endl << std::endl;
    for (size_t i = 0; i < lines.size(); i++ ) {
        Vec4i line = lines[i];
        stream << "line " << i+1 << std::endl;
        stream << "(x1, y1) (" << line[0] << ',' << line[1] << ')' << std::endl;
        stream << "(x2, y2) (" << line[2] << ',' << line[3] << ')' << std::endl << std::endl;
    }
    std::cout << stream.str();
}

void ShapeDetector::drawLines(const vector<Vec4i> & lines, Mat & final_dest) {
    for( size_t i = 0; i < lines.size(); i++ ) {
        Vec4i l = lines[i];
        line( final_dest, Point(l[0], l[1]), Point(l[2], l[3]), LINECOLOR, THICKNESS, CV_AA);
    }
}

void ShapeDetector::writeObjectsToConsole(const vector<Vec4i> & lines, const CvSeq * circles) {
    writeCirclesToConsole(circles);
    writeLinesToConsole(lines);
}

void ShapeDetector::showObjects(const vector<Vec4i> & lines, const CvSeq * circles, const Mat & orginal_image, Mat & custom_image){
    drawLines(lines, custom_image);
    drawCircles(circles, custom_image);
    imshow("orginal image", orginal_image);
    imshow("detected lines & circles", custom_image);
}


