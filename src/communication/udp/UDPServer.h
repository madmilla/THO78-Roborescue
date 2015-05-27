/**
*               __
*    _________ / /_  ____  ________  ____________  _____
*   /___/ __ \/ __ \/ __ \/ ___/ _ \/ ___/ ___/ / / / _ \
*  / / / /_/ / /_/ / /_/ / /  /  __(__  ) /__/ /_/ /  __/
* /_/  \____/_.___/\____/_/   \___/____/\___/\__,_/\___/
*
*
* @file UDPServer
* @date Created: 27-5-2015
*
* @author Rene Keijzer
*
* @section LICENSE
* License: newBSD
*
* Copyright © 2015, HU University of Applied Sciences Utrecht.
* All rights reserved.
*
* Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:
* - Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
* - Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.
* - Neither the name of the HU University of Applied Sciences Utrecht nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
* "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
* THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
* ARE DISCLAIMED. IN NO EVENT SHALL THE HU UNIVERSITY OF APPLIED SCIENCES UTRECHT
* BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
* CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE
* GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
* HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
* LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT
* OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
**/



#ifndef __UDPSERVER__
#define __UDPSERVER__
 
#include <stdio.h>
#include <winsock2.h>
#include <vector>
#include <iostream>
#include <string>
#include <exception>

#include "MessageQueue.h"
#include "Connection.h"
#include "UDPSocket.h"
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