#include <iostream>
#include "TCPConnection.h"
#include "MAVLinkExchanger.h"
#include <boost/asio.hpp>
#include <thread>

boost::asio::io_service service;
TCPConnection c{ service };
MAVLinkExchanger exchanger{ &c };

void bla()
{
	while(1)
	{
		while (exchanger.receiveQueueSize())
		
		{
			auto line = exchanger.dequeueMessage();
			std::cout << "Line: " 
			<< mavlink_msg_lidar_line_get_start_X(&line) << ','
			<< mavlink_msg_lidar_line_get_start_Y(&line) << " tot " 
			<< mavlink_msg_lidar_line_get_end_X(&line) << ','
			<< mavlink_msg_lidar_line_get_end_Y(&line) << std::endl;
		}
	}
}

void input()
{
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
}

int main()
{
	c.connect(8000);
	std::thread exchangerThread{ &MAVLinkExchanger::loop, std::ref(exchanger) };
	std::thread engeThread{ bla };
	std::thread inputThread{ input };
	exchangerThread.detach();
	engeThread.detach();
	inputThread.detach();
	service.run();
	
	
	return 0;
}