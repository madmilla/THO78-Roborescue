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
#include "headers/aruco.h"
#include "Coordinate.h"
#include <opencv2/highgui/highgui.hpp>
using namespace cv;
using namespace aruco;

class ARInterface
{
private:
	static const int VIDEO_DEVICE_X = 0;
	static const int VIDEO_DEVICE_Y = 1;
	
	Coordinate<int> currentCoordinate;
	bool newCoordinate;
	bool errorOnInit;
	
	std::string error;
	
	int halfWidthCameraX, halfWidthCameraY;
	float theMarkerSizeX;
	float theMarkerSizeY;
	int thePyrDownLevel;
	
	MarkerDetector markerDetectorX;
	MarkerDetector markerDetectorY;
	VideoCapture theVideoCapturerX;
	VideoCapture theVideoCapturerY;
	vector<Marker> theMarkersX;
	vector<Marker> theMarkersY;
	Mat theInputImageX;
	Mat theInputImageY;
	
	CameraParameters theCameraParametersX;
	CameraParameters theCameraParametersY;

	double thresParam1, thresParam2;
	
	int getClosestId(vector<Marker> &theMarkers, int halfWidthCamera)
	{
		if (theMarkers.size()>0)
		{
			int currentClosestId = -1;
			float currentClosestX = 1000;

			for (unsigned int i = 0; i<theMarkers.size(); i++)
			{
				float xValueTotal = 0;
				//Add all the x values of the 4 points
				for (int j = 0; j < 4; j++)
				{
					xValueTotal += theMarkers[i][j].x;
				}	
				//Divide the values by 4 to get the average, and substract
				//That from the middle point of the image; this way we get
				//The distance from the middle
				int distance = abs(halfWidthCameraX - (int)(xValueTotal / 4));
				
				//Get the closest distance from all the markers
				if (distance < currentClosestX)
				{
					currentClosestId = theMarkers[i].id;
					currentClosestX = distance;
				}
			}			
			return currentClosestId;
		}
		return -1;
	}
public:
	ARInterface() :
		newCoordinate {false},
		errorOnInit { false},
		error {""},
		theMarkerSizeX { -1},
		theMarkerSizeY { -1}	
	{
		//Open the camera's
		theVideoCapturerX.open(VIDEO_DEVICE_X);
		theVideoCapturerY.open(VIDEO_DEVICE_Y);

		//Check video is open
		if (!theVideoCapturerX.isOpened() || !theVideoCapturerY.isOpened())
		{
			cerr << "Could not open video" << endl;
			errorOnInit = true;
			error += " Could not open video devices";
		}
		//Read first image to get the dimensions of the image
		theVideoCapturerX >> theInputImageX;
		theVideoCapturerY >> theInputImageY;

		//Get the half of the width of the images
		cv::Size sizeX = theInputImageX.size();
		halfWidthCameraX = sizeX.width / 2;
		
		cv::Size sizeY = theInputImageY.size();
		halfWidthCameraY = sizeY.width / 2;

		//Configure other parameters
		if (thePyrDownLevel>0)
		{
			markerDetectorX.pyrDown(thePyrDownLevel);
			markerDetectorY.pyrDown(thePyrDownLevel);
		}
		
		markerDetectorX.getThresholdParams(thresParam1, thresParam2);
		markerDetectorX.setCornerRefinementMethod(MarkerDetector::SUBPIX);
		markerDetectorY.getThresholdParams(thresParam1, thresParam2);
		markerDetectorY.setCornerRefinementMethod(MarkerDetector::SUBPIX);
	}
	
	void run()
	{
		while(1)
		{
			theVideoCapturerX.grab();
			theVideoCapturerY.grab();

			theVideoCapturerX.retrieve(theInputImageX);
			theVideoCapturerY.retrieve(theInputImageY);

			markerDetectorX.detect(theInputImageX, theMarkersX,
				theCameraParametersX, theMarkerSizeX);
			markerDetectorY.detect(theInputImageY, theMarkersY,
				theCameraParametersY, theMarkerSizeY);

			int closestIdX = getClosestId(theMarkersX, halfWidthCameraX);
			if (closestIdX != -1)
			{
				if(currentCoordinate.getX() != closestIdX)
				{
					currentCoordinate.setX(closestIdX);
					newCoordinate = true;
				}
			}
		
			int closestIdY = getClosestId(theMarkersY, halfWidthCameraY);
			if (closestIdY != -1)
			{
				if(currentCoordinate.getY() != closestIdY)
				{
					currentCoordinate.setY(closestIdY);
					newCoordinate = true;
				}
			}
		}
	}	

	Coordinate<int> getCoordinate()
	{
		newCoordinate = false;
		return currentCoordinate;
	}


	bool isNewCoordinate()
	{
		return newCoordinate;
	}
};
#endif