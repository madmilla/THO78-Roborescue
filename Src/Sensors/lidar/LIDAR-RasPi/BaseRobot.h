/**
*               __
*    _________ / /_  ____  ________  ____________  _____
*   /___/ __ \/ __ \/ __ \/ ___/ _ \/ ___/ ___/ / / / _ \
*  / / / /_/ / /_/ / /_/ / /  /  __(__  ) /__/ /_/ /  __/
* /_/  \____/_.___/\____/_/   \___/____/\___/\__,_/\___/
*
*
* @file Socket
* @date Created: 27-5-2015
*
* @author Hamza ait Messaoud
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

#ifndef BASEROBOT_H_
#define BASEROBOT_H_

#include "roborescueV1/mavlink.h"
#include <queue>


//! \author@ Hamza ait Messaoud<hamza.aitmessaoud@student.hu.nl>
//! \class@ BaseRobot
//! \brief the base class for a Robot, this has the virtual function which need to be overwritten by other Robots like Lidar or Rosbee
class BaseRobot{
public:
	/// brief default constructor
	BaseRobot():systemID{0}{}

	//! \brief The function onMessage() will be called by the UDPClient. This function determine what to do with the recieved message.
	//! The message must first be decoded from the default mavlink_message_t to an mavlink_ralcp_t.
	//! \param[function] the recieved function
	virtual void onMessage(mavlink_message_t & function) = 0;

	//! \brief Get the messageQueue of the baseRobot
	//! \Return@ The message Queue
	std::queue<mavlink_message_t> * getMessageQueue(){return &messages;}

	//! \Returns the ID of the system
	int getSystemID(){return systemID;}

protected:

	//! \brief The function sendCommand pushes a message in the message Queue.
	//! This function can be used to send a message to the CPI.
	//! \param[payload] The payload for the mavlink message
	//! \param[dest] The destination for the mavlink message
	//! \param[rlcf] The function id for the mavlink message
	template<typename T>
	void sendCommand(mavlink_command_long_t payload, T rlcf){
		messages.push(encodeCommandLongMessage(payload, rlcf ));
	}

	//! \brief The function encodeCommandLongMessage encodes an mavlink_lidar_message_t to an mavlink_message_t
	//! \param[payload] The payload for the mavlink message
	//! \param[dest] The destination for the mavlink message
	//! \param[rlcf] The function for the mavlink message
	//! \Return@ Returns the encoded mavlink_message_t message
	template<typename T>
	mavlink_message_t encodeCommandLongMessage(mavlink_command_long_t command, T rlcf){

		mavlink_message_t mavlinkMessage;
		command.command = rlcf;
		command.target_system = COMMAND_DESTINATION::LIDAR;

		mavlink_msg_command_long_encode(systemID, COMMAND_DESTINATION::LIDAR, &mavlinkMessage, &command);

		return mavlinkMessage;
	}

	//! \brief The function decodeCommandLongMessage decodes an mavlink_message_t to an mavlink_command_long_t
	//! param[mavlinkMessage] The message that needs to be decoded
	//! \Return@ Returns the decoded mavlink_lidar_message_t message
	mavlink_command_long_t decodeCommandLongMessage(mavlink_message_t & mavlinkMessage){
		mavlink_command_long_t mavlinkCommandLong;
		mavlink_msg_command_long_decode(&mavlinkMessage, &mavlinkCommandLong);

		return mavlinkCommandLong;
	}

	std::queue<mavlink_message_t> messages;
	int systemID;
	mavlink_command_long_t message;
};

#endif /* BASEROBOT_H_ */
