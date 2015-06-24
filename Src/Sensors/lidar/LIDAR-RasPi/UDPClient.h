#ifndef UPDCLIENT_H_
#define UPDCLIENT_H_

#include <thread>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "PracticalSocket.h"
#include "roborescueV1/mavlink.h"
#include <queue>

#include "BaseRobot.h"



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

	void setBaseRobot(BaseRobot * sl){baseRobot = sl;};

private:
	void sockbind();
	void start();
	void addConnection(sockaddr_in con);
	void checkConnectionStatus();
	std::thread * connectionThread;

	bool stopped;
	UDPSocket sock;
	SocketAddress remoteadr;
	BaseRobot * baseRobot;
	std::queue<mavlink_message_t> * robotMessages;

};

#endif //UPDCLIENT_H_
