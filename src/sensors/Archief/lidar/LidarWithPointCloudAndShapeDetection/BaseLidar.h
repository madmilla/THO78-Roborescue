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
	virtual void onMessage(mavlink_message_t & function) = 0;

	std::queue<mavlink_message_t> * getMessageQueue(){return &messages;}
	int getSystemID(){return systemID;}

	std::queue<mavlink_message_t> messages;

protected:

	mavlink_message_t encodeRalcpMessage(uint64_t payload, COMMAND_DESTINATION dest, LIDAR_COMMAND_FUNCTIONS lcf){
		mavlink_message_t mavlinkMessage;
		mavlink_ralcp_t mavlinkRALCP{payload, dest, lcf};
		mavlink_msg_ralcp_encode(systemID, COMMAND_DESTINATION::LIDAR, &mavlinkMessage, &mavlinkRALCP);

		return mavlinkMessage;
	}

	mavlink_ralcp_t decodeRalcpMessage(mavlink_message_t & mavlinkMessage){
		mavlink_ralcp_t mavlinkRALCP;
		mavlink_msg_ralcp_decode(&mavlinkMessage, &mavlinkRALCP);

		return mavlinkRALCP;
	}

	int systemID;
};

#endif /* BASELIDAR_H_ */
