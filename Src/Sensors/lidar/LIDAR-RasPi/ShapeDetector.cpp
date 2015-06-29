#include "ShapeDetector.h"

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
	size_t imageHeight = source.getCloudHeight() +DEVIDEIMAGESIZE;
	size_t imageWidth = source.getCloudWidth() + DEVIDEIMAGESIZE;		
	Mat mat((int)(imageHeight / DEVIDEIMAGESIZE), (int)(imageWidth / DEVIDEIMAGESIZE), CV_8U); //Create a Mat object which will represent the image with all the pixels
	for (Pointcloud::Point p : *source.getPoints()){
		mat.at<uchar>(Point( (int) ((p.X + abs(minX)) / DEVIDEIMAGESIZE), (int)( ((p.Y + abs(minY) )) / DEVIDEIMAGESIZE))) = WHITE_PIXEL;
	}
	imwrite("ScanImage.jpg", mat); // save the created image
	Mat image(imread("ScanImage.jpg")); //read and return the image
	return image;
}
void ShapeDetector::removeLines(std::vector<Line> & lines){ 
	for(int i = 0; i < lines.size(); ++i){
		int vectorPosition = 0;
		for (auto it = lines.begin(); it != lines.end();){
			++vectorPosition;
			int value = lines[i].intersect(*it);
			if ((value != 0 && value != 100)){
				//std::cout << value << 
			}
			if(value > 95){
				if (lines[i].getLength() >= (*it).getLength()){
					if (!(lines[i].getLine().begin_pos == it->getLine().begin_pos && lines[i].getLine().end_pos == it->getLine().end_pos)){
						it = lines.erase(it);
						if (vectorPosition <= i) { --i; }
						continue;
					}
				}
			}
			++it;
		}
	}
}
Line ShapeDetector::combineTwoLines(Line & line1, Line & line2){
	Line::Point formula2 = line2.getFormula();
	if (line1.pointOnLine(line1.getLine().begin_pos, formula2, line2.getLine())){
		return Line{ line2.getLine().begin_pos, line1.getLine().end_pos };
	}
	else{
		return Line{ line1.getLine().begin_pos, line2.getLine().end_pos };
	}
}
void ShapeDetector::combineLines(std::vector<Line> & lines){
	for (int i = 0; i < lines.size(); ++i){
		for (auto it = lines.begin(); it != lines.end();){
			int value = lines[i].intersect(*it);
			if (value > 0){
				float slopeA = lines[i].getFormula().x;
				float slopeB = (*it).getFormula().x;
				if (abs(slopeA - slopeB) < SLOPE_THRESHOLD && value!=100){
					lines[i].setLine(combineTwoLines(lines[i], *it).getLine().begin_pos, combineTwoLines(lines[i], *it).getLine().end_pos);
					lines.erase(it);
				}
			}
			++it;
		}
		
	}
}
void ShapeDetector::checkLines(std::vector<Line> & lines) {
	removeLines(lines);
	combineLines(lines);
	removeLines(lines);
	
}

vector<Line> ShapeDetector::searchLines(const Mat & image) {
	if (image.empty()) { //check if there is an image
		std::cout << "could not read image" << std::endl;
		exit(-1);
	}
	Mat newImage = image.clone();
	Mat frame;

	
	blur(newImage, frame, Size(5, 5), Point(-1, -1));
	cv::addWeighted(frame, 10, newImage, -10, 0, newImage);            								
	Mat dest;
	Canny(newImage, dest, CANNY_THRESHHOLD1, CANNY_THRESHHOLD2); //extracts the egdes of an image
	vector<Vec4i> lines;  // container to save the lines
	cvtColor(newImage, newImage, CV_RGB2GRAY);
	HoughLinesP(newImage, lines, HOUGHLINES_RHO, HOUGHLINES_THETA, HOUGHLINES_THRESHHOLD,			
		HOUGHLINES_MINLINELENGTH, HOUGHLINES_MAXLINEGAP);  //search the lines

	
	vector<Line> newLines;
	for (Vec4i line : lines){
		Line::Point begin{ (float)line[0],  (float)line[1] };
		Line::Point end{ (float)line[2], (float)line[3] };
		Line newLine(begin,end);
		newLines.push_back(newLine);
	}
	checkLines(newLines); //check for double lines
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

void ShapeDetector::drawLines(const std::vector<Line> lines, Mat & final_dest, Line::Point lidarPoint) {
	std::cout << lidarPoint << "\t LIDARPOINT\n";
	if (lidarPoint.x != 0){
		line(final_dest, Point(lidarPoint.x - 10, lidarPoint.y), Point(lidarPoint.x + 10, lidarPoint.y), LIDAR_MARK_COLOR, LINE_THICKNESS, CV_AA); //Draw lidarPoint position
		line(final_dest, Point(lidarPoint.x, lidarPoint.y - 10), Point(lidarPoint.x, lidarPoint.y + 10), LIDAR_MARK_COLOR, LINE_THICKNESS, CV_AA);//Draw lidarPoint position
	}
	for (Line l : lines){
		line(final_dest, Point(l.getLine().begin_pos.x, l.getLine().begin_pos.y), Point(l.getLine().end_pos.x, l.getLine().end_pos.y), LINECOLOR, LINE_THICKNESS, CV_AA);
		circle(final_dest, Point(l.getLine().begin_pos.x, l.getLine().begin_pos.y), CIRCLE_CENTER_RADIUS, LINE_BEGINPOINT_COLOR, CENTER_THICKNESS, CIRCLE_LINE_TYPE);
		circle(final_dest, Point(l.getLine().end_pos.x, l.getLine().end_pos.y), CIRCLE_CENTER_RADIUS, LINE_ENDPOINT_COLOR, CENTER_THICKNESS, CIRCLE_LINE_TYPE);
	}
}

void ShapeDetector::writeObjectsToConsole(const std::vector<Line> & lines, const std::vector<Circle> circles) {
	writeCirclesToConsole(circles);
	writeLinesToConsole(lines);
}

void ShapeDetector::showObjects(const vector<Line> & lines, const std::vector<Circle> circles, const Mat & orginal_image, Mat & custom_image, Line::Point lidarPoint){
	drawLines(lines, custom_image, lidarPoint);
	imwrite("newImage.png",custom_image);
	drawCircles(circles, custom_image);
	imshow("orginal image", orginal_image);
	imshow("detected lines & circles", custom_image);
}
