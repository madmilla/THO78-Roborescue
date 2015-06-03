#include "shapedetector.h"

ShapeDetector::ShapeDetector()
{
}

ShapeDetector::~ShapeDetector()
{

}

void ShapeDetector::writeCirclesToConsole(const vector<Circle> circles){
	std::cout << "found circles: " << (circles.size()) << std::endl << std::endl;
	for (Circle c : circles){ // walk through the circles
		std::cout << "(" << c.getCircle().originX << "," << c.getCircle().originY << ")    \t" << c.getCircle().radius << "\n\n";
	}
}

void ShapeDetector::drawCircles(const std::vector<Circle> circles, Mat & image){
	for (Circle c : circles){ //Walk through all the circles
		// round the floats to an int
		cv::Point center(c.getCircle().originX, c.getCircle().originY);
		int radius = c.getCircle().radius;

		// draw the circle center
		circle(image, center, CIRCLE_CENTER_RADIUS, CIRCLE_CENTER_COLOR, CENTER_THICKNESS, CIRCLE_LINE_TYPE);
		// draw the circle outline
		circle(image, center, radius, CIRCUMFERENCE_COLOR, CIRCLE_THICKNESS, CIRCLE_LINE_TYPE);
	}
	//Show Image with the detected circles
}

std::vector<Circle> ShapeDetector::detectCircles(const Mat & image){
	Mat newImage = image.clone();
	Mat frame;
	cv::GaussianBlur(newImage, frame, cv::Size(0, 0), 3);
	cv::addWeighted(frame, 100, newImage, -100, 10, newImage);
	IplImage img = newImage;

	IplImage* gray = cvCreateImage(cvGetSize(&img), IPL_DEPTH_8U, 1); // create a new image with only black and white pixels
	CvMemStorage* storage = cvCreateMemStorage(0);

	cvCvtColor(&img, gray, CV_BGR2GRAY); // transform the created image into the black/white image

	cvSmooth(gray, gray, CV_GAUSSIAN, SMOOTH, SMOOTH); // This is done so as to prevent a lot of false circles from being detected
	IplImage* canny = cvCreateImage(cvGetSize(&img), IPL_DEPTH_8U, 1); // Create a image which will only contain the edges of the objects
	cvCanny(gray, canny, EDGE_TRESHHOLD, EDGE_TRESHHOLD); // Detect edges int he image

	CvSeq* circles = cvHoughCircles(gray, storage, CV_HOUGH_GRADIENT, RESOLUTION_INVERSERATIO, gray->height / MIN_DISTANCE_CIRCLES, EDGE_TRESHHOLD * 3, CIRCLE_CENTER_TRESHHOLD); // Detect circles in the gray image
	std::vector<Circle> newCircles;
	for (int i = 0; i < circles->total; i++) // walk through the circles
	{
		// round the floats to an int
		std::cout << "Circle " << i + 1 << std::endl;
		float* p = (float*)cvGetSeqElem(circles, i);
		Circle c(cvRound(p[0]), cvRound(p[1]), cvRound(p[2]));
		newCircles.push_back(c);
	}
	return newCircles;
}

bool ShapeDetector::callCvSmooth(const Mat & m_src, const Mat & m_dest, const int smooth_type, const int param1, const int param2) {
	if (m_src.empty()) {
		return false;
	}
	IplImage src = m_src;
	IplImage dst = m_dest;
	cvSmooth(&src, &dst, smooth_type, param1, param2);
	return true;
}

Mat ShapeDetector::createImage(Pointcloud & source, int DEVIDEIMAGESIZE){
	int minX = source.getMinValues().X;
	int minY = source.getMinValues().Y;
	size_t imageHeight = source.getCloudHeight();
	size_t imageWidth = source.getCloudWidth();
	Mat mat((int)(imageWidth / DEVIDEIMAGESIZE)+1, (int)(imageHeight / DEVIDEIMAGESIZE)+1, CV_8UC1); //Create a Mat object which will represent the image with all the pixels
	for (int y = 0; y < imageHeight; ++y){
		for (int x = 0; x < imageWidth; ++x){
			mat.at<uchar>(Point((int)(y / DEVIDEIMAGESIZE),(int)( x / DEVIDEIMAGESIZE))) = BLACK_PIXEL;
		}
	}

	int i = 0;
	for (Pointcloud::Point p : *source.getPoints()){
		//std::cout << i << " - " << p.X << " - " << p.Y << " ----- " << p.Y + (abs(minY)) << " - " <<  p.X + (abs(minX)) << " --- " << imageHeight << " - " << imageWidth << "\n";
		i++;
		mat.at<uchar>(Point( (int) ((p.Y + abs(minY)) / DEVIDEIMAGESIZE), (int)((p.X + abs(minX)) / DEVIDEIMAGESIZE))) = WHITE_PIXEL;
	}
	imwrite("output.jpg", mat); // save the 
	Mat image(imread("output.jpg")); //read and return the image
	return image;
}

