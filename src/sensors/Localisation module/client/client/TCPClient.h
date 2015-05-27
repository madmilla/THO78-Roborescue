#pragma once

#include <queue>
#include <boost/asio/io_service.hpp>
#include <boost/asio/write.hpp>
#include <boost/asio/buffer.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <array>
#include <string>
#include <iostream>
#include <boost/bind.hpp>


using namespace boost::asio;
using namespace boost::asio::ip;


class TCPClient
{
public:
	TCPClient(io_service & ioService, std::string service, std::string port);
	~TCPClient();

	void connect();
	void resolveHandler(const boost::system::error_code &ec, tcp::resolver::iterator it);
	void connectHandler(const boost::system::error_code &ec);

	void write(std::string);
	void writeHandler();

	void read();
	void readHandler(const boost::system::error_code &ec,
		std::size_t bytes_transferred);

	std::string readQueue();

private:

	std::queue<std::string> sendQueue;
	std::queue<std::string> receiveQueue;

	io_service & ioService;

	tcp::resolver resolv{ ioService };
	tcp::socket tcp_socket{ ioService };
	std::array<char, 4096> bytes;
	std::string writeString;

	tcp::resolver::query q;
};

