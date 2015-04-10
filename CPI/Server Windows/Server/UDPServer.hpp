#ifndef __UDPSERVER__
#define __UDPSERVER__
#include <thread>
#include<stdio.h>
#include<winsock2.h>
#include <vector>
#include <iostream>
#include <string>
#include "..\..\Rosbee\Connection.hpp"
#include "..\..\Rosbee\UDPSocket.hpp"

#pragma comment(lib,"ws2_32.lib") //Winsock Library

const int bufferlen = 512;
const int port = 8888;

/// \author Rene Keijzer<rene.keijzer@student.hu.nl>
/// \class UDPServer
/// \brief a test class for udp with rosbee this class may be used in the future for rosbee communication
/// \brief the constructor of this class initializes an socket and makes it ready for use. this will also start a new thread so the main thread can do other stuff while the udp server is handeling his own messages


class UDPServer
{
public:
	static uint8_t currentid;
	UDPServer();
	~UDPServer();
	/// \param Message this is the message to be broadcasted on all the known udp connections
	/// \returns void
	void broadcast(std::string message);

	/// \param Send a message to a specefic connection.
	/// \param Message
	/// \returns void 
	void send(Connection connection, std::string message);
	
	
	/// \param buffer for the message to be received in
	/// \returns void
	void receive(char * buffer);

	/// \brief stops the udpServer thread
	void stop();
private:

	void init();
	void sockbind();
	void start();
	void addConnection(sockaddr_in con);
	std::thread connectionThread;

	bool stopped = false;
	SOCKET sock;
	struct sockaddr_in server, si_other;
	int slen, recv_len;
	char buf[bufferlen];
	WSADATA wsa;

	std::vector<UDPSocket> _connections;
};

#endif