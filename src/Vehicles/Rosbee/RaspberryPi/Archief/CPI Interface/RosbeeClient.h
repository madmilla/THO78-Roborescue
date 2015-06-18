#ifndef ROSBEECLIENT_H
#define ROSBEECLIENT_H

#include <iostream>
using namespace std;

#include "PracticalSocket.h"
#include <iostream>
#include <inttypes.h>
#include <string.h>
#include <stdlib.h>
#include <ctime>
#include "mavlink_commands/mavlink_commands/mavlink.h"

class RosbeeClient {
	private:
	UDPSocket sock;
	
	SocketAddress to_adr;
	clock_t start;
	
	mavlink_message_t msg;
	mavlink_ralcp_t initMsg;
	int count = 0;
	
	public:
	RosbeeClient(string IP);
	int waitReceiveMessage();
	void sendMessage(string message);
};

#endif