/**
*                __
*    _________  / /_  ____  ________  ____________  _____
*   / ___/ __ \/ __ \/ __ \/ ___/ _ \/ ___/ ___/ / / / _ \
*  / /  / /_/ / /_/ / /_/ / /  /  __(__  ) /__/ /_/ /  __/
* /_/   \____/_.___/\____/_/   \___/____/\___/\__,_/\___/
*
*
* @file 			GlobalLocalisation.h
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
#include "Coordinate.h"
#include <opencv2/highgui/highgui.hpp>
#include <unistd.h>

using namespace cv;
using namespace aruco;

class GlobalLocalisation
{
private:	
	/**
	* getClosetId()
	* getClosetId a function for retreiving the closest id tag (to the center)
	* in the list of markers
	*/
	int getClosestId(vector<Marker> &theMarkers, int halfWidthCamera);	

	bool initializeDrivers();

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
	Coordinate<int> currentCoordinate {-1, -1};
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
	float theMarkerSizeX, theMarkerSizeY, theMarkerSizeFlow;
	/**
	* thePyrDownLevel
	* interger used to indicate the current pyrdownlevel
	*/
	int thePyrDownLevel = 0;
	/**
	* markerDetectorX
	* creates markerDetectorX for video_deviceX
	*/
	MarkerDetector markerDetectorX;
	/**
	* markerDetectorY
	* creates markerDetectorY for video_deviceY
	*/
	MarkerDetector markerDetectorY;
	/**
	* markerDetectorFlow
	* creates markerDetectorY for the px4Flow
	*/
	MarkerDetector markerDetectorFlow;
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
	* theMarkersFlow
	* creates a vector to contain all the Flow markers
	*/
	vector<Marker> theMarkersFlow;
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
	* theCameraParametersFlow
	* creates theCameraParametersFlow
	*/
	CameraParameters theCameraParametersFlow;
	/**
	* thresParam1,thresParam2
	* creates the doubles thresParam1 and thresParam2 used for the threshold
	*/
	double thresParam1, thresParam2;
	
	bool hasGui;
	Mat theInputImageCopyX, theInputImageCopyY;
public:
	/**
	* GlobalLocalisation()
	* the constructor for GlobalLocalisation opens the video_devices
	*/
	GlobalLocalisation(bool hasGui = false, double thres1 = 7, double thres2 = 7);
	
	/**
	* run() is the the method that will be called by the user of GlobalLocalisation.
	* It will grab the images from the webcams, and runs the marker detection on
	* those images.
	* If a new coordinate is found in a marker, it will also set
	* the 'newCoordinate' bool on true, which can be accessed through
	* isNewCoordinate().
	* run() is usually used in a seperate thread.
	*/
	void run();
	
	int detectPX4FlowTag();
	
	/**
	* getCoordinate returns the current coordinate of the localization system.
	* It returns an <int> Coordinate, with X and Y attributes for the current
	* position.
	*
	*/
	Coordinate<int> getCoordinate();

	/**
	* isNewCoordinate is called by the user of GlobalLocalisation to determine if there
	* is a new coordinate available. Iif it is, getCoordinate() is usually
	* called.
	* It returns a bool.
	*
	*/
	bool isNewCoordinate();

	/**
	* Returns wether an error in the initialisation (constructor) has occured
	*
	*/
	bool isErrorOnInit();
	
	/**
	* Returns wether an error in the run (run()) has occured 
	*
	*/
	bool isErrorInRun();
	
	/**
	* Returns the error string 
	*
	*/
	std::string getErrorString();
};
#endif
