/**
*               __
*    _________ / /_  ____  ________  ____________  _____
*   /___/ __ \/ __ \/ __ \/ ___/ _ \/ ___/ ___/ / / / _ \
*  / / / /_/ / /_/ / /_/ / /  /  __(__  ) /__/ /_/ /  __/
* /_/  \____/_.___/\____/_/   \___/____/\___/\__,_/\___/
*
*
* @file VirtualQuadCopter.h
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

#ifndef VIRTUALQUADCOPTER_H
#define VIRTUALQUADCOPTER_H

#include "dimension.h"

class VirtualQuadCopter
{
public:
	/**
	* @fn	VirtualQuadCopter(Dimension size, Dimension fov, int x, int y);
	*
	* @brief	Constructor of the class VirtualQuadCopter.
	*
	* @param	size
	* @param	fov
	* @param	x
	* @param	y
	*/
    VirtualQuadCopter(Dimension size, Dimension fov, int x, int y);
	/**
	* @fn	~VirtualQuadCopter();
	*
	* @brief	Destructor of the class VirtualQuadCopter.
	*
	*/
    ~VirtualQuadCopter();
	/**
	* @fn	void goTo(int x, int y);
	*
	* @brief	Function to move the VirtualQuadCopter to location x and y.
	*
	* @param	x
	* @param	y
	*/
    void goTo(int x, int y);
    bool inView(int x, int y);
    /**
	* @fn	Dimension getSize();
	*
	* @brief	Function to get size of Dimension.
	*
	* @return	size
	*/
	Dimension getSize() { return size; };
	/**
	* @fn	Dimension getFov();
	*
	* @brief	Function to get fov of Dimension.
	*
	* @return	fov
	*/
	Dimension getFov() { return fov; };
	/**
	* @fn	int getX();
	*
	* @brief	Function to get x location of VirtualQuadCopter.
	*
	* @return	x
	*/
	int getX() { return x; };
	/**
	* @fn	int getY();
	*
	* @brief	Function to get y location of VirtualQuadCopter.
	*
	* @return	y
	*/
	int getY() { return y; };
	/**
	* @fn	void setSize(Dimension size);
	*
	* @brief	Function to set size of Dimension.
	*
	* @param	size
	*/
	void setSize(Dimension size) { this->size = size; };
	/**
	* @fn	void setFov(Dimension fov);
	*
	* @brief	Function to set fov of Dimension.
	*
	* @param	fov
	*/
	void setFov(Dimension fov) { this->fov = fov; };
	/**
	* @fn	void setX(int x);
	*
	* @brief	Function to set x location of VirtualQuadCopter.
	*
	* @param	x
	*/
	void setX(int x) { this->x = x; };
	/**
	* @fn	void setXY(int y);
	*
	* @brief	Function to set y location of VirtualQuadCopter.
	*
	* @param	y
	*/
	void setY(int y) { this->y = y; };
private:
	/**
	* @brief Dimension size. Size of Dimension.
	*/
    Dimension size;
	/**
	* @brief Dimension fov. Fov of Dimension.
	*/
    Dimension fov;
	/**
	* @brief int x. X location of VirtualQuadCopter.
	*/
	int x;
	/**
	* @brief int y. Y location of VirtualQuadCopter.
	*/
    int y;
};

#endif // VIRTUALQUADCOPTER_H
