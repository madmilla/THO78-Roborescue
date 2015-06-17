/**
*               __
*    _________ / /_  ____  ________  ____________  _____
*   /___/ __ \/ __ \/ __ \/ ___/ _ \/ ___/ ___/ / / / _ \
*  / / / /_/ / /_/ / /_/ / /  /  __(__  ) /__/ /_/ /  __/
* /_/  \____/_.___/\____/_/   \___/____/\___/\__,_/\___/
*
*
* @file PX4FlowWrapper
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

#include "mavlink.h"

/**
* PX4FlowWrapper is a class that is used to get useful data from the PX4Flow. The messages sent by the PX4Flow have to be forwarded to this class, which will then interpret it and calculate the position in the room based on those messages. The PX4FlowWrapper on its own can't provide an accurate absolute position. Therefore, the PX4Flow has to be calibrated on the fly, by calling both the setPosition and the setHeading functions. Calibrating it should allow for accurate positioning for the next while, but the more often they get called the more accurate the system will be.
*/
class PX4FlowWrapper{
public:
	PX4FlowWrapper();
	
	/**
	* @brief ReceiveMAVLinkMessage is called to let the PX4FlowWrapper handle a message.
	*
	* @param msg mavlink_message_t to let handled by the PX4FlowWrapper.
	**/
	void ReceiveMAVLinkMessage(mavlink_message_t* msg);
	
	/**
	* @brief Sets the absolute position.
	*
	* This function is used to set the absolute position. The PX4FlowWrapper will use this position to calculate the future positions. This function has to be called regularly to make sure the PX4FlowWrapper values don't drift.
	*
	*@param x is the absolute x in the room.
	*@param y is the absolute y in the room.
	*/
	void setPosition(double x, double y);
	
	/**
	* @brief Sets the absolute heading.
	*
	* This function is used to set the absolute heading. The PX4FlowWrapper will use this heading to calculate the future positions. This function has to be called regularly to make sure the PX4FlowWrapper values don't drift.
	*
	*@param headingInDegrees is the heading the PX4Flow is aiming at.
	*/
	void setHeading(double headingInDegrees);
	
	/**
	* Returns the X in the room according to the PX4FlowWrapper.
	*
	* @return the X in the room.
	*/
	float getX();
	
	/**
	* Returns the Y in the room according to the PX4FlowWrapper.
	*
	* @return the Y in the room.
	*/
	float getY();
	
	/**
	* Returns the heading of the PX4Flow according to the PX4FlowWrapper.
	*
	* @return the heading of the PX4Flow in degrees.
	*/
	double getHeadingInDegrees();
private:
	float x=0.f,y=0.f;
	float heading=0;
};