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

#include "aruco.h"
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace cv;
using namespace aruco;

class ARInterface {
public:	
	ARInterface(bool hasGui = false, double thres1 = 7, double thres2 = 7);
	vector<Marker> detectMarkers(Mat inputImage);
	int getIdFromImage(Mat* image);
	Mat getThresholdedImage();
	
private:
	/**
	* markerDetector
	* creates a markerDetector
	*/
	MarkerDetector markerDetector;
	double thresParam1, thresParam2;
	
	CameraParameters theCameraParameters;
	
	/**
	* thePyrDownLevel
	* interger used to indicate the current pyrdownlevel
	*/
	int thePyrDownLevel = 0;
	/**
	* theMarkerSizeX, theMarkerSizeY
	* floats used to indicate the marker size for video_deviceX and video_deviceY
	*/
	float theMarkerSize;
	
	bool hasGui;
	
};

#endif