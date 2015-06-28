#include "TCPConnection.h"

TCPConnection::TCPConnection(boost::asio::io_service& service):
tcp::socket{ service },
service{ service }
{		
}

TCPConnection::~TCPConnection()
{
	shutdown(boost::asio::ip::tcp::socket::shutdown_both);
	close();
}

bool TCPConnection::connect(std::string host, std::string port)
{
	tcp::resolver resolver{ service };
	tcp::resolver::query query{ host, port };
	tcp::resolver::iterator endpoints = resolver.resolve(query);
	tcp::socket::connect(*endpoints, error);
	if(error)
	{
		return false;
	}
	return true;
}

bool TCPConnection::connect(int port)
{
	tcp::acceptor acceptor{ service, tcp::endpoint(tcp::v4(), port) };
	acceptor.accept(*this);
	return true;
}

size_t TCPConnection::readData(unsigned char* buffer, int nrOfBytes)
{
	if(socket)
	{
		boost::system::error_code error;
		return read_some(boost::asio::buffer(buffer, nrOfBytes), error);
	}
	return -1;
}

size_t TCPConnection::writeData(const unsigned char* buffer, int nrOfBytes)
{
	if(socket)
	{
		boost::system::error_code error;
		return write_some(boost::asio::buffer(buffer, nrOfBytes), error);
	}
	return -1;
}