void ShapeDetector::checkLines(vector<Vec4i> & lines) {

	for (size_t i = 0; i < lines.size(); i++) {    //walk through the line container
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

			if ((second_x1 - RANGE_CHECK)< current_x1 && (second_x2 + RANGE_CHECK) > current_x2) {
				if (((second_y1 < (current_y1 + RANGE_CHECK)) && second_y1 >(current_y1 - RANGE_CHECK)) &&  //compare the current and the second line
					((second_y2 < (current_y2 + RANGE_CHECK)) && second_y2 >(current_y2 - RANGE_CHECK))){    // coordinates in a range

					if (j != i){
						lines.erase(lines.begin() + j); // erase the target line
					}
				}
			}
		}
	}
}

vector<Line> ShapeDetector::searchLines(const Mat & image) {

	if (image.empty()) { //check if there is an image
		std::cout << "could not read image" << std::endl;
		exit(-1);
	}
	Mat newImage = image.clone();
	Mat frame;

	//medianBlur(newImage, frame, 3);
	blur(newImage, frame, Size(5, 5), Point(-1, -1));
	//cv::GaussianBlur(newImage, frame, cv::Size(3, 3), 3);										////////////////////////////
	cv::addWeighted(frame, 10, newImage, -10, 0, newImage);                                     ///////////////////////////									
	imwrite("lines1.jpg", frame);
	imwrite("lines2.jpg", newImage);
	Mat dest;
	/*if (!callCvSmooth(newImage, newImage, CV_GAUSSIAN, SMOOTH, SMOOTH)) {						///////////////////////////
		std::cout << "the source file is empty!" << std::endl;
		exit(-1);
	}*/
	imwrite("lines3.jpg", newImage);
	Canny(newImage, dest, CANNY_THRESHHOLD1, CANNY_THRESHHOLD2); //extracts the egdes of an image	//////////////////////
	imwrite("linesdest1.jpg", dest);
	vector<Vec4i> lines;  // container to save the lines
	cvtColor(newImage, newImage, CV_RGB2GRAY);
	HoughLinesP(newImage, lines, HOUGHLINES_RHO, HOUGHLINES_THETA, HOUGHLINES_THRESHHOLD,			///////////////////////////
		HOUGHLINES_MINLINELENGTH, HOUGHLINES_MAXLINEGAP);  //search the lines

	checkLines(lines); //check for double lines
	vector<Line> newLines;
	for (Vec4i line : lines){
		Line::Point begin{ line[0], line[1] };
		Line::Point end{ line[2], line[3] };
		Line newLine(begin,end);
		newLines.push_back(newLine);
	}
	return newLines;  // return the saved lines
}

void ShapeDetector::writeLinesToConsole(const vector<Line> & lines){
	std::stringstream stream;
	stream << "found lines: " << lines.size() << std::endl << std::endl;
	int i = 0;
	for (Line l : lines) {
		stream << "line " << i + 1 << std::endl;
		stream << "(x1, y1) (" << l.getLine().begin_pos.x << ',' << l.getLine().begin_pos.y << ')' << std::endl;
		stream << "(x2, y2) (" << l.getLine().end_pos.x << ',' << l.getLine().end_pos.y << ')' << std::endl << std::endl;
		++i;
	}
	std::cout << stream.str();
}

void ShapeDetector::drawLines(const std::vector<Line> lines, Mat & final_dest) {
	for (Line l : lines){
		l.getLine().end_pos.x;
		line(final_dest, Point(l.getLine().begin_pos.x, l.getLine().begin_pos.y), Point(l.getLine().end_pos.x, l.getLine().end_pos.y), LINECOLOR, THICKNESS, CV_AA);
	}
}

void ShapeDetector::writeObjectsToConsole(const std::vector<Line> & lines, const std::vector<Circle> circles) {
	writeCirclesToConsole(circles);
	writeLinesToConsole(lines);
}

void ShapeDetector::showObjects(const vector<Line> & lines, const std::vector<Circle> circles, const Mat & orginal_image, Mat & custom_image){
	drawLines(lines, custom_image);
	drawCircles(circles, custom_image);
	imshow("orginal image", orginal_image);
	imshow("detected lines & circles", custom_image);
}
