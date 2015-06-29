/**
*               __
*    _________ / /_  ____  ________  ____________  _____
*   /___/ __ \/ __ \/ __ \/ ___/ _ \/ ___/ ___/ / / / _ \
*  / / / /_/ / /_/ / /_/ / /  /  __(__  ) /__/ /_/ /  __/
* /_/  \____/_.___/\____/_/   \___/____/\___/\__,_/\___/
*
*
* @file Circle.h
* @date Created: 29-4-2015
* @version 1.0
*
* @author Nick Verhaaf
* @author Patrick Schoonheym
*
* @section LICENSE
* License: newBSD
*
* Copyright © 2015, HU University of Applied Sciences Utrecht.
* All rights reserved.
*
* Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:
* - Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
* - Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.
* - Neither the name of the HU University of Applied Sciences Utrecht nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
* "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
* THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
* ARE DISCLAIMED. IN NO EVENT SHALL THE HU UNIVERSITY OF APPLIED SCIENCES UTRECHT
* BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
* CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE
* GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
* HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
* LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT
* OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
**/

#ifndef CIRCLE_H
#define CIRCLE_H

#include "Line.h" 
#include <vector>
#include <math.h>

class Line;

class Circle
{
private:
	//! Position X of the circle in the map
	int originX;

	//! Position Y of the circle in the map
	int originY;

	//! Radius of the circle
	int radius;
	
	//! Data structure for origins
	/*!
		The data structure for the origins X and Y
	*/
	struct circleData {
		int originX;
		int originY;
		int radius;
	};

	//! the offset of the lines around the circle
	const double LINES_OFFSET = 1.25;
	//! the angle step of the lines around the circle
	const int LINES_ANGLE_STEP = 45;
	//! the amount of lines around the circle
	const int LINES_VALUE = 6;

public:
	//! The Contructor for the Lidar
	/*!
		Initialize the Circle with origins X, Y and the radius
		@param originX: Set the position X of the circle in the map
		@param originY: Set the position Y of the circle in the map
		@param radius: Set the radius of the circle
	*/
	Circle(int originX, int originY, int radius);

	//!The default destructor for Circle
	~Circle();

	//! Setter for the circle object
	/*!
		Set new values for the circle object
		@param x: Set new position x
		@param y: Set new position y
		@param r: Set new radius for circle
	*/
	void setCircle(int x, int y, int r);

	//! Getter for the circle object
	/*!
		Return requested data of circle object in a struct
		@return struct circleData: With the circle data (originX, originY, radius)
	*/
	circleData getCircle();
	
	//! Getter for get lines around the circle
	/*!
		Return requested data of lines in a vector
		@return Line vector: With line data
	*/
	 std::vector<Line> getLinesAroundCircle();
};

#endif // CIRCLE_H
