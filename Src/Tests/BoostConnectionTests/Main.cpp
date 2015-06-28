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
	c.connect(8000)
	return 0;
}