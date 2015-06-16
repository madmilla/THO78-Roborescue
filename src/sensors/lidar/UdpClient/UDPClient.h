#ifndef UPDCLIENT_H_
#define UPDCLIENT_H_

#include <thread>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <iostream>
#include <string>
#include "PracticalSocket.h"
#include "../../../../deps/incl/mavlink/udp_mavlink_commands/mavlink.h"
#include <queue>

#include "BaseLidar.h"



class UDPClient
{
public:
	UDPClient();
	~UDPClient();

	/// \param Send a message to a specefic connection.
	/// \param Message
	/// \returns void 
	int send(mavlink_message_t message);
	
	
	/// \param buffer for the message to be received in
	/// \returns void
	void receive();

	/// \brief stops the udpServer thread
	void stop();

	void addListener(BaseLidar * sl){lidar = sl;};

private:
	void sockbind();
	void start();
	void addConnection(sockaddr_in con);
	void checkConnectionStatus();
	std::thread * connectionThread;

	bool stopped;
	UDPSocket sock;
	SocketAddress remoteadr;
	BaseLidar * lidar;

};

#endif //UPDCLIENT_H_
