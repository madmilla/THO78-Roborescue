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

Line::~Line() {
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
	//std::cout << "lengthe = " << deltaX << " - " << deltaY << std::endl;
	return sqrt(pow(deltaX, 2) + pow(deltaY, 2));
}

Line::Point Line::getFormula() {
	float deltaX = lineData.end_pos.x - lineData.begin_pos.x;
	float deltaY = lineData.end_pos.y - lineData.begin_pos.y;
	float a = deltaY / deltaX;
	float b = this->lineData.begin_pos.y - (a * this->lineData.begin_pos.x);
	//std::cout << "y = " << a << " x + " << b << std::endl;
	return Line::Point{ a, b };
}

bool Line::pointOnLine(Line::Point &p, Line::Point & lineFormula, Line::LineData & data) {
	const int THRESHHOLD{10 };
	if (data.end_pos.x < data.begin_pos.x){
		std::cout << "er gaat iets mis ik stop: " << data.begin_pos << " - " << data.begin_pos;
		//exit(-1);
	}
	float y = (lineFormula.x * p.x) + lineFormula.y;
	//std::cout << "point on line: " << p.x << " - " << p.y << " - - - " << data.begin_pos.x << " - " << data.end_pos.x << std::endl;
	if (y < (THRESHHOLD + p.y) && y >(p.y - THRESHHOLD) && p.x <= (data.end_pos.x + THRESHHOLD) && p.x > (data.begin_pos.x- THRESHHOLD)) {
		return true;
	}
	return false;
}

int Line::intersect(Line & line2) {
	static int aapje;
	//std::cout << aapje << "\n";
	//aapje++;
	float line1Length = this->getLength();
	float line2Length = line2.getLength();
	Line::Point abLine1 = this->getFormula();
	Line::Point abLine2 = line2.getFormula();
	if ((abLine1.x < 0 && abLine2.x > 0) || (abLine2.x < 0 && abLine1.x>0)){
		//std::cout << aapje << "foutje1:\t\t\t\t" << abLine1.x << " + " << abLine2.x << "\n";
		//return 100;
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
			std::cout << "zie je wel!!!!";
			return ((length / line2Length) * 100);
		}
	}

	return 0;
}