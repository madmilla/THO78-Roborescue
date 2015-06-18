#include "RosbeeClient.h"

// Constructor
RosbeeClient::RosbeeClient(string IP) {
	to_adr = SocketAddress(IP.c_str(), 8888, SocketAddress::UDP_SOCKET);
	start = clock()+ (CLOCKS_PER_SEC*2);
	
	initMsg.Destination = COMMAND_DESTINATION::ROSBEE;
	initMsg.Function = ROSBEE_COMMAND_FUNCTIONS::STARTMISSION;
	initMsg.Payload = 500; // Wordt een "ready" bericht
}

int RosbeeClient::waitReceiveMessage() {
	try{
			while(start > clock()){}

			sock.recvFrom(&msg, sizeof(mavlink_message_t), to_adr);

			mavlink_msg_ralcp_decode(&msg, &initMsg);

			cout << "received: " << initMsg.Payload << endl;
			cout << "from: " << to_adr.getAddress() << ":" << to_adr.getPort() << endl;

			start = clock()+ (CLOCKS_PER_SEC*2);

		}catch(SocketTimedOutException e){return -1;}
	return initMsg.Payload;
}

void RosbeeClient::sendMessage(string message) {
	mavlink_msg_ralcp_encode(COMMAND_DESTINATION::ROSBEE, COMMAND_DESTINATION::ROSBEE, &msg, &initMsg);
	sock.sendTo(&msg, sizeof(msg), to_adr);
}