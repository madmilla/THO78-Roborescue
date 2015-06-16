/**
*               __
*    _________ / /_  ____  ________  ____________  _____
*   /___/ __ \/ __ \/ __ \/ ___/ _ \/ ___/ ___/ / / / _ \
*  / / / /_/ / /_/ / /_/ / /  /  __(__  ) /__/ /_/ /  __/
* /_/  \____/_.___/\____/_/   \___/____/\___/\__,_/\___/
*
*
* @file scanArea.cpp
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

#include "scanArea.h"


/**
 * Constructor of scanArea.
 *
 * @param map
 * @param rosbee
 */

scanArea::scanArea(Map *map, Rosbee *rosbee){
    // Constructor
    this->map = map;
    this->rosbee = rosbee;
}

/**
 * Destructor of scanArea.
 */

scanArea::~scanArea(){
    // Destructor
}


/**
 * Function to start the scanMidAlgorithm.
 */

void scanArea::run(){
    if(map->isLoaded()){
        scanMidAlgorithm(rosbee->getRosbeeLocationX(), rosbee->getRosbeeLocationY());
    }
}

/**
 * Function to scan the room.
 *
 * @param x
 * @param y
 * @return tileLocation
 * @return scanMidAlgorithm()
 */

int * scanArea::scanMidAlgorithm(int x, int y){
    // Temp to store location.
    int * tileLocation;
    // Get tile that is needed for the algorithm.
    tileLocation = map->getTileForMidAlgorithm(x, y);
    // Set rosbee location to the tile location what is stored in tileLocation.
    rosbee->setRosbeeLocationX(tileLocation[0]);
    rosbee->setRosbeeLocationY(tileLocation[1]);
    // Check if the rosbeelocation is changed.
    map->rosbeeLocationChanged();
    // Check if the map is full scanned. When this is true the algorithm can stop.
    // When it is false call the function with the new rosbee location.
    if(map->isMapFullScanned() == true){
        return tileLocation;
    }else{
        return scanMidAlgorithm(tileLocation[0], tileLocation[1]);
    }
}


