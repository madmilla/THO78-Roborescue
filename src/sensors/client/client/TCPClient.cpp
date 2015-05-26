#include "TCPClient.h"


using namespace boost::asio;
using namespace boost::asio::ip;

TCPClient::TCPClient(io_service & ioService, std::string service, std::string port):
ioService{ioService},
service{service},
port{port}
{
}


TCPClient::~TCPClient()
{
}

void TCPClient::connect(){
	tcp::resolver::query q{service, port };
	resolv.async_resolve(q, std::bind( &TCPClient::resolveHandler, this, std::placeholders::_1, std::placeholders::_2));
}


void TCPClient::resolveHandler(const boost::system::error_code &ec, tcp::resolver::iterator it){
	if (!ec){
		tcp_socket.async_connect(*it, std::bind(&TCPClient::connectHandler, this, std::placeholders::_1));
		read();
	}
}


bool TCPClient::connectHandler(const boost::system::error_code &ec){
	if (!ec){
		return true;
	}
	return false;
}

void TCPClient::write(std::string s){
	writeString = s;
	tcp_socket.async_send(buffer(writeString), std::bind(&TCPClient::writeHandler, this));
}

void TCPClient::writeHandler(){

}

void TCPClient::read(){
	tcp_socket.async_read_some(buffer(bytes), std::bind(&TCPClient::readHandler, this));
}

void TCPClient::readHandler(){
	std::cout << bytes.data();
	read();
}