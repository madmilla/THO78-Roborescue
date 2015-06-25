/**
*               __
*    _________ / /_  ____  ________  ____________  _____
*   /___/ __ \/ __ \/ __ \/ ___/ _ \/ ___/ ___/ / / / _ \
*  / / / /_/ / /_/ / /_/ / /  /  __(__  ) /__/ /_/ /  __/
* /_/  \____/_.___/\____/_/   \___/____/\___/\__,_/\___/
*
*
* @file RosbeeClient.h
* @date Created: 27-5-2015
*
* @author Rik Buimer, Nathan Schaaphuizen
* @version 1.1
*
* @section LICENSE
* License: newBSD
*
* Copyright © 2015, HU University of Applied Sciences Utrecht.
* All rights reserved.
*
* Redistribution and use in source and binary forms, with or without modification, are permitted provided$
* - Redistributions of source code must retain the above copyright notice, this list of conditions and th$
* - Redistributions in binary form must reproduce the above copyright notice, this list of conditions and$
* - Neither the name of the HU University of Applied Sciences Utrecht nor the names of its contributors m$
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


#ifndef ROSBEECLIENT_H
#define ROSBEECLIENT_H

#include "PracticalSocket.h"
#include <string>
#include "roborescueV1/mavlink.h"


/// @brief Class for communication.
///
/// The class make use of the UDP and Mavlink protocol to receive and send
/// messages to the server.
class RosbeeClient {
private:
	//Socket for UDP.
	UDPSocket sock;
	//Address of the server.
	SocketAddress serverAddr;

public:
	/// @brief Create a new RosbeeClient object.
	///
	/// @param serverAddress IP address of the server.
	/// @param serverPort Port of the server.
	RosbeeClient(const std::string &serverAddress, unsigned short serverPort);

	/// @brief Wait for a message.
	///
	/// This function blocks until a message is received.
	/// @param function Function ID parsed from the Mavelink message.
	/// @param payload Payload parsed from the Mavelink message.
	//void waitReceiveMessage(unsigned char &function, unsigned long long &payload);

	/// @brief Send message.
	///
	/// @param function Function ID that will be included in the Mavlink message.
	/// @param payload Payload that will be included in the Mavlink message.
	//void sendMessage(unsigned char function, unsigned long long payload);

	void sendInit(float x, float y, float angle);

	void sendMessage(unsigned char function, float data[7]);
	
	void requestWaypoint(float x, float y, float angle, float status);

	void waitReceiveMessage(mavlink_command_long_t &packet);



	void sendMessage(
			float param1,
			float param2,
			float param3,
			float param4,
			float param5,
			float param6,
			float param7,
			unsigned short command,
			unsigned char target_system
			){

		mavlink_message_t message;
		mavlink_command_long_t packet;   // = mavlink_command_long_t{std::forward<Args>(args) ...};

		packet.command = command;
		packet.confirmation = 0;
		packet.param1 = param1;
		packet.param2 = param2;
		packet.param3 = param3;
		packet.param4 = param4;
		packet.param5 = param5;
		packet.param6 = param6;
		packet.param7 = param7;
		packet.target_component = 0;
		packet.target_system = target_system;

		mavlink_msg_command_long_encode(COMMAND_DESTINATION::ROSBEE, COMMAND_DESTINATION::ROSBEE, &message, &packet);
		sock.sendTo(&message, sizeof(message), serverAddr);
	}
};

#endif // ROSBEECLIENT_H
