/**
*                __
*    _________  / /_  ____  ________  ____________  _____
*   / ___/ __ \/ __ \/ __ \/ ___/ _ \/ ___/ ___/ / / / _ \
*  / /  / /_/ / /_/ / /_/ / /  /  __(__  ) /__/ /_/ /  __/
* /_/   \____/_.___/\____/_/   \___/____/\___/\__,_/\___/
*
*
* @file 			ARInterface.h
* @date Created:	03/06/2015
*
*  @author	- Feiko Wielsma
*  @author	- Jos Roijakkers
*
*  @section LICENSE
*  License:	newBSD
*
*  Copyright © 2015, HU University of Applied Sciences Utrecht.
* 		All rights reserved.
*
*
*
*	Redistribution and use in source and binary forms,
*	with or without modification, are permitted provided that
*	the following conditions are met:
*	- Redistributions of source code must retain the above copyright notice,
*	  this list of conditions and the following disclaimer.
*	- Redistributions in binary form must reproduce the above copyright notice,
*	  this list of conditions and the following disclaimer in the documentation
*	  and/or other materials provided with the distribution.
*	- Neither the name of the HU University of Applied Sciences Utrecht
*	  nor the names of its contributors may be used to endorse or
*	  promote products derived from this software without
*	  specific prior written permission.
*
*   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
*   "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING,
*	BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY
*	AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
*	IN NO EVENT SHALL THE HU UNIVERSITY OF APPLIED SCIENCES UTRECHT
*   BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
*   CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
*	PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
*	OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
*	OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
*	(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
*	OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
**/

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

		cv::Size sizeX = TheInputImageX.size();
		cout << "xw: " << sizeX.width << endl;
		cout << "xh: " << sizeX.height << endl;

		halfWidthCameraX = sizeX.width / 2;

		cv::Size sizeY = TheInputImageY.size();
		cout << "yw: " << sizeY.width << endl;
		cout << "yh: " << sizeY.height << endl;

		halfWidthCameraY = sizeY.width / 2;

		//Configure other parameters
		if (ThePyrDownLevel>0)
		{
			MDetectorX.pyrDown(ThePyrDownLevel);
			MDetectorY.pyrDown(ThePyrDownLevel);
		}
		//DISPLAY
		//cv::namedWindow("in",1);
		//cv::namedWindow("in2",1);

		MDetectorX.getThresholdParams(ThresParam1, ThresParam2);
		MDetectorX.setCornerRefinementMethod(MarkerDetector::SUBPIX);
		MDetectorY.getThresholdParams(ThresParam1, ThresParam2);
		MDetectorY.setCornerRefinementMethod(MarkerDetector::SUBPIX);
	}

	int getCurrentX()
	{
		return currentX;
	}

	int getCurrentY()
	{
		return currentY;
	}

	bool isNewXValue()
	{
		if (newXValue)
		{
			newXValue = false;
			return true;
		}
		return false;
	}

	bool isNewYValue()
	{
		if (newYValue)
		{
			newYValue = false;
			return true;
		}
		return false;
	}

	void run()
	{
		TheVideoCapturerX.grab();
		TheVideoCapturerY.grab();

		TheVideoCapturerX.retrieve(TheInputImageX);
		TheVideoCapturerY.retrieve(TheInputImageY);

		MDetectorX.detect(TheInputImageX, TheMarkersX,
			TheCameraParametersX, TheMarkerSizeX);
		MDetectorY.detect(TheInputImageY, TheMarkersY,
			TheCameraParametersY, TheMarkerSizeY);

		//TheInputImageX.copyTo(TheInputImageCopyX);
		//TheInputImageY.copyTo(TheInputImageCopyY);

		if (TheMarkersX.size()>0)
		{
			//cout << "Camera X" << endl;			

			int currentClosestId = -1;
			float currentClosestX = 1000;

			for (unsigned int i = 0; i<TheMarkersX.size(); i++)
			{
				//cout << "id: " << TheMarkersX[i].id << " ";

				float x = 0;
				for (int j = 0; j<4; j++)
				{
					x += TheMarkersX[i][j].x;
					//cout <<"(" << TheMarkersX[i][j].x ;
					//cout <<"," << TheMarkersY[i][j].y << ") ";
				}
				//cout << endl << " midX: " << x/4 << endl;			

				int distance = abs(halfWidthCameraX - (int)(x / 4));
				//cout << distance << endl;

				if (distance < currentClosestX)
				{
					currentClosestId = TheMarkersX[i].id;
					currentClosestX = distance;
				}

				//DISPLAY
				//TheMarkersX[i].draw(TheInputImageCopyX,Scalar(0,0,255),1);
			}
			if (currentClosestId != -1)
			{
				currentX = currentClosestId;
				newXValue = true;
			}
		}
		if (TheMarkersY.size()>0)
		{
			//cout << "Camera Y" << endl;

			int currentClosestId = -1;
			float currentClosestX = 1000;
			for (unsigned int i = 0; i<TheMarkersY.size(); i++)
			{
				//cout << "id: " << TheMarkersY[i].id << " ";

				float x = 0;
				for (int j = 0; j<4; j++)
				{
					x += TheMarkersY[i][j].x;
					//cout <<"(" << TheMarkersY[i][j].x ;
					//cout <<"," << TheMarkersY[i][j].y << ") ";
				}
				//cout << endl << " midX: " << x/4 << endl;

				int distance = abs(halfWidthCameraY - (int)(x / 4));
				//cout << distance << endl;				

				if (distance < currentClosestX)
				{
					currentClosestId = TheMarkersY[i].id;
					currentClosestX = distance;
				}
				//DISPLAY
				//TheMarkersY[i].draw(TheInputImageCopyY,Scalar(0,0,255),1);
			}
			if (currentClosestId != -1)
			{
				currentY = currentClosestId;
				newYValue = true;
			}
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
	int halfWidthCameraX, halfWidthCameraY;
	float TheMarkerSizeX = -1;
	float TheMarkerSizeY = -1;
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

	double ThresParam1, ThresParam2;
};
#endif