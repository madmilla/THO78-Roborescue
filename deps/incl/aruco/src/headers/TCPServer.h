#ifndef _TCPSERVER_H
#define _TCPSERVER_H
#include <boost/asio.hpp>

using boost::asio::ip::tcp;

class TCPServer
{
public:
	TCPServer(boost::asio::io_service& service, int portNumber);

	/**
	* \brief Broadcast data to all active connections
	*
	* Loops through all connections and start asynchronously
	* sending data to them.
	*
	* \param data String of data to send to all connections.
	*/
	void broadcast(std::string data);
private:
	boost::asio::io_service& service;
	tcp::acceptor tcpAcceptor;
	std::vector<tcp::socket*> connections;
	std::string sendData;

	/**
	* \brief 
	*
	* 
	*/
	void acceptConnections();
	void connectionAcceptedHandler(const boost::system::error_code &ec);
	void dataWrittenHandler(const boost::system::error_code &ec);
};
#endif