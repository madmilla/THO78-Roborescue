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


RosbeeClient::RosbeeClient(const std::string &serverAddress, unsigned short serverPort):
serverAddr{serverAddress.c_str(),serverPort, SocketAddress::UDP_SOCKET}
{}
/*
void RosbeeClient::waitReceiveMessage(unsigned char &function, unsigned long long &payload){
	//Raw mavlink message.
	mavlink_message_t message;
	//Decoded mavlink message.
	mavlink_ralcp_t packet;
	//Address from which the message came.
	SocketAddress remote_addr;
	//Receive UDP message.
	//This function blocks until a message is received.
	sock.recvFrom(&message, sizeof(message), remote_addr);
	//Decode the message to a packet.
	mavlink_msg_ralcp_decode(&message, &packet);
	//Get the function from the packet and store it on the address from the parameter.
	function = packet.Function;
	//Get the payload from the packet and store it on the address form the parameter.
	payload = packet.Payload;
}
*/
//void RosbeeClient::waitReceiveMessage(unsigned char &function, unsigned long long &payload){

void RosbeeClient::waitReceiveMessage(mavlink_command_long_t &packet){
		mavlink_message_t message;
		SocketAddress remote_addr;
		
		sock.recvFrom(&message, sizeof(message), remote_addr);
		mavlink_msg_command_long_decode(&message, &packet);
}


void RosbeeClient::sendInit(float x, float y, float angle){
	sendMessage(x,y,angle,0,0,0,0,ROSBEE_COMMAND_FUNCTIONS::ROSBEE_INIT, COMMAND_DESTINATION::ROSBEE);
}

void RosbeeClient::requestWaypoint(float x, float y, float angle, float status){
	sendMessage(x,y,angle,status,0,0,0,ROSBEE_COMMAND_FUNCTIONS::ACKNOWLEDGE, COMMAND_DESTINATION::ROSBEE);
}

void RosbeeClient::sendMessage(unsigned char function, float data[7]){
	sendMessage(data[0], data[1], data[2], data[3], data[4], data[5],data[6], function, COMMAND_DESTINATION::ROSBEE);
}


// void RosbeeClient::sendMessage(unsigned char function, unsigned long long payload){
// 	//Raw mavlink message.
// 	mavlink_message_t message;
// 	//Decoded mavlink message.
// 	mavlink_command_long_t packet;
// 	//Set the destination, this will always be the same.
// 	packet.Destination = COMMAND_DESTINATION::ROSBEE;
// 	//Set the function.
// 	packet.Function = function;
// 	//Set the payload.
// 	packet.Payload = payload;
// 	//Encode the packet the a raw mavlink message.
// 	mavlink_msg_ralcp_encode(COMMAND_DESTINATION::ROSBEE, COMMAND_DESTINATION::ROSBEE, &message, &packet);
// 	//Send the message over UDP.
// 	sock.sendTo(&message, sizeof(message), serverAddr);
// }
