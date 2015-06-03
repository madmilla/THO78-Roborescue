#ifndef AR_INTERFACE_H
#define AR_INTERFACE_H

#include <iostream>
#include <fstream>
#include <sstream>
#include "aruco.h"
#include "cvdrawingutils.h"
#include <opencv2/highgui/highgui.hpp>
using namespace cv;
using namespace aruco;

class ARInterface
{
	public:
		ARInterface()
		{
			//read from camera or from  file
    
			TheVideoCapturerX.open(0);
			TheVideoCapturerY.open(1);
			
			//check video is open
			if (!TheVideoCapturerX.isOpened() || !TheVideoCapturerY.isOpened()) 
			{
				cerr << "Could not open video" << endl;
				//return -1;
			}
			//read first image to get the dimensions
			TheVideoCapturerX >> TheInputImageX;
			TheVideoCapturerY >> TheInputImageY;
			
			cv::Size sx = TheInputImageX.size();
			cout << "xw: " << sx.width <<endl ;
			cout << "xh: " << sx.height << endl;			
			
			cv::Size sy = TheInputImageY.size();
			cout << "yw: " << sy.width <<endl ;
			cout << "yh: " << sy.height << endl;
			
			//Configure other parameters
			if (ThePyrDownLevel>0)
			{
				MDetectorX.pyrDown(ThePyrDownLevel);
				MDetectorY.pyrDown(ThePyrDownLevel);
			}
			//DISPLAY
			//cv::namedWindow("in",1);
			//cv::namedWindow("in2",1);
			
			MDetectorX.getThresholdParams( ThresParam1,ThresParam2);       
			MDetectorX.setCornerRefinementMethod(MarkerDetector::SUBPIX);
			MDetectorY.getThresholdParams( ThresParam1, ThresParam2);
			MDetectorY.setCornerRefinementMethod(MarkerDetector::SUBPIX);
		}
		
		int getCurrentX();
		
		int getCurrentY();
		
		bool isNewXValue();
		bool isNewYValue();
		
		void run()
		{
			TheVideoCapturerX.grab();
			TheVideoCapturerY.grab();
			
			TheVideoCapturerX.retrieve( TheInputImageX);
			TheVideoCapturerY.retrieve( TheInputImageY);

			MDetectorX.detect(TheInputImageX, TheMarkersX, 
				TheCameraParametersX, TheMarkerSizeX);
			MDetectorY.detect(TheInputImageY, TheMarkersY, 
				TheCameraParametersY, TheMarkerSizeY);	
			
			TheInputImageX.copyTo(TheInputImageCopyX);
			TheInputImageY.copyTo(TheInputImageCopyY);
			
			if(TheMarkersX.size()>0)
			{			
				cout << "Camera X" << endl;
			}
			for (unsigned int i=0;i<TheMarkersX.size();i++) 
			{
				cout << "id: " << TheMarkersX[i].id << " ";
				for (int j=0;j<4;j++)
				{
					cout <<"("<< TheMarkersX[i][j].x << ") ";
				}
				cout << endl;			
				
				//DISPLAY
				//TheMarkersX[i].draw(TheInputImageCopyX,Scalar(0,0,255),1);
			}
			
			if(TheMarkersY.size()>0)
			{
				cout << "Camera Y" << endl;
			}
			for (unsigned int i=0;i<TheMarkersY.size();i++) 
			{
				cout << "id: " << TheMarkersY[i].id << " ";
				for (int j=0;j<4;j++)
				{
					cout <<"("<< TheMarkersY[i][j].x << ") ";
				}
				cout << endl;
				
				//DISPLAY
				//TheMarkersY[i].draw(TheInputImageCopyY,Scalar(0,0,255),1);
			}
			
			//DISPLAY
			//cv::imshow("in",TheInputImageCopyX);
			//cv::imshow("in2",TheInputImageCopyY);
		}
	
	private:
		int currentX;
		int currentY;
		bool newXValue = false;
		bool newYValue = false;
		
		float TheMarkerSizeX=-1;
		float TheMarkerSizeY=-1;
		int ThePyrDownLevel;
		MarkerDetector MDetectorX;
		MarkerDetector MDetectorY;
		VideoCapture TheVideoCapturerX;
		VideoCapture TheVideoCapturerY;
		vector<Marker> TheMarkersX;
		vector<Marker> TheMarkersY;
		Mat TheInputImageX;
		Mat TheInputImageY;
		
		//DISPLAY
		//Mat TheInputImageCopyX, TheInputImageCopyY;
		CameraParameters TheCameraParametersX;
		CameraParameters TheCameraParametersY;

		double ThresParam1,ThresParam2;
};

#endif