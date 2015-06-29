/**
*               __
*    _________ / /_  ____  ________  ____________  _____
*   /___/ __ \/ __ \/ __ \/ ___/ _ \/ ___/ ___/ / / / _ \
*  / / / /_/ / /_/ / /_/ / /  /  __(__  ) /__/ /_/ /  __/
* /_/  \____/_.___/\____/_/   \___/____/\___/\__,_/\___/
*
*
* @file RosbeeClient.cpp
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


#include "RosbeeClient.h"
#include <string>
#include "roborescueV1/mavlink.h"
#include "RosbeeCommandFunctions.h"


RosbeeClient::RosbeeClient(const std::string &serverAddress, unsigned short serverPort):
serverAddr{serverAddress.c_str(),serverPort, SocketAddress::UDP_SOCKET}
{}

void RosbeeClient::waitReceiveMessage(mavlink_command_long_t &packet){
		mavlink_message_t message;
		SocketAddress remote_addr;
		//Wait for incoming message.
		//This function blocks.
		sock.recvFrom(&message, sizeof(message), remote_addr);
		mavlink_msg_command_long_decode(&message, &packet);
}


void RosbeeClient::sendInit(float x, float y, float angle){
	sendMessage(ROSBEE_COMMAND_FUNCTIONS::ROSBEE_INIT,x,y,angle);
}

void RosbeeClient::requestWaypoint(float x, float y, float angle, float status){
	sendMessage(ROSBEE_COMMAND_FUNCTIONS::ACKNOWLEDGE, x,y,angle,status);
}

void RosbeeClient::sendMessage(
		unsigned short command,
		float param1,
		float param2,
		float param3,
		float param4,
		float param5,
		float param6,
		float param7
	){
	//Mavlink packets.
	mavlink_message_t message;
	mavlink_command_long_t packet; 
	packet.command = command;
	//Confirmation is not used.
	//Therefore is standard filled with a zero.
	packet.confirmation = 0;
	packet.param1 = param1;
	packet.param2 = param2;
	packet.param3 = param3;
	packet.param4 = param4;
	packet.param5 = param5;
	packet.param6 = param6;
	packet.param7 = param7;
	//Target component is not used.
	//Therefore is standard filled with a zero.
	packet.target_component = 0;
	packet.target_system = COMMAND_DESTINATION::ROSBEE;
	//Encode the packet to ready it for sending.
	mavlink_msg_command_long_encode(COMMAND_DESTINATION::ROSBEE, COMMAND_DESTINATION::ROSBEE, &message, &packet);
	//Send the the messages to the server.
	sock.sendTo(&message, sizeof(message), serverAddr);
}

