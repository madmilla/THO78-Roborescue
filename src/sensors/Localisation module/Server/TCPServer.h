#ifndef _TCPSERVER_H
#define _TCPSERVER_H
#include <boost/asio.hpp>

using boost::asio::ip::tcp;

class TCPServer
{
public:
	TCPServer(boost::asio::io_service& service, int portNumber);
	void broadcast(std::string data);
private:
	boost::asio::io_service& service;
	tcp::acceptor tcpAcceptor;
	std::vector<tcp::socket*> connections;
	std::string sendData;

	void acceptConnections();
	void connectionAcceptedHandler();
	void dataWrittenHandler();
};
#endif