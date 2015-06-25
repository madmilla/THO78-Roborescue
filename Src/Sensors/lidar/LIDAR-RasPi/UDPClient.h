/**
*               __
*    _________ / /_  ____  ________  ____________  _____
*   /___/ __ \/ __ \/ __ \/ ___/ _ \/ ___/ ___/ / / / _ \
*  / / / /_/ / /_/ / /_/ / /  /  __(__  ) /__/ /_/ /  __/
* /_/  \____/_.___/\____/_/   \___/____/\___/\__,_/\___/
*
*
* @file Socket
* @date Created: 27-5-2015
*
* @author Hamza ait Messaoud
*
* @section LICENSE
* License: newBSD
*
* Copyright � 2015, HU University of Applied Sciences Utrecht.
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

#ifndef UPDCLIENT_H_
#define UPDCLIENT_H_

#include <thread>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "PracticalSocket.h"
#include "roborescueV1\mavlink.h"
#include <queue>

#include "BaseRobot.h"

//! \author@ Hamza ait Messaoud<hamza.aitmessaoud@student.hu.nl>
//! \class@ UDPClient
//! \brief This class is used to make a connection with the server and to sends and receives data.
class UDPClient
{
public:
	//! \brief Default constructor
	UDPClient();
	//! \brief Default deconstructor
	~UDPClient();

	//! \brief Send a message to a the server.
	//! \param[message]
	int send(mavlink_message_t message);
	
	//! \brief recvieve messages from the server
	void receive();

	//! \brief stops the udpServer thread
	void stop();

	//! \brief set the BaseRobot for handeling messages
	void setBaseRobot(BaseRobot * sl){baseRobot = sl;};

private:
	//! \brief Bind the socket
	void sockbind();
	//! \brief Start the socket
	void start();
	//! \brief Check the connection status
	void checkConnectionStatus();

	std::thread * connectionThread;
	bool stopped;
	UDPSocket sock;
	SocketAddress remoteadr;
	BaseRobot * baseRobot;
	std::queue<mavlink_message_t> * robotMessages;

};

#endif //UPDCLIENT_H_
