/*
 * messageListener.h
 *
 *  Created on: May 20, 2015
 *      Author: pawel
 */

#ifndef BASELIDAR_H_
#define BASELIDAR_H_

#include "../../../../deps/incl/mavlink/udp_mavlink_commands/mavlink.h"
#include <queue>

class BaseLidar{
public:
	//The function onMessage() will be called by the UDPClient. This function determine what to do with the recieved message.
	//The message must first be decoded from the default mavlink_message_t to an mavlink_ralcp_t.
	virtual void onMessage(mavlink_message_t & function) = 0;

	//Retuns the message Queue
	std::queue<mavlink_message_t> * getMessageQueue(){return &messages;}

	//Returns the ID of the system
	int getSystemID(){return systemID;}

protected:
	//The function sendCommand pushes a message in the message Queue.
	//This function can be used to send a message to the CPI.
	void sendCommand(uint64_t payload, COMMAND_DESTINATION dest, LIDAR_COMMAND_FUNCTIONS lcf){
		messages.push(encodeRalcpMessage(payload, dest, lcf ));
	}

	//The function encodeRalcpMessage encodes an mavlink_ralcp_t to an mavlink_message_t
	mavlink_message_t encodeRalcpMessage(uint64_t payload, COMMAND_DESTINATION dest, LIDAR_COMMAND_FUNCTIONS lcf){
		mavlink_message_t mavlinkMessage;
		mavlink_ralcp_t mavlinkRALCP{payload, dest, lcf};
		mavlink_msg_ralcp_encode(systemID, COMMAND_DESTINATION::LIDAR, &mavlinkMessage, &mavlinkRALCP);

		return mavlinkMessage;
	}

	//The function decodeRalcpMessage decodes an mavlink_message_t to an mavlink_ralcp_t
	mavlink_ralcp_t decodeRalcpMessage(mavlink_message_t & mavlinkMessage){
		mavlink_ralcp_t mavlinkRALCP;
		mavlink_msg_ralcp_decode(&mavlinkMessage, &mavlinkRALCP);

		return mavlinkRALCP;
	}

	std::queue<mavlink_message_t> messages;
	int systemID;
};

#endif /* BASELIDAR_H_ */
