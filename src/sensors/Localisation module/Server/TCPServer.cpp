#include "TCPServer.h"
#include <functional>
#include <iostream>

TCPServer::TCPServer(boost::asio::io_service& service, int portNumber):
service{ service },
tcpAcceptor{ service, tcp::endpoint( tcp::v4(), portNumber ) }
{
	acceptConnections();
}

void TCPServer::acceptConnections()
{
	connections.push_back(new tcp::socket{ tcpAcceptor.get_io_service() });
	tcpAcceptor.async_accept(*connections.back(), std::bind( &TCPServer::connectionAcceptedHandler, this ));
}

void TCPServer::broadcast(std::string data)
{
	sendData = data;
	for (auto& tcpSocket : connections)
	{
		tcpSocket->async_send(boost::asio::buffer(sendData), std::bind(&TCPServer::dataWrittenHandler, this));
	}
}

void TCPServer::connectionAcceptedHandler()
{
	std::cout << "incoming connection\n";
	acceptConnections();
}

void TCPServer::dataWrittenHandler()
{
}