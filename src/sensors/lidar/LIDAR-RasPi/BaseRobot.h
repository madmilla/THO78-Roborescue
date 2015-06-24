/*
 * messageListener.h
 *
 *  Created on: May 20, 2015
 *      Author: pawel
 */


#ifndef BASEROBOT_H_
#define BASEROBOT_H_

#include "roborescueV1/mavlink.h"
#include <queue>

class BaseRobot{
public:

	BaseRobot():systemID{0}{}

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
	void sendRosbeeCommand(uint64_t payload, COMMAND_DESTINATION dest, ROSBEE_COMMAND_FUNCTIONS lcf){
		messages.push(encodeRosbeeMessage(payload, dest, lcf ));
	}

	void sendLidarCommand(int32_t * payload, COMMAND_DESTINATION dest, LIDAR_COMMAND_FUNCTIONS lcf){
		messages.push(encodeLidarMessage(payload, dest, lcf ));
	}

	//The function encodeRalcpMessage encodes an mavlink_ralcp_t to an mavlink_message_t
	mavlink_message_t encodeRosbeeMessage(uint64_t payload, COMMAND_DESTINATION dest, ROSBEE_COMMAND_FUNCTIONS lcf){
		mavlink_message_t mavlinkMessage;
		mavlink_rosbee_message_t mavlinkRALCP{payload, dest, lcf};
		mavlink_msg_rosbee_message_encode(systemID, COMMAND_DESTINATION::ROSBEE, &mavlinkMessage, &mavlinkRALCP);

		return mavlinkMessage;
	}

	mavlink_message_t encodeLidarMessage(int32_t * payload, COMMAND_DESTINATION dest, LIDAR_COMMAND_FUNCTIONS lcf){

		mavlink_message_t mavlinkMessage;
		mavlink_lidar_message_t mavlinkRALCP;
		for(int i=0; i< 6; i++){
			mavlinkRALCP.Payload[i] = payload[i];
		}

		mavlinkRALCP.Destination = dest;
		mavlinkRALCP.Function = lcf;
		mavlink_msg_lidar_message_encode(systemID, COMMAND_DESTINATION::LIDAR, &mavlinkMessage, &mavlinkRALCP);

		return mavlinkMessage;
	}

	//The function decodeRalcpMessage decodes an mavlink_message_t to an mavlink_ralcp_t
	mavlink_rosbee_message_t decodeRosbeeMessage(mavlink_message_t & mavlinkMessage){
		mavlink_rosbee_message_t mavlinkRALCP;
		mavlink_msg_rosbee_message_decode(&mavlinkMessage, &mavlinkRALCP);

		return mavlinkRALCP;
	}

	mavlink_lidar_message_t decodeLidarMessage(mavlink_message_t & mavlinkMessage){
		mavlink_lidar_message_t mavlinkRALCP;
		mavlink_msg_lidar_message_decode(&mavlinkMessage, &mavlinkRALCP);

		return mavlinkRALCP;
	}

	std::queue<mavlink_message_t> messages;
	int systemID;
};

#endif /* BASEROBOT_H_ */
