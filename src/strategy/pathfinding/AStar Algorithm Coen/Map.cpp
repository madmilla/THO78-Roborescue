/**
*               __
*    _________ / /_  ____  ________  ____________  _____
*   /___/ __ \/ __ \/ __ \/ ___/ _ \/ ___/ ___/ / / / _ \
*  / / / /_/ / /_/ / /_/ / /  /  __(__  ) /__/ /_/ /  __/
* /_/  \____/_.___/\____/_/   \___/____/\___/\__,_/\___/
*
*
* @file map.cpp
* @date Created: 6/15/2015
*
* @author Coen Andriessen
*
* @version 1.8
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

#include "Map.h"

const int MAP_WIDTH = 20;
const int MAP_HEIGHT = 20;

int world_map[ MAP_WIDTH * MAP_HEIGHT ] =
{

// 0001020304050607080910111213141516171819
    1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,   // 00
    1,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,1,   // 01
    1,9,9,1,1,9,9,9,1,9,1,9,1,9,1,9,9,9,1,1,   // 02
    1,9,9,1,1,9,9,9,1,9,1,9,1,9,1,9,9,9,1,1,   // 03
    1,9,1,1,1,1,9,9,1,9,1,9,1,1,1,1,9,9,1,1,   // 04
    1,9,1,1,9,1,1,1,1,9,1,1,1,1,9,1,1,1,1,1,   // 05
    1,9,9,9,9,1,1,1,1,1,1,9,9,9,9,1,1,1,1,1,   // 06
    1,9,9,9,9,9,9,9,9,1,1,1,9,9,9,9,9,9,9,1,   // 07
    1,9,1,1,1,1,1,1,1,1,1,9,1,1,1,1,1,1,1,1,   // 08
    1,9,1,9,9,9,9,9,9,9,1,1,9,9,9,9,9,9,9,1,   // 09
    1,9,1,1,1,1,9,1,1,9,1,1,1,1,1,1,1,1,1,1,   // 10
    1,9,9,9,9,9,1,9,1,9,1,9,9,9,9,9,1,1,1,1,   // 11
    1,9,1,9,1,9,9,9,1,9,1,9,1,9,1,9,9,9,1,1,   // 12
    1,9,1,9,1,9,9,9,1,9,1,9,1,9,1,9,9,9,1,1,   // 13
    1,9,1,1,1,1,9,9,1,9,1,9,1,1,1,1,9,9,1,1,   // 14
    1,9,1,1,9,1,1,1,1,9,1,1,1,1,9,1,1,1,1,1,   // 15
    1,9,9,9,9,1,1,1,1,1,1,9,9,9,9,1,1,1,1,1,   // 16
    1,1,9,9,9,9,9,9,9,1,1,1,9,9,9,1,9,9,9,9,   // 17
    1,9,1,1,1,1,1,1,1,1,1,9,1,1,1,1,1,1,1,1,   // 18
    1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,3,   // 19

};

// map helper functions



/**
 * Constructor of Map.
 *
 * @param rosbee
 */

Map::Map(Rosbee *rosbee){
    bool_isLoaded = false;
    this->rosbee = rosbee;
}

/**
 * Destructor of Map.
 */

Map::~Map(){
    // Destructor
}

/**
 * Function to set tile in map. X and Y where the tile is on the map,
 * value what kind of tile it is.
 *
 * @param x
 * @param y
 * @param value
 */

void Map::setTile(int x, int y, const char * value){
    myMap[x][y] = value;
}

/**
 * Function to get tile in map. X and Y to search which tile must be returned.
 *
 * @param x
 * @param y
 * @return myMap[x][y]
 */

int Map::getTile(int x, int y){
    if(x < 0 || x > 19 || y < 0 || y > 19){
        return 9;
    }else{
        return atoi(myMap[x][y].c_str());
    }

}

/**
 * Function to check if the map is full scanned. For all the tiles in myRoute,
 * will be checked if they are connect to a tile what isnt scanned.
 */

bool Map::isMapFullScanned(){
    // Loop through vector.
    for(auto &i : myRoute ) {
        // Checks if tile is connected to a tile what isnt scanned.
        if(isTileConnectedScanned(i.first, i.second) == false){
            return false;
        }else{
            continue;
        }
    }
    return true;
}

/**
 * Function to check if the location of the rosbee is changed. When the location is changed,
 * the old location will be stored in myRoute.
 */

void Map::rosbeeLocationChanged(){
    // Check if the location of the rosbee is changed.
    if(rosbee->isLocationChanged()){
        // Set tile where to rosbee was on isScanned.
        setTile(rosbee->getOldRosbeeLocationX(), rosbee->getOldRosbeeLocationY(), "1");
        // Create pair temp to store the old rosbee location.
        std::pair <int, int> temp;
        temp.first = rosbee->getOldRosbeeLocationX();
        temp.second = rosbee->getOldRosbeeLocationY();
        // Set the old rosbee location in myRoute.
        myRoute.push_back(temp);
        // Increase steps.
        numberOfSteps++;
    }
}

