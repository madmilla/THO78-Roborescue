#include <iostream>
#include "TCPConnection.h"
#include "MAVLinkExchanger.h"
#include <boost/asio.hpp>

boost::asio::io_service service;
TCPConnection c{ service };
MAVLinkExchanger exchanger{ c };

int main()
{
	if(c.connect( "192.168.2.7", "8000" ))
	{
		
	}
	else
	{
		std::cout << "Error connecting to server" << std::endl;
	}
	return 0;
}