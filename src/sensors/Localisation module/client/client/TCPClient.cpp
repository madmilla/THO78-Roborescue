#include "TCPClient.h"


using namespace boost::asio;
using namespace boost::asio::ip;

TCPClient::TCPClient(io_service & ioService, std::string service, std::string port):
ioService{ioService},
q{service, port}
{
}


TCPClient::~TCPClient()
{
}

void TCPClient::connect(){
	std::cout << "connecting/resolving to " << q.service_name() << "\n";
	std::cout << "resolving...\n";
	
	resolv.async_resolve(q, std::bind( &TCPClient::resolveHandler, this, std::placeholders::_1, std::placeholders::_2));
}


void TCPClient::resolveHandler(const boost::system::error_code &ec, tcp::resolver::iterator it){
	if (!ec){
		std::cout << "resolve ok\n";
		std::cout << "connecting...\n";
		
		tcp_socket.async_connect(*it, std::bind(&TCPClient::connectHandler, this, std::placeholders::_1));
	}
	else{
		std::cout << "resolve failed\n";
	}
}


void TCPClient::connectHandler(const boost::system::error_code &ec){
	if (!ec){
		std::cout << "connecting ok.\n";
		read();
	}
	else{
		std::cout << "connecting failed.\n";
	}
}

void TCPClient::write(std::string s){
	writeString = s;
	std::cout << "writing: " << writeString;
	tcp_socket.async_send(buffer(writeString), std::bind(&TCPClient::writeHandler, this));
}

void TCPClient::writeHandler(){
	std::cout << "\nwriting ok\n";
}

void TCPClient::read(){
	tcp_socket.async_read_some(buffer(bytes), std::bind(&TCPClient::readHandler, this, std::placeholders::_1, std::placeholders::_2));
}

void TCPClient::readHandler(const boost::system::error_code &ec, std::size_t bytes_transferred){
	if (!ec)
	{
		//receiveQueue.push( bytes.data() );
		std::cout << bytes.data();
		read();
	}
	else{
		std::cout << "read failed";
	}
}

std::string TCPClient::readQueue(){
	std::string s = receiveQueue.front();
	receiveQueue.pop();
	return s;
}