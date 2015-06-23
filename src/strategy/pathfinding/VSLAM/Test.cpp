/**
*               __
*    _________ / /_  ____  ________  ____________  _____
*   /___/ __ \/ __ \/ __ \/ ___/ _ \/ ___/ ___/ / / / _ \
*  / / / /_/ / /_/ / /_/ / /  /  __(__  ) /__/ /_/ /  __/
* /_/  \____/_.___/\____/_/   \___/____/\___/\__,_/\___/
*
*
* @file Test.cpp
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

#include "Test.h"

/**
* Constructor of VSLAM.
*/

Test::Test(map * Map, mapLogicVSLAM *MapLogicVSLAM, Rosbee * rosbee){
	start = std::clock();
	this->Map = Map;
	this->MapLogicVSLAM = MapLogicVSLAM;
	this->rosbee = rosbee;
    myfile.open("C:\\Users\\coen__000\\Documents\\Visual Studio 2013\\Projects\\VSLAM\\VSLAM\\Testresults\\testresults.txt", std::ios::out|std::ios::app);
}

/**
* Destructor of VSLAM.
*/

Test::~Test(){
	// Destructor
}

/**
 * Function to write start the test for the VSLAM algorithm.
 */

void Test::startTests(){
	writeTimeAndDate();
	checkFullyScanned();
	writeMap();
	writeNumberOfSteps();
	writeExecuteTime();
	writeAmountObjects();
	writeEndLine();
}

/**
* Function to write the time and date to the file of testresults.
*/

void Test::writeTimeAndDate(){
	// Get time now
    time_t t = time(0);
    struct tm * now = localtime( & t );
	// Write date to the file.
    myfile << "Date: " << (now->tm_mday) << "-" << (now->tm_mon +1) << "-" << (now->tm_year + 1900);
	// Write time to the file.
    myfile << " Time: " << (now->tm_hour) << ":" << (now->tm_min) << ":" << (now->tm_sec) << "\n\n";
}

/**
 * Function to check if the map is succesfull scanned and write the output to the file of testresults.
 */

void Test::checkFullyScanned(){
	// Check if the map is succesfull scanned.
	if (MapLogicVSLAM->isMapFullyScanned()){
		// Write to the file.
		myfile << "Map is succesfull scanned" << "\n\n";
	}
	else{
		// Write to the file.
		myfile << "Map is not succesfull scanned" << "\n\n";
	}
}

/**
 * Function to write the map to the file of testresults.
 */

void Test::writeMap(){
	// Write to the file.
    myfile << "Scanned map:\n";
	// Loops trough the whole map for each tile write value to the file.
	for (int i = 0; i < Map->getScaledWidth(); i++){
		for (int ii = 0; ii < Map->getScaledHeight(); ii++){
			myfile << Map->getScaledLocationValue(ii, i);
		}
		myfile << "\n";
	}
    myfile << "\n";
	// Write width and height of the map to the file.
	myfile << "Size map: " << Map->getScaledWidth() << " x " << Map->getScaledHeight() << "\n\n";
}

/**
* Function to write the steps taken by the rosbee to the file of testresults.
*/

void Test::writeNumberOfSteps(){
	// Write to the file.
	myfile << "Steps taken by rosbee: ";
	int steps = 0;
	// Loops trough the whole map for each tile check if the tile is equals to 3.
	// When the tile is equals to 3 amount steps by 1.
	for (int i = 0; i < Map->getScaledWidth(); i++){
		for (int ii = 0; ii < Map->getScaledHeight(); ii++){
			if (Map->getScaledLocationValue(ii, i) == 3){
				steps++;
			}
		}
	}
	// Write steps to the file.
	myfile << steps << "\n\n";
}

/**
 * Function to write a endline to the file of testresults.
 */

void Test::writeEndLine(){
    for(int i = 0; i < 150; i++){
        myfile << "=";
    }
    myfile << "\n";
}

/**
 * Function to write the execute time to the file of testresults.
 */

void Test::writeExecuteTime(){
	// Calculate execute time.
	duration = (std::clock() - start) / (double)CLOCKS_PER_SEC;
	// Write execute time to the file.
    myfile << "Execute time: " << duration <<  "seconds. \n";
}

/**
* Function to set objects in the map.
*/

void Test::setObjectsInMap(){
	for (int i = 0; i < numberOfObjects; i++){
		int v1 = rand() % Map->getScaledWidth();
		int v2 = rand() % Map->getScaledHeight();
		if (rosbee->getRosbeeLocationX() == v1 && rosbee->getRosbeeLocationY() == v2){
		}
		else{
			Map->setScaledLocationValue(v1, v2, 9);
		}
	}
}

/**
* Function to write amount of objects in the map to the file of testresults.
*/

void Test::writeAmountObjects(){
	myfile << "Amount of objects: " << numberOfObjects << "\n\n";
}

