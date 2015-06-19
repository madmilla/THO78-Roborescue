/**
* __
* _________ / /_ ____ ________ ____________ _____
* /___/ __ \/ __ \/ __ \/ ___/ _ \/ ___/ ___/ / / / _ \
* / / / /_/ / /_/ / /_/ / / / __(__ ) /__/ /_/ / __/
* /_/ \____/_.___/\____/_/ \___/____/\___/\__,_/\___/
*
*
* @file mapFactory.h
* @date Created: 06/18/2015
* @brief A factory class that will read a file and return all the lines from this file
*
* @author Jos Bijlenga
*
* @version 1.0
*
* @section LICENSE
* License: newBSD
*
* Copyright � 2015, HU University of Applied Sciences Utrecht.
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

#pragma once

#include "point.hpp"
#include "line.hpp"
#include "map.hpp"
#include <fstream>
#include <string>

class mapFactory
{
public:

	//! Constructor
	mapFactory();

	//! Destructor
	~mapFactory();

	//! Will return a vector of lines that are present in the map file
	//! @param The address of the map file (pay attention to \\ on windows)
	//! @return A vector of lines with all the lines present in the map file
	std::vector<line> loadMapFromFile(std::string fileAddress);

private:
	//! Will return a line from a linestring read from the map file
	//! @param The line string to be parsed to a line object
	//! @param A line object parsed from the linestring
	line linestringToLine(std::string linestring);

	//! Will return a vector of lines from a objectstring read from the map file
	//! @param The object string to be parsed to multiple line objeccts
	//! @param A vector of lines parsed from the object string
	std::vector<line> objectToLines(std::string object);

	//! Will split a string by the given delimiter
	//! @param The string to be split
	//! @param The delimiter to split the string with
	//! @return A vector of strings split by the delimiter
	std::vector<std::string> splitString(std::string text, char delimiter);

};