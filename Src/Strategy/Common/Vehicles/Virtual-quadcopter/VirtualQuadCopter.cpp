/**
*               __
*    _________ / /_  ____  ________  ____________  _____
*   /___/ __ \/ __ \/ __ \/ ___/ _ \/ ___/ ___/ / / / _ \
*  / / / /_/ / /_/ / /_/ / /  /  __(__  ) /__/ /_/ /  __/
* /_/  \____/_.___/\____/_/   \___/____/\___/\__,_/\___/
*
*
* @file VirtualQuadCopter.cpp
* @date Created: 4/28/2015
* @version 1.0
*
* @author Mathijs Arends
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
#include "VirtualQuadCopter.h"

/**
 * Constructor of VirtualQuadCopter.
 */

VirtualQuadCopter::VirtualQuadCopter(Dimension size, Dimension fov, int x, int y):
    size{size},
    fov{fov},
    x{x},
    y{y}
{
	// Constructor.
}

/**
 * Destructor of VirtualLidar.
 */

VirtualQuadCopter::~VirtualQuadCopter(){
	// Destructor.
}

/**
 * Function to move the VirtualQuadCopter to location x and y.
 */

void VirtualQuadCopter::goTo(int x, int y){
	// Set x VirtualQuadCopter.
    this->x = x;
	// Set y VirtualQuadCopter.
    this->y = y;
}
/**
 * Function to move the VirtualQuadCopter to a waypoint.
 */
void VirtualQuadCopter::goTo(WayPoint* waypoint){
    this->x = waypoint->x;
    this->y = waypoint->x;
}

bool VirtualQuadCopter::inView(int x, int y){
    //param x in range of view
    if(((this->x) -(fov.width/2) <= x) && ((this->x) + (fov.width/2) >= x)){
        //param y in range of view
        if(((this->y) - (fov.height/2) <= y) && ((this->y) + fov.height/2) >= y){
            return true;
        }
    }
    return false;
}
