#include <iostream>
#include "TCPConnection.h"
#include "MAVLinkExchanger.h"
#include <boost/asio.hpp>
#include <thread>

boost::asio::io_service service;

int main()
{
	TCPConnection c{ service };
	MAVLinkExchanger exchanger{ &c };
	c.connect(8000);
	std::thread exchangerThread{ &MAVLinkExchanger::loop, std::ref(exchanger) };
	exchangerThread.detach();
	
	mavlink_message_t message;
	mavlink_msg_command_long_pack(1, 1, &message, 1,1, MAV_CMD_LIDAR_START_SCAN, 0,1, 0,0,0,0,0,0);
	while(1)
	{
		char c;
		std::cin >> c;
		if(c != ' ')
		{
			std::cout << "Sent message" << std::endl;
			exchanger.enqueueMessage(message);
		}
	}
	return 0;
}