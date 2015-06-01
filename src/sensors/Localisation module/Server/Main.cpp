#include <boost/asio/io_service.hpp>
#include "TCPServer.h"
#include <thread>
#include <iostream>

int main()
{
	boost::asio::io_service service;
	TCPServer server{ service, 10033 };
	std::thread inputThread{ [&server]()
	{
		std::string message;
		while (1)
		{
			getline(std::cin, message);
			server.broadcast(message);
		}
	}};
	inputThread.detach();
	service.run();
}