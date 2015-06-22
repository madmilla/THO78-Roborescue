/**
*               __
*    _________ / /_  ____  ________  ____________  _____
*   /___/ __ \/ __ \/ __ \/ ___/ _ \/ ___/ ___/ / / / _ \
*  / / / /_/ / /_/ / /_/ / /  /  __(__  ) /__/ /_/ /  __/
* /_/  \____/_.___/\____/_/   \___/____/\___/\__,_/\___/
*
*
* @file Line.cpp
* @date Created: 29-04-2015
* @version 1.2
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



#include "Line.h"

Line::Line(const Line::Point & begin_pos, const Line::Point & end_pos)	{
	lineData.begin_pos = begin_pos;
	lineData.end_pos = end_pos;
}

Line::~Line(){
}

void Line::setLine(const Line::Point & begin_pos, const Line::Point & end_pos) {
	lineData.begin_pos = begin_pos;
	lineData.end_pos = end_pos;
}
Line::LineData& Line::getLine() {
	return lineData;
}

std::ostream& operator<<(std::ostream & stream, const Line::Point & point) {
	stream << '(' << point.x << ' ' << point.y << ')';
	return stream;
}

std::ostream& operator<<(std::ostream & stream, const Line & line) {
	stream << line.lineData.begin_pos << ' ' << line.lineData.end_pos;
	return stream;
}

bool operator==(const Line::Point & p1, const Line::Point & p2) {
	if (p1.x == p2.x && p1.y == p2.y) {
		return true;
	}
	return false;
}

int Line::getLength() {
	float deltaX = lineData.end_pos.x - lineData.begin_pos.x;
	float deltaY = lineData.end_pos.y - lineData.begin_pos.y;
	return sqrt(pow(deltaX, 2) + pow(deltaY, 2));
}

Line::Point  Line::getFormula() {
	float deltaX = lineData.end_pos.x - lineData.begin_pos.x;
	float deltaY = lineData.end_pos.y - lineData.begin_pos.y;
	float a = deltaY / deltaX;
	float b = this->lineData.begin_pos.y - (a * this->lineData.begin_pos.x);
	return Line::Point{ a, b };
}

bool Line::pointOnLine(Line::Point &p, Line::Point & lineFormula, Line::LineData & data) {
	const int MAX_POINT_ON_LINE_DISTANCE{11 };
	Point C; //Point p projected on the line. Het snijpunt tussen del lijn van punt p tot de lijn.
	float A1 = lineFormula.x;
	float B1 = lineFormula.y; //Y1 = A1x + B1 -> invert naar Y2 = (1/a1) x2 + B2
	float A2 = -1 / A1;
	float B2 = p.y - (A2 * p.x);
	//Y  = A1 X + B1 = A2 X + B2 --> --> --> A1X - A2X  = B2 - B1	 ->>> (A1-A2)X = B2 - B1	 -> --> --> X = (B2 - B1) / A1 - A2
	C.x = (B2 - B1) / (A1 - A2);
	C.y = (A2 * C.x) + B2;

	if (Line(C, p).getLength() <= MAX_POINT_ON_LINE_DISTANCE && (p.x + MAX_POINT_ON_LINE_DISTANCE > data.begin_pos.x) && (p.x - MAX_POINT_ON_LINE_DISTANCE < data.end_pos.x)){
		if (A1 > 0){
			if ((p.y - MAX_POINT_ON_LINE_DISTANCE < data.end_pos.y) && (p.y + MAX_POINT_ON_LINE_DISTANCE > data.begin_pos.y)){
				return true;
			}
			return false;
		}
		else{
			if ((p.y - MAX_POINT_ON_LINE_DISTANCE < data.begin_pos.y) && (p.y + MAX_POINT_ON_LINE_DISTANCE > data.end_pos.y)){
				return true;
			}
			return false;
		}

	}
	return false;
}

int Line::intersect(Line & line2) {
	float line1Length = this->getLength();
	float line2Length = line2.getLength();
	Line::Point abLine1 = this->getFormula();
	Line::Point abLine2 = line2.getFormula();
	if ((this->getLine().begin_pos.x > 200 && this->getLine().end_pos.x < 280 && this->getLine().begin_pos.y < 250) && (line2.getLine().begin_pos.x > 200 && line2.getLine().end_pos.x < 280 && line2.getLine().begin_pos.y < 250)){
	}
	if (this->pointOnLine(this->lineData.begin_pos, abLine2, line2.lineData)){
		if (this->pointOnLine(this->lineData.end_pos, abLine2, line2.lineData)){
			return 100;// Line 1 is 100% on line 2
		}
		else if (this->pointOnLine(line2.lineData.begin_pos, abLine1, this->lineData)){
			if (this->pointOnLine(line2.lineData.end_pos, abLine1, this->lineData)){
				return 100; //Line 2 is for 100% on line 1 ---- the beginning of line 1 and 2 is at the same point
			}
			else{
				float length = Line(line2.lineData.begin_pos, this->lineData.begin_pos).getLength();
				return ((length / line2Length) * 100);
			}
		}
		else if (this->pointOnLine(line2.lineData.end_pos, abLine1, this->lineData)){
			float length = Line(line2.lineData.end_pos, this->lineData.begin_pos).getLength();
			return ((length / line2Length) * 100);

		}
	}
	else if (this->pointOnLine(line2.lineData.begin_pos, abLine1, this->lineData)){
		if (this->pointOnLine(line2.lineData.end_pos, abLine1, this->lineData)){
			return 100;// Line 2 is 100% on line 1
		}
		else if (this->pointOnLine(this->lineData.end_pos, abLine2, line2.lineData)){
			float length = Line(this->lineData.end_pos, line2.lineData.begin_pos).getLength();
			return ((length / line2Length) * 100);
		}
	}
	else if (this->pointOnLine(line2.lineData.end_pos, abLine1, this->lineData)){
		if (this->pointOnLine(line2.lineData.begin_pos, abLine1, this->lineData)){
			float length = Line(this->lineData.end_pos, line2.lineData.end_pos).getLength();
			return ((length / line2Length) * 100);
		}
	}

	return 0;
}
