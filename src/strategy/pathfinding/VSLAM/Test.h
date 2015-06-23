/**
*               __
*    _________ / /_  ____  ________  ____________  _____
*   /___/ __ \/ __ \/ __ \/ ___/ _ \/ ___/ ___/ / / / _ \
*  / / / /_/ / /_/ / /_/ / /  /  __(__  ) /__/ /_/ /  __/
* /_/  \____/_.___/\____/_/   \___/____/\___/\__,_/\___/
*
*
* @file Test.h
* @date Created: 6/21/2015
* @version 1.0
*
* @author Coen Andriessen
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

#ifndef TEST_H
#define TEST_H

#include "map.hpp"
#include <iostream>
#include <fstream>
#include <cstdio>
#include <ctime>
#include "mapLogicVSLAM.h"
#include "Rosbee.h"

class Test
{
public:
	/**
	* @fn	Test(map * Map, mapLogicVSLAM *MapLogicVSLAM, Rosbee * rosbee);
	*
	* @brief	Constructor of the class Test.
	*
	* @param	map * Map
	* @param	mapLogicVSLAM *MapLogicVSLAM
	*/
	Test(map * Map, mapLogicVSLAM *MapLogicVSLAM, Rosbee * rosbee);
	/**
	* @fn	~Test();
	*
	* @brief	Constructor of the class Test.
	*/
    ~Test();
	/**
	* @fn	void checkFullyScanned();
	*
	* @brief	Function to check if the map is succesfull scanned and write the output to the file of testresults.
	*/
    void checkFullyScanned();
	/**
	* @fn	void writeTimeAndDate();
	*
	* @brief	Function to write the time and date to the file of testresults.
	*/
    void writeTimeAndDate();
	/**
	* @fn	void writeMap();
	*
	* @brief	Function to write the map to the file of testresults.
	*/
    void writeMap();
	/**
	* @fn	 void writeEndLine();
	*
	* @brief	Function to write a endline to the file of testresults.
	*/
    void writeEndLine();
	/**
	* @fn	 void writeExecuteTime();
	*
	* @brief	Function to write the execute time to the file of testresults.
	*/
    void writeExecuteTime();
	/**
	* @fn	 void startTests();
	*
	* @brief	Function to write start the test for the VSLAM algorithm.
	*/
	void startTests();
	/**
	* @fn	 void writeNumberOfSteps();
	*
	* @brief	Function to write the steps taken by the rosbee to the file of testresults.
	*/
	void writeNumberOfSteps();
	/**
	* @fn	 void setObjectsInMap();
	*
	* @brief	Function to set objects in map for testing.
	*/
	void setObjectsInMap();
	/**
	* @fn	 void writeAmountObjects();
	*
	* @brief	Function to write the amount of objects in the map to the file of testresults.
	*/
	void writeAmountObjects();
private:
	/**
	* @brief Map object.
	*/
    map * Map;
	/**
	* @brief MapLogicVSLAM object.
	*/
	mapLogicVSLAM *MapLogicVSLAM;
	/**
	* @brief Rosbee object.
	*/
	Rosbee * rosbee;
	/**
	* @brief std::ofstream myfile object. Output file for testresults.
	*/
    std::ofstream myfile;
	/**
	* @brief std::clock_t start object. Start time of the program.
	*/
    std::clock_t start;
	/**
	* @brief double duration variable. Time of the duration of the program.
	*/
    double duration;
	/**
	* @brief int numberOfObjects variable. How many objects will be in the map.
	*/
	int numberOfObjects = rand() % 80;
};

#endif // TEST_H
