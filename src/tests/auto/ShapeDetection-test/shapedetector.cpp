#include "shapedetector.h"

ShapeDetector::ShapeDetector()
{
}

ShapeDetector::~ShapeDetector()
{

}

void ShapeDetector::writeCirclesToConsole(const CvSeq * circles){
    std::cout << "found circles: " << (circles->total) << std::endl << std::endl;
    for (int i = 0; i < circles->total; ++i) // walk through the circles
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
    for (int i = 0; i < circles->total; ++i) //Walk through all the circles
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
    IplImage img = image;

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

Mat ShapeDetector::createImage(const std::string & source){
    std::ifstream file(source); // open  inputfile
    if (!file.is_open()){
        std::cout << "could not open file with name " << source << std::endl;
        exit(EXIT_FAILURE);
    }
    std::string line;
    size_t imageHeight = 0;
    size_t imageWidth = 0;
    while(getline(file,line)){ //a while loop to get the image width and the image Height
        imageHeight++;
        if(line.length()> imageWidth){
            imageWidth = line.length();
        }
    }
    Mat mat((int)imageWidth,(int)imageHeight,CV_8UC1); //Create a Mat object which will represent the image with all the pixels
    int x = 0;
    file.clear();
    file.seekg(0,file.beg);
    while(getline(file,line)){ //Walk through the file
        int y = 0;
        for(int i = 0; i< (int)imageWidth; ++i){
            char ch = line[i];
            if(isdigit(ch)){ // if the char in the file is a number, the pixel should be 255
                mat.at<uchar>(Point(y,x)) = BLACK_PIXEL; // set the pixel at 255
            }
            else{
                mat.at<uchar>(Point(y,x)) = WHITE_PIXEL;
            }
            y++;
        }
        x++;
    }
    file.close();
    imwrite("output.jpg", mat); // save the image

    return Mat(imread("output.jpg")); //read and return the image
}

void ShapeDetector::checkLines(vector<Vec4i> & lines) {

    for( size_t i = 0; i < lines.size(); ++i ) {    //walk through the line container
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

    if (image.empty()) { //check if there is a image
        std::cout << "could not read image" << std::endl;
        exit(-1);
    }

    Mat dest;
    if(!callCvSmooth(image, image, CV_GAUSSIAN, SMOOTH, SMOOTH)) {
       std::cout << "the source file is empty!" << std::endl;
       exit(-1);
    }
    Canny(image, dest, CANNY_THRESHHOLD1, CANNY_THRESHHOLD2); //extracts the egdes of an image

    vector<Vec4i> lines;  // container to save te lines
    HoughLinesP(dest, lines, HOUGHLINES_RHO, HOUGHLINES_THETA, HOUGHLINES_THRESHHOLD,
    HOUGHLINES_MINLINELENGTH, HOUGHLINES_MAXLINEGAP);  //search the lines

    checkLines(lines); //check for double lines

    return lines;  // return the saved lines
}

void ShapeDetector::writeLinesToConsole(const vector<Vec4i> & lines) {
    std::stringstream stream;
    stream << "found lines: " << lines.size() << std::endl << std::endl;
    for (size_t i = 0; i < lines.size(); ++i ) {
        Vec4i line = lines[i];
        stream << "line " << i+1 << std::endl;
        stream << "(x1, y1) (" << line[0] << ',' << line[1] << ')' << std::endl;
        stream << "(x2, y2) (" << line[2] << ',' << line[3] << ')' << std::endl << std::endl;
    }
    std::cout << stream.str();
}

void ShapeDetector::drawLines(const vector<Vec4i> & lines, Mat & final_dest) {
    for( size_t i = 0; i < lines.size(); ++i ) {
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


