/**
*               __
*    _________ / /_  ____  ________  ____________  _____
*   /___/ __ \/ __ \/ __ \/ ___/ _ \/ ___/ ___/ / / / _ \
*  / / / /_/ / /_/ / /_/ / /  /  __(__  ) /__/ /_/ /  __/
* /_/  \____/_.___/\____/_/   \___/____/\___/\__,_/\___/
*
*
* @file VirtualRosbee.cpp
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

#include "virtualRosbee.h"

/**
 * Constructor of VirtualRosbee.
 */

virtualRosbee::virtualRosbee(int x, int y,Rosbee* actual):
rActual{actual}
{
	// Set x location.
	this->virtualRosbeeLocationX = x;
	// Set y location.
	this->virtualRosbeeLocationY = y;
}


/**
 * Destructor of VirtualRosbee.
 */

virtualRosbee::~virtualRosbee() {
    // Destructor
}

/**
 * Function to return the VirtualRosbee location x.
 */

int virtualRosbee::getVirtualRosbeeLocationX() {
	return virtualRosbeeLocationX;
}

/**
 * Function to return the virtualrosbee location y.
 * @return rosbeeLocationY
 */

int virtualRosbee::getVirtualRosbeeLocationY() {
    return virtualRosbeeLocationY;
}

/**
 * Function to set the virtualrosbee location x.
 */

void virtualRosbee::setVirtualRosbeeLocationX(int x) {
    virtualRosbeeLocationX = x + virtualRosbeeLocationX;
}

/**
 * Function to set the VirtualRosbee location y.
 */

void virtualRosbee::setVirtualRosbeeLocationY(int y) {
    virtualRosbeeLocationY = y + virtualRosbeeLocationY;
}

/**
* Function to get flank of the actual Rosbee.
*/

int virtualRosbee::getVirtualRosbeeFlank() {
    return rActual->getFlank();
}

/**
* Function to move the VirtualRosbee to location x - y.
*/

void virtualRosbee::moveTo(int x, int y) {
	while(!rActual->needsWaypoint()){}
	//rActual->heading
	rActual->sendWaypoint(x,y);
	std::cout << "Rosbee move to: " << x << " , " << y << std::endl;
}




