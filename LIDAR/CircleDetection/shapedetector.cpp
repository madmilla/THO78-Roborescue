#include "shapedetector.h"

ShapeDetector::ShapeDetector()
{
}

ShapeDetector::~ShapeDetector()
{

}

using namespace cv;
//This function creates a .jpg file from a .txt file with pixels according to the output paramter.
void ShapeDetector::makeImage(std::string source, std::string output){
    std::ifstream file(source); // open  inputfile
    if (!file.is_open()){
        printf("File niet gevonden.....\nProgramma wordt afgesloten\n");
        exit(-1);
    }
    std::string line;
    int imageHeight = 0;
    int imageWidth = 0;
    while(getline(file,line)){ //a while loop to get the image width and the imageHeight
        imageHeight++;
        if(line.length()> imageWidth){
            imageWidth = line.length();
        }
    }
    Mat * newMat = new Mat(imageWidth,imageHeight,CV_8UC1); //Create a Mat object which will represent the image with all the pixels
    int x = 0;
    file.clear();
    file.seekg(0,file.beg);
    while(getline(file,line)){ //Walk through the file
        int y = 0;
        for(int i = 0; i< imageWidth; i++){
            char ch = line[i];
            if(isdigit(ch)){ // if the char in the file is a number, the pixel should be 255
                newMat->at<uchar>(Point(y,x)) = black_pixel; // set the pixel at 255 ==
            }
            else{
                newMat->at<uchar>(Point(y,x)) = white_pixel;
            }
            y++;
        }
        x++;
    }
    file.close();
    imwrite(output, *newMat); // save the image according to the output paramter
}
//This functions writes all the circle positions and radii to a file according to the outputName paramter
void ShapeDetector::writeCircles(CvSeq * circles, std::string outputName){
    std::ofstream output(outputName, std::ofstream::out); // open output
    if (!output.is_open()){
        printf("File niet gevonden.....\nProgramma wordt afgesloten\n");
        exit(-1);
    }
    output << "(X,Y)    \tRadius\n"; //write data info to the file
    for (size_t i = 0; i < circles->total; i++) // walk through the circles
    {
        // round the floats to an int
        float* p = (float*)cvGetSeqElem(circles, i);
        cv::Point center(cvRound(p[0]), cvRound(p[1]));
        int radius = cvRound(p[2]);
        output << "("<< center.x << "," <<center.y<< ")\t" << radius << "\n";
        std::cout << "("<< center.x << "," << center.y<< ")     \t" << radius << "\n";
    }
    output.close();
}
//This function shows the input image with the detected circles;
void ShapeDetector::showCircles(CvSeq * circles, std::string sourceName ){
    IplImage * image; // image which will contain the loaded image
    if ((image = cvLoadImage("output.jpg"))== 0)
    {
        printf("File niet gevonden.....\nProgramma wordt afgesloten\n");
        exit(-1);
    }
    for (size_t i = 0; i < circles->total; i++) //Walk through all the circles
    {
        // round the floats to an int
        float* p = (float*)cvGetSeqElem(circles, i);
        cv::Point center(cvRound(p[0]), cvRound(p[1]));
        int radius = cvRound(p[2]);


        // draw the circle center
        cvCircle(image, center, circleCenterRadius, circleCenterColor, centerThickness, circleLineType);

        // draw the circle outline
        cvCircle(image, center, radius, circumferenceColor, circleThickness, circleLineType);
    }

    ///Show Image with the detected circles
    cvNamedWindow("circles");
    cvShowImage("circles", image);
}

//This function detect circles and return a CVSEQ pointer with the detected circles
CvSeq * ShapeDetector::detectCircles(std::string sourceName){
    IplImage* img = NULL;

    makeImage(sourceName, "output.jpg");//Make a image from the txt file and save it as output.jpg
    if ((img = cvLoadImage("output.jpg"))== 0) //Check if the image can be loaded
    {
        printf("cvLoadImage failed\n");
    }

    IplImage* gray = cvCreateImage(cvGetSize(img), IPL_DEPTH_8U, 1); // create a new image with only black and white pixels
    CvMemStorage* storage = cvCreateMemStorage(0);

    cvCvtColor(img, gray, CV_BGR2GRAY); // transform the created image into the black/white image


    cvSmooth(gray, gray, CV_GAUSSIAN, smooth, smooth); // This is done so as to prevent a lot of false circles from being detected

    IplImage* canny = cvCreateImage(cvGetSize(img),IPL_DEPTH_8U,1); // Create a image which will only contain the edges of the objects
    IplImage* rgbcanny = cvCreateImage(cvGetSize(img),IPL_DEPTH_8U,3); // Create a image with color pixels where the circles will be drawn
    cvCanny(gray, canny, edgeTreshhold, edgeTreshhold); // Detect edges int he image

    CvSeq* circles = cvHoughCircles(gray, storage, CV_HOUGH_GRADIENT, resolutionInverseRatio, gray->height/minDistanceCircles, edgeTreshhold*3, circleCenterTreshhold); // Detect circles in the gray image
    return circles;
}
