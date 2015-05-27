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

#include "SocketListener.h"



class UDPClient
{
public:
	UDPClient();
	~UDPClient();

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

#endif //UPDCLIENT_H_
