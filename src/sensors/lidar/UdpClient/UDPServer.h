#ifndef UPDSERVER_H_
#define UPDSERVER_H_

#include <thread>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <iostream>
#include <string>
#include "PracticalSocket.h"
#include " ../../../../deps/incl/mavlink/udp_mavlink_commands/mavlink.h"
#include <queue>

#include "SocketListener.h"


/// \author Rene Keijzer<rene.keijzer@student.hu.nl>
/// \class UDPServer
/// \brief a test class for udp with rosbee this class may be used in the future for rosbee communication
/// \brief the constructor of this class initializes an socket and makes it ready for use. this will also start a new thread so the main thread can do other stuff while the udp server is handeling his own messages


class UDPServer
{
public:
	UDPServer();
	~UDPServer();

	/// \param Send a message to a specefic connection.
	/// \param Message
	/// \returns void 
	void send(mavlink_ralcp_t message);
	
	
	/// \param buffer for the message to be received in
	/// \returns void
	void receive();

	/// \brief stops the udpServer thread
	void stop();

	void addListener(SocketListener * sl){Socketlistener = sl;};

private:
	void sockbind();
	void start();
	void addConnection(sockaddr_in con);
	std::thread * connectionThread;

	UDPSocket sock;
	SocketAddress remoteadr;

	bool stopped = false;
	SocketListener * Socketlistener;

};

#endif //UPDSERVER_H_
