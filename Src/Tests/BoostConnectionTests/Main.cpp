#include <iostream>
#include "TCPConnection.h"
#include "MAVLinkExchanger.h"
#include <boost/asio.hpp>
#include <thread>

boost::asio::io_service service;

int main()
{
	TCPConnection c{ service };
	MAVLinkExchanger exchanger{ c };
	
	if(c.connect(8000))
	{
		service.run();
	}
	else
	{
		std::cout << "Could not start-up server" << std::endl;
	}
	return 0;
}