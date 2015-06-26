/**
*                __
*    _________  / /_  ____  ________  ____________  _____
*   / ___/ __ \/ __ \/ __ \/ ___/ _ \/ ___/ ___/ / / / _ \
*  / /  / /_/ / /_/ / /_/ / /  /  __(__  ) /__/ /_/ /  __/
* /_/   \____/_.___/\____/_/   \___/____/\___/\__,_/\___/
*
*
* @file 			QuadcopterController.h
* @date Created:	19-06-2015
*
*  @author	Jos Roijakkers
*  @author	Daan Leijen
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

#ifndef _QUADCOPTERCONTROLLER_H
#define _QUADCOPTERCONTROLLER_H
#include "Quadcopter.h"
#include "XYLocalisationModule.h"
#include "Coordinate.h"

class XYLocalisationModule;

class QuadcopterController
{
public:
	/**
	* QuadcopterController constructor
	* @param quadcopter a quadcopter reference
	* @param locMod a localisationModule reference
	*/
	QuadcopterController(Quadcopter& quadcopter, XYLocalisationModule& locMod);
	/**
	* setTarget sets a target destination
	* @param target a target coordinate
	* @param targetHeight a float used for indicating the target height
	*/
	void setTarget(Coordinate<double> target, float targetHeight);
	/**
	* setPosition sets the latest registered position as position
	* gets the position from the localisation-module
	*/
	void setPosition();
	/**
	* setHeight sets the current height 
	* @param currentHeight a float used for indicating the current height
	*/
	void setHeight(float currentHeight);
	/**
	* moveTowardsTarget a function that allows the quadcopter to move 
	* towards the set target coordinate and height 
	*/
	void moveTowardsTarget();
	/**
	* QuadcopterController default destructor
	*/
	~QuadcopterController();

private:
	/**
	* registeredQuad
	*/
	Quadcopter& registeredQuadcopter;
	/**
	* registeredLocationModule
	*/
	XYLocalisationModule& registeredLocationModule;
	/**
	* recentLocation
	* vector of intergers used for the recent location
	*/
	Coordinate<double> recentLocation;
	/**
	* recentHeight
	* float used to indicate the recentheight
	*/
	float recentHeight;
	/**
	* targetLocation
	* vector of intergers used for the target location
	*/
	Coordinate<double> targetLocation = Coordinate<double>{-1,-1};
	/**
	* targetHeight
	* float default set to -1.0f
	*/
	float targetHeight = -1.0f;
	/**
	* allowedDeviation
	* float default set to 0.2
	*/
	float allowedDeviation = 0.2;
};
#endif
