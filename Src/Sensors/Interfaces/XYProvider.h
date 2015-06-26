/**
*               __
*    _________ / /_  ____  ________  ____________  _____
*   /___/ __ \/ __ \/ __ \/ ___/ _ \/ ___/ ___/ / / / _ \
*  / / / /_/ / /_/ / /_/ / /  /  __(__  ) /__/ /_/ /  __/
* /_/  \____/_.___/\____/_/   \___/____/\___/\__,_/\___/
*
*
* @file Image
* @date Created: 6-16-2015
*
* @author Daniël van den Berg
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

class XYProvider{
public:
	/**
	* Returns the X in the room according to this XYProvider.
	*
	* @return the X in the room.
	*/
	double getX();
	
	/**
	* Returns the Y in the room according to this XYProvider..
	*
	* @return the Y in the room.
	*/
	double getY();
	
	/**
	* @brief Sets the absolute position.
	*
	* This function is used to set the absolute position. The XYProvider will use this position to calculate the future positions. This function has to be called regularly to prevent value drift.
	*
	*@param x is the absolute x in the room.
	*@param y is the absolute y in the room.
	*/
	void calibrate(double x, double y);
	
	/**
	* @brief Sets the absolute X.
	*
	* This function is used to set the absolute X. The XYProvider will use this position to calculate the future positions. This function has to be called regularly to prevent value drift.
	*
	*@param x is the absolute x in the room.
	*/
	void calibrateX(double x);
	
	/**
	* @brief Sets the absolute Y.
	*
	* This function is used to set the absolute Y. The XYProvider will use this position to calculate the future positions. This function has to be called regularly to prevent value drift.
	*
	*@param y is the absolute y in the room.
	*/
	void calibrateY(double y);
protected:
	double x,y;
};
