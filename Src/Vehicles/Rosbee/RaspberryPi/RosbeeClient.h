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
	/// Wait for a incoming messages and decodes it into een Mavlink packet.
	/// This function blocks until a message is received.
	/// @param packet Payload parsed from the Mavelink message.
	void waitReceiveMessage(mavlink_command_long_t &packet);

	/// @brief Send message.
	///
	/// Create a Mavlink message from the parameters and send it over the UDP socket.
	/// @param command Command ID that will be included in the Mavlink message.
	/// @param param1 First parameter.
	/// @param param2 Second parameter.
	/// @param param3 Third parameter.
	/// @param param4 Fourth parameter.
	/// @param param5 Fifth parameter.
	/// @param param6 Sixth parameter.
	/// @param param7 Seventh parameter.
	void sendMessage(
		unsigned short command,
		float param1 = 0,
		float param2 = 0,
		float param3 = 0,
		float param4 = 0,
		float param5 = 0,
		float param6 = 0,
		float param7 = 0
	);
	
	/// @brief Send a initialization messages.
	///
	/// Sort hand function to create a initialization messages.
	/// @param x The position on the x-axis of the Rosbee.
	/// @param y The position of the y-axis of the Rosbee.
	/// @param angle The heading in degrees of the Rosbee.
	void sendInit(float x, float y, float angle);
	
	/// @brief Send a request for a new waypoint.
	///
	/// Sort hand function to create request a new waypoint messages.
	/// The messages need to be filled with most recent values in order for CPI/MAP
	/// the create a accurate new one.
	/// @param x The position on the x-axis of the Rosbee.
	/// @param y The position of the y-axis of the Rosbee.
	/// @param angle The heading in degrees of the Rosbee.
	/// @param status Current status of the Rosbee.
	void requestWaypoint(float x, float y, float angle, float status);

};

#endif // ROSBEECLIENT_H
