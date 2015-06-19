/**
*               __
*    _________ / /_  ____  ________  ____________  _____
*   /___/ __ \/ __ \/ __ \/ ___/ _ \/ ___/ ___/ / / / _ \
*  / / / /_/ / /_/ / /_/ / /  /  __(__  ) /__/ /_/ /  __/
* /_/  \____/_.___/\____/_/   \___/____/\___/\__,_/\___/
*
*
* @file Line.h
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
#ifndef LINE_H
#define LINE_H

#include <iostream>
#include <math.h>
#include <cmath>
#include <stdlib.h>

class Line
{
public:	
	//! Data structure for origins
	/*!
	The data structure for the origins X and Y
	*/
	struct Point {
		float x;
		float y;
	};
private:
	//! Data structure for the line coordinates
	/*!
	The data structure for the origins X and Y
	*/
	struct LineData {
		Point begin_pos;
		Point end_pos;
	};
	LineData lineData;

	

public:
	//! The Contructor for the Lidar
	/*!
	Initialize the line with the struct Point begin position and the struct Point end position
	@param begin_pos: set the begin position of the line 
	@param end_pos: Set the end position of the line
	*/
	Line(const Point & begin_pos, const Point & end_pos);
	~Line();
	
	//! The setter for the line object
	/*!
	set new values for the line object
	@param begin_pos: set the new begin position of the line
	@param end_pos: set the new end position of the line 
	*/
	void setLine(const Point & begin_pos, const Point & end_pos);
	//! The getter for the line object
	/*!
	get the values of the line object
	@return struct lineData: With the line data (struct Point begin_pos, struct Point end_pos)
	*/
	LineData& getLine();

	//! operator for printing points
	/*!
	print a specifiek point to the console
	*/
	friend std::ostream& operator<<(std::ostream & stream, const Point & point);
	//! operator for printing all line information
	/*!
	print all the line information to the console
	*/
	friend std::ostream& operator<<(std::ostream & stream, const Line & line);
	//! operator for checking if 2 Points are the same
	/*!
	check if 2 Points are the same
	*/
	friend bool operator==(const Point & p1, const Point & p2);

	int getLength();
	int intersect(Line & line2);
	Line::Point getFormula();
	bool pointOnLine(Line::Point &p, Line::Point & lineFormula, Line::LineData & data);
};
#endif

