//First parameter is .txt file with the pixels.
// compiled with: g++ circles.cpp -o circles `pkg-config --cflags --libs opencv`
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <opencv/cv.h>
#include <iostream>
#include <stdio.h>
#include "time.h"
#include "ctime"
#include <math.h>
#include <fstream>
using namespace cv;
//This function creates a .jpg file from a .txt file with pixels according to the output paramter.
void makeImage(std::string source, std::string output = "output.jpg"){
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
                newMat->at<uchar>(Point(y,x)) = 255; // set the pixel at 255
            }
            else{
                newMat->at<uchar>(Point(y,x)) = 0;
            }
            y++;
        }
        x++;
    }
    file.close();
    imwrite(output, *newMat); // save the image according to the output paramter
}
//This functions writes all the circle positions and radii to a file according to the outputName paramter
void WriteCircles(CvSeq * circles, std::string outputName = "output.txt"){
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
void ShowCircles(CvSeq * circles, std::string sourceName = "output.jpg"){
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
        cvCircle(image, center, 3, CV_RGB(0,255,0), -1, 8, 0 );

        // draw the circle outline
        cvCircle(image, center, radius+3, CV_RGB(0,0,255), 2, 8, 0 );
    }

    ///Show Image with the detected circles
    cvNamedWindow("circles", 1);
    cvShowImage("circles", image);
}

//This function detect circles and return a CVSEQ pointer with the detected circles
CvSeq * DetectCircles(std::string sourceName){
    IplImage* img = NULL;

    makeImage(sourceName, "output.jpg");//Make a image from the txt file and save it as output.jpg
    if ((img = cvLoadImage("output.jpg"))== 0) //Check if the image can be loaded
    {
        printf("cvLoadImage failed\n");
    }

    IplImage* gray = cvCreateImage(cvGetSize(img), IPL_DEPTH_8U, 1); // create a new image with only black and white pixels
    CvMemStorage* storage = cvCreateMemStorage(0);

    cvCvtColor(img, gray, CV_BGR2GRAY); // transform the created image into the black/white image


    cvSmooth(gray, gray, CV_GAUSSIAN, 7, 7); // This is done so as to prevent a lot of false circles from being detected

    IplImage* canny = cvCreateImage(cvGetSize(img),IPL_DEPTH_8U,1); // Create a image which will only contain the edges of the objects
    IplImage* rgbcanny = cvCreateImage(cvGetSize(img),IPL_DEPTH_8U,3); // Create a image with color pixels where the circles will be drawn
    cvCanny(gray, canny, 50, 100, 3); // Detect edges int he image

    CvSeq* circles = cvHoughCircles(gray, storage, CV_HOUGH_GRADIENT, 1, gray->height/6, 145, 19); // Detect circles in the gray image
    return circles;
}
void test(){
    clock_t Start = clock();
    CvSeq* circles = DetectCircles("circles400.txt");
    clock_t end = clock();
    int time = end - Start;
    printf("%d circles detected in %f sec\n\n", circles->total,(float)time /CLOCKS_PER_SEC);
    if (circles->total != 7){
        exit(-1);
    }
    WriteCircles(circles);
}

int main(int argc, char** argv)
{
    if(argc >1 && strcmp(argv[1], "test") == 0){
        printf("Testing CircleDetection\n\n");
        test();
        return 0;
    }
    CvSeq* circles = DetectCircles(argv[1]);
    WriteCircles(circles);
    ShowCircles(circles);
    waitKey(0);
    return 0;
}
