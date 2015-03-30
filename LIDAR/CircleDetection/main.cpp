//First parameter is .txt file with the pixels.
// compiled with: g++ circles.cpp -o circles `pkg-config --cflags --libs opencv`
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <opencv/cv.h>
#include <iostream>
#include <stdio.h>
#include <QVector>
#include <QString>
#include <QFile>
#include <QImage>
#include "time.h"
#include "ctime"
#include <math.h>
#include <QTextStream>
using namespace cv;
void makeImage(QString source, QString output = "output.jpg"){
    QFile file(source);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        printf("File niet gevonden.....\nProgramma wordt afgesloten\n");
        exit(1);
    }

    QTextStream stream(&file);
    QString line = stream.readLine();
    int imageHeight = 0;
    int imageWidth = 0;
    while(!line.isNull()){
        imageHeight++;
        line = stream.readLine();
        if(line.length()> imageWidth){
            imageWidth = line.length();
        }
    }
    Mat * newMat = new Mat(imageWidth,imageHeight,CV_8UC1);
    int x = 0;
    file.seek(0);
    line = stream.readLine();
    while(!line.isNull()){
        int y = 0;
        for(int i = 0; i< imageWidth; i++){
            if(line[i].isNumber()){
                newMat->at<uchar>(Point(y,x)) = 255;
            }
            else{
                newMat->at<uchar>(Point(y,x)) = 0;
            }
            y++;
        }
        line = stream.readLine();
        x++;
    }
    file.close();
    imwrite(output.toStdString(), *newMat);
}
int main(int argc, char** argv)
{
    clock_t Start = clock();
    IplImage* img = NULL;
    makeImage(argv[1]); // transform .txt to .jpg file
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
    cvCvtColor(canny, rgbcanny, CV_GRAY2BGR);
    clock_t end = clock();
    int time = end - Start;
    printf("%d circles detected in %f sec\n", circles->total,(float)time /CLOCKS_PER_SEC);
    for (size_t i = 0; i < circles->total; i++)
    {
         // round the floats to an int
         float* p = (float*)cvGetSeqElem(circles, i);
         cv::Point center(cvRound(p[0]), cvRound(p[1]));
         int radius = cvRound(p[2]);


         // draw the circle center
         cvCircle(rgbcanny, center, 3, CV_RGB(0,255,0), -1, 8, 0 );

         // draw the circle outline
         cvCircle(rgbcanny, center, radius+3, CV_RGB(0,0,255), 2, 8, 0 );

         printf("x: %d y: %d r: %d\n",center.x,center.y, radius);
    }


    //cvNamedWindow("circles", 1);
    //cvShowImage("circles", rgbcanny);

//    cvSaveImage("out2.png", rgbcanny);
//    cvSaveImage("out3.png", canny);
    cvWaitKey(0);

    return 0;
}
