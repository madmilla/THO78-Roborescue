/**
*               __
*    _________ / /_  ____  ________  ____________  _____
*   /___/ __ \/ __ \/ __ \/ ___/ _ \/ ___/ ___/ / / / _ \
*  / / / /_/ / /_/ / /_/ / /  /  __(__  ) /__/ /_/ /  __/
* /_/  \____/_.___/\____/_/   \___/____/\___/\__,_/\___/
*
*
* @file UDPSocket
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



// Author@ Rene Keijzer
// class@ UDPSocket
// This class is used to make a connection with the client and to send and receive data.

#ifndef __UDPSOCKET__
#define __UDPSOCKET__
#include "Socket.h"
#include "Connection.h"
#include "UDPServer.h"
#include "../../../deps/incl/mavlink/udp_mavlink_commands/mavlink.h"
#include <iostream>

class UDPSocket : public Socket
{
public:

	// Constructor to make a socket
	// Param@ Connection this is the connection you want to bind to the socket
	// Param@ UDPServer This is the server where you want to talk with
	UDPSocket(Connection c, UDPServer * serv) : con(c), server(serv){
		incomming = new MessageQueue<mavlink_message_t *>();
	}

	// This function sends a messege
	//Param: message this is the message that you are sending
	void send(mavlink_message_t * message) override;

	void receive(mavlink_message_t * message) override;
	// This function returns the connection id
	// Return@ The id of the connection
	uint8_t getId() override { return con.id; }

	void print();

	// Standard destructor
	~UDPSocket(){
	}
	MessageQueue<mavlink_message_t *> * incomming;
protected:

private:
	friend class UDPServer;
	friend class RobotManager;
	UDPServer * server;
	Connection con;

};
#endif