/**
 * Function get tile that will be needed in the mid area scan algorithm.
 * First will be check if the tile above the rosbee is free, then right to
 * the rosbee, then left to the rosbee and last down to the rosbee. When there
 * is no tile available the last tile out myRoute will be returned.
 * Param x and y to search for tile location.
 *
 * @param x
 * @param y
 * @return tileLocation
 */

int * Map::getTileForMidAlgorithm(int x, int y){
    // Create temp to save tile location.
    static int tileLocation[1];
    // Check tile above to the rosbee.
    if(getTile(x, y-1) == 0){
        tileLocation[0] = int(x);
        tileLocation[1] = int(y-1);
    }
    // Check tile right to the rosbee.
    else if(getTile(x+1, y) == 0){
        tileLocation[0] = int(x+1);
        tileLocation[1] = int(y);
    }
    // Check tile left to the rosbee.
    else if(getTile(x-1, y) == 0){
        tileLocation[0] = int(x-1);
        tileLocation[1] = int(y);
    }
    // Check tile below to the rosbee.
    else if(getTile(x, y+1) == 0){
        tileLocation[0] = int(x);
        tileLocation[1] = int(y+1);
    }
    // When the rosbee is stuck.
    else{
        // Get size of myRoute.
        int i = myRoute.size()-1;
        // Last tile of myRoute.
        tileLocation[0] = int(myRoute[i-1].first);
        tileLocation[1] = int(myRoute[i-1].second);
        // Remove tile out myRoute.
        myRoute.pop_back();
        myRoute.pop_back();
    }
    return tileLocation;
}

/**
 * Function to check if the tile is connected to a tile what is not scanned.
 * Param x and y to search for tile location.
 *
 * @param x
 * @param y
 */

bool Map::isTileConnectedScanned(int x, int y){
    // Check if tile left to the tile is scanned.
    if(getTile(x-1, y) == 0){
        return false;
    }
    // Check if tile right to the tile is scanned.
    else if(getTile(x+1, y) == 0){
        return false;
    }
    // Check if tile above to the tile is scanned.
    else if(getTile(x, y-1) == 0){
        return false;
    }
    // Check if tile below to the tile is scanned.
    else if(getTile(x, y+1) == 0){
        return false;
    }else{
        return true;
    }
}

/**
 * Function to check if the map is loaded.
 *
 * @return bool_isLoaded
 */

bool Map::isLoaded(){
    return bool_isLoaded;
}

/**
 * Function to get the number of steps.
 *
 * @return numberOfSteps
 */

int Map::getNumberOfSteps(){
    return numberOfSteps;
}

/**
 * Function to choose the map. Random number will be create to
 * choose a map.
 *
 * @return pathMap
 */

const char * Map::chooseMap(){
    srand(static_cast<unsigned int>(time(0)));
    int random = rand() % 5;
    switch(5){
        case 1:
            return pathMap1;
            break;
        case 2:
            return pathMap2;
            break;
        case 3:
            return pathMap3;
            break;
        case 4:
            return pathMap4;
            break;
        default:
            return pathMap5;
            break;
    }

}

/**
 * Function to load the map by filename.
 *
 * @param filename
 */

void Map::loadMap(const char * filename){
    int xLength = 0;
    int yLength = 0;
    ifstream file(filename, ifstream::binary);
    file.seekg(0, file.end);
    // Store length of file.
    int length = file.tellg();
    file.seekg(0, file.beg);
    // Create buffer for file.
    char * buffer = new char[length];
    // Store data of file in buffer.
    file.read(buffer, length);
    file.close();
    // Loop through buffer.
    for(int i = 0; i < int(strlen(buffer)); i++){
        // Store character at i in buffer in character.
        char character = char(buffer[i]);
        // When xLength is 20 set xLength on 0 and increase yLength by 1.
        if(xLength == 20){
            xLength = 0;
            yLength = yLength + 1;
        }
        // Check for correct input.
        if(character == '0' || character == '3' || character == '2'){
            // Create tile with value of character.
            setTile(xLength, yLength, &character);
            xLength = xLength + 1;
        }/*
        if(character == 'Q'){
            for(int henk = (i + 1); henk < (i + 6); henk++){
            temp += buffer[henk];
            std::cout << temp << std::endl;
            }*/
       // }
    }
    // Set rosbee location.
    rosbee->setRosbeeLocationX(19);
    rosbee->setRosbeeLocationY(19);
    // Set loaded on true.
    bool_isLoaded = true;
    std::cout << "map loaded" << std::endl;
}

int Map::henk(){
    return 9;
}

int Map::GetMap( int x, int y )
{
    if( x < 0 ||
        x >= MAP_WIDTH ||
         y < 0 ||
         y >= MAP_HEIGHT
      )
    {
        return 9;
    }
    //std::cout << world_map[(y*MAP_WIDTH)+x] << std::endl;
    //std::cout << getTile(0,0) << std::endl;
    return world_map[(y*MAP_WIDTH)+x];
}
