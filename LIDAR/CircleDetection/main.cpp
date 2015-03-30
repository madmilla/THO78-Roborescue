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
void makeImage(std::string source, std::string output = "output.jpg"){
    std::ifstream file(source);
    if (!file.is_open()){
        printf("File niet gevonden.....\nProgramma wordt afgesloten\n");
        exit(-1);
    }
    std::string line;
    int imageHeight = 0;
    int imageWidth = 0;
    while(getline(file,line)){
        imageHeight++;
        if(line.length()> imageWidth){
            imageWidth = line.length();
        }
    }
    Mat * newMat = new Mat(imageWidth,imageHeight,CV_8UC1);
    int x = 0;
    file.clear();
    file.seekg(0,file.beg);
    while(getline(file,line)){
        int y = 0;
        for(int i = 0; i< imageWidth; i++){
            char ch = line[i];
            if(isdigit(ch)){
                newMat->at<uchar>(Point(y,x)) = 255;
            }
            else{
                newMat->at<uchar>(Point(y,x)) = 0;
            }
            y++;
        }
        x++;
    }
    file.close();
    imwrite(output, *newMat);
}
void WriteCircles(CvSeq * circles, std::string outputName = "output.txt"){
    std::ofstream output(outputName, std::ofstream::out);
    if (!output.is_open()){
        printf("File niet gevonden.....\nProgramma wordt afgesloten\n");
        exit(-1);
    }
    output << "(X,Y)    \tRadius\n";
    for (size_t i = 0; i < circles->total; i++)
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
    IplImage * image;
    if ((image = cvLoadImage("output.jpg"))== 0)
    {
        printf("File niet gevonden.....\nProgramma wordt afgesloten\n");
        exit(-1);
    }
    for (size_t i = 0; i < circles->total; i++)
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

CvSeq * DetectCircles(std::string sourceName){
    IplImage* img = NULL;
    makeImage(sourceName); // transform .txt to .jpg file
    if ((img = cvLoadImage("output.jpg"))== 0)
    {
        printf("cvLoadImage failed\n");
    }

    IplImage* gray = cvCreateImage(cvGetSize(img), IPL_DEPTH_8U, 1);
    CvMemStorage* storage = cvCreateMemStorage(0);

    cvCvtColor(img, gray, CV_BGR2GRAY);

    // This is done so as to prevent a lot of false circles from being detected
    cvSmooth(gray, gray, CV_GAUSSIAN, 7, 7);

    IplImage* canny = cvCreateImage(cvGetSize(img),IPL_DEPTH_8U,1);
    IplImage* rgbcanny = cvCreateImage(cvGetSize(img),IPL_DEPTH_8U,3);
    cvCanny(gray, canny, 50, 100, 3);

    CvSeq* circles = cvHoughCircles(gray, storage, CV_HOUGH_GRADIENT, 1, gray->height/6, 145, 19);
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
