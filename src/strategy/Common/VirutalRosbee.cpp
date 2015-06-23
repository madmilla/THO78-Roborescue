/**
*               __
*    _________ / /_  ____  ________  ____________  _____
*   /___/ __ \/ __ \/ __ \/ ___/ _ \/ ___/ ___/ / / / _ \
*  / / / /_/ / /_/ / /_/ / /  /  __(__  ) /__/ /_/ /  __/
* /_/  \____/_.___/\____/_/   \___/____/\___/\__,_/\___/
*
*
* @file Rosbee.cpp
* @date Created: 4/28/2015
*
* @author Coen Andriessen
* @author Jeroen Steendam
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
#include "VirutalRosbee.h"


/**
 * Constructor of Rosbee.
 */
VirutalRosbee::VirutalRosbee() {
    // Constructor
}

/**
 * Destructor of Map.
 */
VirutalRosbee::~VirutalRosbee() {
    // Destructor
}

/**
 * Function to check if the rosbee location is changed. When it is changed
 * the location will be stored in the old rosbee location.
 */
bool VirutalRosbee::isLocationChanged() {
    if(rosbeeLocationX == oldRosbeeLocationX && rosbeeLocationY == oldRosbeeLocationY){
        return false;
    }else{
        oldRosbeeLocationX = rosbeeLocationX;
        oldRosbeeLocationY = rosbeeLocationY;
        return true;
    }
}

/**
 * Function to return the rosbee location x.
 * @return rosbeeLocationX
 */
int VirutalRosbee::getRosbeeLocationX() {
	return this->rosbeeLocationX;
}

/**
 * Function to return the rosbee location y.
 * @return rosbeeLocationY
 */
int VirutalRosbee::getRosbeeLocationY() {
    return rosbeeLocationY;
}

/**
 * Function to return the old rosbee location x.
 * @return oldRosbeeLocationx
 */
int VirutalRosbee::getOldRosbeeLocationX() {
    return oldRosbeeLocationX;
}

/**
 * Function to return the old rosbee location y.
 * @return oldRosbeeLocationY
 */
int VirutalRosbee::getOldRosbeeLocationY() {
    return oldRosbeeLocationY;
}

/**
 * Function to set the rosbee location x.
 *
 * @param x
 */
void VirutalRosbee::setRosbeeLocationX(int x) {
    rosbeeLocationX = x + rosbeeLocationX;
}

/**
 * Function to set the rosbee location y.
 *
 * @param y
 */
// Set value for rosbeeLocationY.
void VirutalRosbee::setRosbeeLocationY(int y) {
    rosbeeLocationY = y + rosbeeLocationY;
}

void VirutalRosbee::moveTo(int x, int y) {
	std::cout << "Rosbee move to: " << x << " , " << y << std::endl;
}




