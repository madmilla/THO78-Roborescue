#ifndef _TCP_CONNECTION_H
#define _TCP_CONNECTION_H
#include "DataPort.h"
#include <boost/asio.hpp>
#include <memory>

using boost::asio::ip::tcp;

class TCPConnection : public DataPort, public tcp::socket
{
public:
	TCPConnection(boost::asio::io_service& service);
	~TCPConnection();
	//Dus als het deze is worden we een client
	bool connect(std::string host, std::string port);
	//En als het deze is worden we een server
	bool connect(int port);
	size_t readData(unsigned char* buffer, int nrOfBytes) override;
	size_t writeData(const unsigned char* buffer, int nrOfBytes) override;
private:
	boost::asio::io_service& service;
	boost::system::error_code error;
	tcp::socket* tcpSocket;
};
#endif