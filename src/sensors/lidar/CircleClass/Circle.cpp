/**
*               __
*    _________ / /_  ____  ________  ____________  _____
*   /___/ __ \/ __ \/ __ \/ ___/ _ \/ ___/ ___/ / / / _ \
*  / / / /_/ / /_/ / /_/ / /  /  __(__  ) /__/ /_/ /  __/
* /_/  \____/_.___/\____/_/   \___/____/\___/\__,_/\___/
*
*
* @file Circle.cpp
* @date Created: 29-4-2015
* @version 1.0
*
* @author Nick Verhaaf
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

#include "Circle.h"

Circle::Circle(int originX, int originY, int radius) :
originX{ originX },
originY{ originY },
radius{ radius }
{}

Circle::~Circle()
{

}

void Circle::setCircle(int x, int y, int r) {
	originX = x;
	originY = y;
	radius = r;
}

Circle::circleData Circle::getCircle() {
	circleData circleData;
	circleData.originX = originX;
	circleData.originY = originY;
	circleData.radius = radius;
	return circleData;
}

std::vector<Line> Circle::getLinesAroundCircle() {
	std::vector<Line> lines;

	int radius = radius * LINES_OFFSET;
	for (int angle = 90; angle < 360; angle += LINES_ANGLE_STEP) {
		Line::Point begin_p, end_p;

		begin_p.x = static_cast<int>(originX + (radius * cos(angle))); //calculate point 1
		begin_p.y = static_cast<int>(originY + (radius * sin(angle)));

		end_p.x = static_cast<int>(originX + (radius * cos(angle + LINES_ANGLE_STEP))); //calculate point 2
		end_p.y = static_cast<int>(originY + (radius * sin(angle + LINES_ANGLE_STEP)));

		if (angle == (360 - LINES_ANGLE_STEP)) {
			end_p.x = lines[LINES_VALUE].getLine().begin_pos.x;
			end_p.y = lines[LINES_VALUE].getLine().begin_pos.y;
		}
		lines.push_back(Line{ begin_p, end_p }); //store line
	}	
	return lines;
}




