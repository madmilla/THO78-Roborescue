/*
 * messageListener.h
 *
 *  Created on: May 20, 2015
 *      Author: pawel
 */

#ifndef SOCKETLISTENER_H_
#define SOCKETLISTENER_H_

#include "../../../../deps/incl/mavlink/udp_mavlink_commands/mavlink.h"

class SocketListener{
public:
	virtual void onMessage(mavlink_ralcp_t & function) = 0;
	std::queue<mavlink_ralcp_t> * getMessageQueue(){return &messages;};
	std::queue<mavlink_ralcp_t> messages;
};

#endif /* SOCKETLISTENER_H_ */
