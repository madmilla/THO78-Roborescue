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
	* \brief Checks for new connections
	*
	* Checks for new incomming connections. There's no need to first check for any connections.
	* The method automaticly checks any incomming connection and won't do anything if there aren't.
	* 
	*/
	void acceptConnections();
	
	
	/**
	* \brief Is being called after a connection is accepted.
	*
	* This method is being called after a connection has been accepted. If any errors occour they will be included in the ec parameter.
	* 
	* @param ec An errorcode in case an error occoured. Will be 0 if ok.
	* 
	*/
	void connectionAcceptedHandler(const boost::system::error_code &ec);
	
	/**
	* \brief Is being called after the server has writting a message.
	*
	* This method is being called after a message has been written. If any errors occour they will be included in the ec parameter.
	* 
	* @param ec An errorcode in case an error occoured. Will be 0 if ok.
	* 
	*/
	void dataWrittenHandler(const boost::system::error_code &ec);
};
#endif
