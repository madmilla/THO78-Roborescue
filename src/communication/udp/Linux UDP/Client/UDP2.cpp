//============================================================================
// Name        : UDP2.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;


#include "PracticalSocket.h"
#include <iostream>
#include <inttypes.h>
#include <string>
#include <stdlib.h>
#include <ctime>
#include "mavlink_commands/mavlink_commands/mavlink.h"

int main(int argc, char **argv)
{
	UDPSocket sock;
	SocketAddress to_adr("192.168.137.12", 8888, SocketAddress::UDP_SOCKET);
	clock_t start = clock()+ (CLOCKS_PER_SEC*2);

	mavlink_message_t msg;
	mavlink_ralcp_t initMsg;

	int count = 0;
	initMsg.Destination = COMMAND_DESTINATION::ROSBEE;
				initMsg.Function = ROSBEE_COMMAND_FUNCTIONS::STARTMISSION;
				initMsg.Payload = 500;
	while(true){
		try{
			while(start > clock()){}



			mavlink_msg_ralcp_encode(COMMAND_DESTINATION::ROSBEE, COMMAND_DESTINATION::ROSBEE, &msg, &initMsg);

			sock.sendTo(&msg, sizeof(msg), to_adr );

			cout << "recieved: " << initMsg.Payload << endl;
			cout << "from: " << to_adr.getAddress() << ":" << to_adr.getPort() << endl;

			sock.recvFrom(&msg, sizeof(mavlink_message_t), to_adr);

			mavlink_msg_ralcp_decode(&msg, &initMsg);

			cout << "recieved: " << initMsg.Payload << endl;

			start = clock()+ (CLOCKS_PER_SEC*2);

		}catch(SocketTimedOutException e){continue;}
	}
}
