/**
*               __
*    _________ / /_  ____  ________  ____________  _____
*   /___/ __ \/ __ \/ __ \/ ___/ _ \/ ___/ ___/ / / / _ \
*  / / / /_/ / /_/ / /_/ / /  /  __(__  ) /__/ /_/ /  __/
* /_/  \____/_.___/\____/_/   \___/____/\___/\__,_/\___/
*
*
* @file Map.h
* @date Created: 6/15/2015
*
* @author Coen Andriessen
*
* @version 1.5
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

#ifndef MAP_H
#define MAP_H

#include <iostream>
#include <Rosbee.h>
#include <string>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <vector>
#include <ctime>

using namespace std;

class Map
{
public:
    // Constructor of map.
    Map(Rosbee * rosbee);
    // Destructor of map.
    ~Map();
    // Function to set a tile in the map.
    void setTile(int x, int y, const char * value);
    // Function to get a tile in the map.
    int getTile(int x, int y);
    // Function to check if the rosbee location is changed.
    void rosbeeLocationChanged();
    // Function to get a specify tile for the scanning algorithm.
    int * getTileForMidAlgorithm(int x, int y);
    // Function to check if the map is loaded.
    bool isLoaded();
    // Function to check if the map is full scanned.
    bool isMapFullScanned();
    // Function to check if the tile is connected to a tile which is not scanned.
    bool isTileConnectedScanned(int x, int y);
    // Function to load a map from a textfile.
    void loadMap(const char * filename);
    // Function to choose a map from storage.
    const char * chooseMap();
    // Function to get number of steps.
    int getNumberOfSteps();
    int GetMap( int x, int y );
    int henk();
    int blockWidth;
    int blockHeight;

protected:
    Rosbee * rosbee;
private:
    bool bool_isLoaded;
    string myMap[20][20];
    vector <std::pair<int, int>> myRoute;
    const char * pathMap1 = "C:\\Users\\coen__000\\Documents\\TestSystem\\Map1.txt";
    const char * pathMap2 = "C:\\Users\\coen__000\\Documents\\TestSystem\\Map2.txt";
    const char * pathMap3 = "C:\\Users\\coen__000\\Documents\\TestSystem\\Map3.txt";
    const char * pathMap4 = "C:\\Users\\coen__000\\Documents\\TestSystem\\Map4.txt";
    const char * pathMap5 = "C:\\Users\\coen__000\\Documents\\TestSystem\\Map5.txt";
    int numberOfSteps = 0;
};

#endif // MAP_H
