/**
*               __
*    _________ / /_  ____  ________  ____________  _____
*   /___/ __ \/ __ \/ __ \/ ___/ _ \/ ___/ ___/ / / / _ \
*  / / / /_/ / /_/ / /_/ / /  /  __(__  ) /__/ /_/ /  __/
* /_/  \____/_.___/\____/_/   \___/____/\___/\__,_/\___/
*
*
* @file virtualRosbee.h
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

#ifndef ROSBEE_H
#define ROSBEE_H

#include <iostream>

class virtualRosbee
{
public:
	/**
	* @fn	virtualRosbee(int x, int y);
	*
	* @brief	Constructor of the class virtualRosbee.
	*
	* @param	int x
	* @param	int y
	*/
	virtualRosbee(int x, int y);
	/**
	* @fn	~virtualRosbee();
	*
	* @brief	Destructor of the class virtualRosbee.
	*/
	~virtualRosbee();
	/**
	* @fn	int getVirtualRosbeeLocationX();
	*
	* @brief	Function that returns the x location of the virtualRosbee.
	*
	* @return	int rosbeeLocationX
	*/
    int getVirtualRosbeeLocationX();
	/**
	* @fn	int getVirtualRosbeeLocationY();
	*
	* @brief	Function that returns the y location of the virtualRosbee.
	*
	* @return	int rosbeeLocationY
	*/
    int getVirtualRosbeeLocationY();
	/**
	* @fn	void set RosbeeLocationY();
	*
	* @brief	Function that set the y location of the virtualRosbee.
	*/
    void setVirtualRosbeeLocationY(int y);
	/**
	* @fn	void set RosbeeLocationX();
	*
	* @brief	Function that set the x location of the virtualRosbee.
	*/
    void setVirtualRosbeeLocationX(int x);
	/**
	* @fn	void moveTo(int x, int y);
	*
	* @brief	Function to move the virtualrosbee to location x and y.
	*
	* @param	int x
	* @param	int y
	*/
	void moveTo(int x, int y);
private:
	/**
	* @brief int rosbeeLocationX variable to save virtualrosbee location x.
	*/
    int rosbeeLocationX;
	/**
	* @brief int rosbeeLocationY variable to save virtualrosbee location y.
	*/
    int rosbeeLocationY;
};

#endif // ROSBEE_H
