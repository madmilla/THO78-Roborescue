#include <iostream>
#include "TCPConnection.h"
#include "MAVLinkExchanger.h"
#include <boost/asio.hpp>

boost::asio::io_service service;
TCPConnection c{ service };
MAVLinkExchanger exchanger{ c };

int main()
{
	if(c.connect(8000))
	{
		
	}
	else
	{
		std::cout << "Could not start-up server" << std::endl;
	}
	return 0;
}