/**
*               __
*    _________ / /_  ____  ________  ____________  _____
*   /___/ __ \/ __ \/ __ \/ ___/ _ \/ ___/ ___/ / / / _ \
*  / / / /_/ / /_/ / /_/ / /  /  __(__  ) /__/ /_/ /  __/
* /_/  \____/_.___/\____/_/   \___/____/\___/\__,_/\___/
*
*
* @file Test.h
* @date Created: 6/15/2015
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

#include "Map.h"
#include <iostream>
#include <fstream>
#include <cstdio>
#include <ctime>

class Test
{
public:
    // Constructor of test.
    Test(Map * map);
    // Destructor of test.
    ~Test();
    // Function to check and write if the map is full scanned.
    void checkFullyScanned();
    // Function to write the time and date in the output file.
    void writeTimeAndDate();
    // Function to write the loaded and scanned map in the output file.
    void writeMap();
    // Function to start tests that will be runned before the scanning algorithm.
    void testsBeforeScanning();
    // Function to start tests that will be runned after the scanning algorithm.
    void testsAfterScanning();
    // Function to write number of steps what the rosbee has taken by the scanning algorithm.
    void writeNumberOfSteps();
    // Function to write the end line of the tests in the output file.
    void writeEndLine();
    // Function to write the run time of the scanning algorithm in the output file.
    void writeExecuteTime();
private:
    Map * map;
    ofstream myfile;
    std::clock_t start;
    double duration;
};

#endif // TEST_H
