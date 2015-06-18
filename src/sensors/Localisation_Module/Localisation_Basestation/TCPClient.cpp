/**
*               __
*    _________ / /_  ____  ________  ____________  _____
*   /___/ __ \/ __ \/ __ \/ ___/ _ \/ ___/ ___/ / / / _ \
*  / / / /_/ / /_/ / /_/ / /  /  __(__  ) /__/ /_/ /  __/
* /_/  \____/_.___/\____/_/   \___/____/\___/\__,_/\___/
*
*
* @file TCPClient.cpp
* @date Created: 29-5-2015
*
* @author Kjeld Perquin
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
#include "TCPClient.h"

TCPClient::~TCPClient()
{
}

TCPClient::TCPClient(io_service& service, std::string host, std::string port):
tcpQuery{ host, port },
tcpResolver{ service },
tcpSocket{ service }
{
	tcpResolver.async_resolve(tcpQuery, std::bind(&TCPClient::connectionResolvedHandler, this, std::placeholders::_1, std::placeholders::_2));
	tcp::socket tcpSocket{ service };
}

void TCPClient::connectionResolvedHandler(const boost::system::error_code &ec, tcp::resolver::iterator it)
{
	if (!ec)
	{
		async_connect(tcpSocket, it, std::bind(&TCPClient::connectedHandler, this, std::placeholders::_1));
	}
}

void TCPClient::connectedHandler(const boost::system::error_code &ec)
{
	if (!ec)
	{
		readData();
	}
}

void TCPClient::readData()
{ 
	async_read_until(tcpSocket, receiveBuffer, '\n', std::bind(&TCPClient::dataReceivedHandler, this, std::placeholders::_1, std::placeholders::_2));
}

void TCPClient::dataReceivedHandler(const boost::system::error_code& ec, size_t bytesTransferred)
{
	if (!ec)
	{
		std::string message;
		std::istream is(&receiveBuffer);
		getline(is, message);
		handleMessage(message);
		readData();
	}
}