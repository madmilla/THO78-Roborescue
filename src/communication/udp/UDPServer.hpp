#ifndef __UDPSERVER__
#define __UDPSERVER__
 
#include <stdio.h>
#include <winsock2.h>
#include <vector>
#include <iostream>
#include <string>
#include <exception>

#include "MessageQueue.h"
#include "Connection.hpp"
#include "UDPSocket.hpp"
#include "RobotManager.h"

#include "../../../deps/incl/mavlink/udp_mavlink_commands/mavlink.h"
#pragma comment(lib,"ws2_32.lib")
const int bufferlen = 512;
const int port = 8888;

/// \author Rene Keijzer<rene.keijzer@student.hu.nl>
/// \class UDPServer
/// \brief a test class for udp with rosbee this class may be used in the future for rosbee communication
/// \brief the constructor of this class initializes an socket and makes it ready for use. this will also start a new thread so the main thread can do other stuff while the udp server is handeling his own messages

class UDPSocket;
class RobotManager;
class UDPServer
{
public:
	UDPServer(RobotManager & manager);
	~UDPServer();
	/// \param Message this is the message to be broadcasted on all the known udp connections
	/// \returns void
	void broadcast(mavlink_message_t * message);

	/// \param Send a message to a specefic connection.
	/// \param Message
	/// \returns void 
	void send(UDPSocket * connection, mavlink_message_t * message);
	
	/// \param buffer for the message to be received in
	/// \returns void
	void receive(mavlink_message_t * message);

	/// \brief method will receive data from udpSocket this is a blocking method
	void receive();

	/// \brief stops the udpServer thread
	void stop();
	int received(){return recv;}
	void printCon();
private:
	
	void init();
	void sockbind();
	void start();
	void startTest();
	void addConnection(sockaddr_in con, mavlink_message_t * msg);
	void handleMessage(sockaddr_in con, mavlink_message_t * msg);
	int recv;
	bool stopped = false;
	SOCKET sock;
	struct sockaddr_in server, si_other;
	int slen, recv_len;
	WSADATA wsa;
	RobotManager & manager;
	mavlink_message_t msg;
	mavlink_ralcp_t packet;

	std::vector<UDPSocket*> _connections;
	int ConId = 0;
	std::thread connectionThread;
};


#endif