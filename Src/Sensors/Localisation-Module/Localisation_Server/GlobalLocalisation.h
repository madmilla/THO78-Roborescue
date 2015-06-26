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

#ifndef GLOBAL_LOCALISATION_H
#define GLOBAL_LOCALISATION_H

#include <iostream>
#include <fstream>
#include <sstream>
#include "aruco.h"
#include "Coordinate.h"
#include <opencv2/highgui/highgui.hpp>
#include <unistd.h>
#include "ARInterface.h"

using namespace cv;
using namespace aruco;

class GlobalLocalisation
{
private:	
	
	/**
	* ARDetectorX, ARDetectorY
	* The detector classes for the X and the Y camera's
	*/
	ARInterface ARDetectorX, ARDetectorY;

	/**
	* getClosestId()
	* getClosestId a function for retreiving the closest id tag (to the center)
	* in the list of markers
	*/
	int getClosestId(vector<Marker> &theMarkers, int halfWidthCamera);	

	/**
	* initializeDrivers()
	* Initializes the drivers (basically resets them with other parameters)
	*/
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
	* an integer used to indicate the current coordinates
	* starts at -1,-1 which indicates no coordinate has been found yet
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
	* hasGui
	* Boolean value that indicates if the class should output a GUI or not.
	* The GUI can be seen through a screen with HDMI or through X11 forwarding/
	* VNC
	*/
	bool hasGui;

	/**
	* theInputImageCopyX, theInputImageCopyY
	* Images for keeping copies of the input images in - used for drawing the 
	* AR tag outline on in the GUI mode
	*/	
	Mat theInputImageCopyX, theInputImageCopyY;

public:
	/**
	* GlobalLocalisation()
	* the constructor for GlobalLocalisation opens the video_devices and 
	* optionally creates the GUI
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
