/**
*               __
*    _________ / /_  ____  ________  ____________  _____
*   /___/ __ \/ __ \/ __ \/ ___/ _ \/ ___/ ___/ / / / _ \
*  / / / /_/ / /_/ / /_/ / /  /  __(__  ) /__/ /_/ /  __/
* /_/  \____/_.___/\____/_/   \___/____/\___/\__,_/\___/
*
*
* @file VirtualATV.h
* @date Created: 4/28/2015
* @version 1.0
*
* @author Mathijs Arends
* @author Jeroen Steendam
* @author Jacob Visser
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

#ifndef VIRTUALATV_H
#define VIRTUALATV_H

#include "dimension.h"
#include "waypoint.h"

class VirtualATV{
public:
	/**
	* @fn	VirtualATV(Dimension size, int x, int y);
	*
	* @brief	Constructor of the class VirtualATV.
	*
	* @param	size
	* @param	x
	* @param	y
	*/
    VirtualATV(Dimension size, int x, int y);
	/**
	* @fn	void goTo(int x, int y);
	*
	* @brief	Function to move the VirtualATV to position x and y.
	*
	* @param	x
	* @param	y
	*/
    void goTo(int x, int y);
	/**
	* @fn	void goTo(WayPoint* waypoint);
	*
	* @brief	Function to move the VirtualATV to position x and y.
	*
	* @param	waypoint
	*/
    void goTo(WayPoint* waypoint);
	/**
	* @fn	Dimension getSize();
	*
	* @brief	Function to get size of Dimension.
	*
	* @return	size
	*/
    Dimension getSize() { return size; }
	/**
	* @fn	int getX();
	*
	* @brief	Function to get x of VirtualATV.
	*
	* @return	x
	*/
    int getX() { return x; }
	/**
	* @fn	int getY();
	*
	* @brief	Function to get y of VirtualATV.
	*
	* @return	y
	*/
    int getY() { return y; }
	/**
	* @fn	void setSize(Dimension size);
	*
	* @brief	Function to set size of Dimension.
	*
	* @param	size
	*/
    void setSize(Dimension size) { this->size = size; }
	/**
	* @fn	void setX();
	*
	* @brief	Function to set x of VirtualATV.
	*
	* @param	x
	*/
    void setX(int x) { this->x = x; }
	/**
	* @fn	void setY();
	*
	* @brief	Function to set y of VirtualATV.
	*
	* @param	y
	*/
    void setY(int y) { this->y = y; }
private:
	/**
	* @brief size object.
	*/
    Dimension size;
	/**
	* @brief x variable. X location of VirtualATV.
	*/
    int x;
	/**
	* @brief y variable. Y location of VirtualATV.
	*/
    int y;
};

#endif //VIRTUALATV_H
