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
#include <unistd.h>

using namespace cv;
using namespace aruco;

class ARInterface
{
private:
	/**
	* VIDEO_DEVICE_X
	* a static const int used for indicating the video deviceX
	*/
	static const int VIDEO_DEVICE_X = 0;
	/**
	* VIDEO_DEVICE_Y
	* a static const int used for indicating the video deviceY
	*/
	static const int VIDEO_DEVICE_Y = 1;
	/**
	* currentCoordinate
	* an interger used to indicate the current coordinates
	*/
	Coordinate<int> currentCoordinate;
	/**
	* newCoordinate
	* boolean used to flag new coordinate received
	*/
	bool newCoordinate;
	/**
	* errorOnInit
	* boolean used to flag an error on initialization
	*/
	bool errorOnInit;
	/**
	* errorInRun
	* boolean used to flag an error in running
	*/
	bool errorInRun;
	/**
	/**
	* error
	* the string that is returned when an error on initialization is encountered
	*/
	std::string error;
	/**
	* halfWidthCameraX, halfWidthCameraY
	* intergers to indicate the half width of cameraX and cameraY
	*/
	int halfWidthCameraX, halfWidthCameraY;
	/**
	* theMarkerSizeX, theMarkerSizeY
	* floats used to indicate the marker size for video_deviceX and video_deviceY
	*/
	float theMarkerSizeX, theMarkerSizeY;
	/**
	* thePyrDownLevel
	* interger used to indicate the current pyrdownlevel
	*/
	int thePyrDownLevel;
	/**
	* markerDetectorX
	* creates makerDetectorX for video_deviceX
	*/
	MarkerDetector markerDetectorX;
	/**
	* markerDetectorY
	* creates makerDetectorY for video_deviceY
	*/
	MarkerDetector markerDetectorY;
	/**
	* theVideoCapturerX
	* creates theVideoCapturerX for video_deviceX
	*/
	VideoCapture theVideoCapturerX;
	/**
	* theVideoCapturerY
	* creates theVideoCapturerY for video_deviceY
	*/
	VideoCapture theVideoCapturerY;
	/**
	* theMarkersX
	* creates a vector to contain all the X markers
	*/
	vector<Marker> theMarkersX;
	/**
	* theMarkersY
	* creates a vector to contain all the Y markers
	*/
	vector<Marker> theMarkersY;
	/**
	* theInputImageX
	* creates a theImputImageX mat image 
	*/
	Mat theInputImageX;
	/**
	* theInputImageY
	* creates a theImputImageY mat image
	*/
	Mat theInputImageY;
	/**
	* theCameraParametersX
	* creates theCameraParametersX
	*/
	CameraParameters theCameraParametersX;
	/**
	* theCameraParametersY
	* creates theCameraParametersY
	*/
	CameraParameters theCameraParametersY;
	/**
	* thresParam1,thresParam2
	* creates the doubles thresParam1 and thresParam2 used for the threshold
	*/
	double thresParam1, thresParam2;
	/**
	* getClosetId()
	* getClosetId a function for retreiving the closest id tag (to the center)
	* in the list of markers
	*/
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
	/**
	* ARInterface()
	* the constructor for ARInterface opens the video_devices
	*/
	ARInterface() :
		newCoordinate {false},
		errorOnInit { false},
		error {""},
		theMarkerSizeX { -1},
		theMarkerSizeY { -1}	
	{
		if(geteuid() != 0)
		{			
			error += "Program requires root (sudo) to reset video drivers with different parameters!";
			errorOnInit = true;
			return;
		}
		std::cout << "Disabling video driver" << std::endl;
		std::system("sudo rmmod uvcvideo");
		std::cout << "Enabling video driver with timeout parameter" << std::endl;
		std::system("sudo modprobe uvcvideo nodrop=1 timeout=2000");
		//Open the camera's
		theVideoCapturerX.open(VIDEO_DEVICE_X);
		theVideoCapturerY.open(VIDEO_DEVICE_Y);

		//Check video is open
		if (!theVideoCapturerX.isOpened())
		{
			errorOnInit = true;
			error += " Could not open video device X";
			return;
		}
		if (!theVideoCapturerY.isOpened())
		{
			error += " Could not open video device Y";
			errorOnInit = true;
			return;
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
		std::cout << "Ending constructor" << std::endl;
	}
	
	/**
	* run() is the the method that will be called by the user of ARInterface.
	* It will grab the images from the webcams, and runs the marker detection on
	* those images.
	* If a new coordinate is found in a marker, it will also set
	* the 'newCoordinate' bool on true, which can be accessed through
	* isNewCoordinate().
	* run() is usually used in a seperate thread.
	*/
	void run()
	{
		while (1)
		{
			//Grabs the X and Y images (otherwise .retrieve() will always 
			// return the same image)
			if(!theVideoCapturerX.grab())
			{
				error += " Cannot grab image from X camera";
				errorInRun = true;
			}
			cout << "GX." << ends;
			cout.flush();
			if(!theVideoCapturerY.grab())
			{
				error += " Cannot grab image from Y camera";
				errorInRun = true;
			}
			cout << "GY " << ends;
			cout.flush();

			//Retrieves the images and puts them in theInputImages
			if(!theVideoCapturerX.retrieve(theInputImageX))
			{
				error += " Cannot retrieve image from X camera";
				errorInRun = true;
			}
			cout << "RX." << ends;
			cout.flush();
			if(!theVideoCapturerY.retrieve(theInputImageY))
			{
				error += " Cannot retrieve image from Y camera";
				errorInRun = true;
			}
			cout << "RY " << ends;
			cout.flush();

			//Detects markers in the images, and puts them in theMarkers
			markerDetectorX.detect(theInputImageX, theMarkersX,
				theCameraParametersX, theMarkerSizeX);
			cout << "MX." << ends;
			cout.flush();
			markerDetectorY.detect(theInputImageY, theMarkersY,
				theCameraParametersY, theMarkerSizeY);
			cout << "MY " << ends;
			cout.flush();

			//Gets the closest marker to the center of the image
			//getClosestId can return -1 if it didn't find anything,
			//so we need to test if it isn't -1, and after that check if 
			//the new coordinate isn't the same as it already is
			int closestIdX = getClosestId(theMarkersX, halfWidthCameraX);
			if (closestIdX != -1)
			{
				//if (currentCoordinate.getX() != closestIdX)
				//{
					currentCoordinate.setX(closestIdX);
					newCoordinate = true;
				//}
			}

			int closestIdY = getClosestId(theMarkersY, halfWidthCameraY);
			if (closestIdY != -1)
			{
				//if (currentCoordinate.getY() != closestIdY)
				//{
					currentCoordinate.setY(closestIdY);
					newCoordinate = true;
				//}
			}
			cout << endl << flush;
		}
	}

	/**
	* getCoordinate() returns the current coordinate of the localization system.
	* It returns an <int> Coordinate, with X and Y attributes for the current
	* position.
	*
	*/
	Coordinate<int> getCoordinate()
	{
		newCoordinate = false;
		return currentCoordinate;
	}

	/**
	* isNewCoordinate() is called by the user of ARInterface to determine if there
	* is a new coordinate available. Iif it is, getCoordinate() is usually
	* called.
	* It returns a bool.
	*
	*/
	bool isNewCoordinate()
	{
		return newCoordinate;
	}
	
	bool isErrorOnInit()
	{
		return errorOnInit;
	}
	
	bool isErrorInRun()
	{
		return errorInRun;
	}
	
	std::string getErrorString()
	{
		return error;
	}
};
#endif
