/**
*               __
*    _________ / /_  ____  ________  ____________  _____
*   /___/ __ \/ __ \/ __ \/ ___/ _ \/ ___/ ___/ / / / _ \
*  / / / /_/ / /_/ / /_/ / /  /  __(__  ) /__/ /_/ /  __/
* /_/  \____/_.___/\____/_/   \___/____/\___/\__,_/\___/
*
*
* @file Test.cpp
* @date Created: 6/15/2015
*
* @author Coen Andriessen
*
* @version 1.2
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
 * Constructor of Test.
 *
 * @param map
 */

Test::Test(Map * map){
    this->map = map;
    myfile.open("C:\\Users\\coen__000\\Documents\\TestSystem\\testresults.txt", std::ios::out|std::ios::app);
    writeTimeAndDate();
}

/**
 * Destructor of scanArea.
 */

Test::~Test(){

}

/**
 * Function to run tests before the scanning algorithm is started.
 */

void Test::testsBeforeScanning(){
    writeMap();
    start = std::clock();
}

/**
 * Function to run tests when the scanning algorithm is done.
 */

void Test::testsAfterScanning(){
    duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
    checkFullyScanned();
    writeMap();
    writeNumberOfSteps();
    writeExecuteTime();
    writeEndLine();
}

/**
 * Function to write the time and date in the output file.
 */

void Test::writeTimeAndDate(){
    time_t t = time(0);   // get time now
    struct tm * now = localtime( & t );
    myfile << "Date: " << (now->tm_mday) << "-" << (now->tm_mon +1) << "-" << (now->tm_year + 1900);
    myfile << " Time: " << (now->tm_hour) << ":" << (now->tm_min) << ":" << (now->tm_sec) << "\n";
}

/**
 * Function to write if the map is full scanned in the output file.
 */

void Test::checkFullyScanned(){
    if(map->isMapFullScanned()){
        myfile << "Map is succesfull scanned\n";
    }else{
        myfile << "Map scanned is failed";
    }
}

/**
 * Function to write the loaded or scanned map in the output file.
 */

void Test::writeMap(){
    myfile << "Scanned map:\n";
    for(int iiy = 0; iiy < 20; iiy++){
        for(int iix = 0; iix < 20; iix++){
            myfile << map->getTile(iix, iiy);
            if(iix == 19){
                myfile << "\n";
            }
        }
    }
    myfile << "\n";
}

/**
 * Write number of steps the rosbee has taken in the output file.
 */

void Test::writeNumberOfSteps(){
    myfile << "Number of steps: " << map->getNumberOfSteps() << "\n";
}

/**
 * Write end line of the test.
 */

void Test::writeEndLine(){
    for(int i = 0; i < 150; i++){
        myfile << "=";
    }
    myfile << "\n";
}

/**
 * Write run time of algorithm in the output file.
 */

void Test::writeExecuteTime(){
    myfile << "Time: " << duration << "\n";
}
