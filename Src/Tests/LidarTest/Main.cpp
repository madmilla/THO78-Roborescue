#include <iostream>
#include "TCPConnection.h"
#include "MAVLinkExchanger.h"
#include <boost/asio.hpp>
#include "Lidar.h"
#include "LidarController.h"
#include <thread>

boost::asio::io_service service;

int main()
{
	TCPConnection c{ service };
	if(c.connect( "192.168.2.7", "8000" ))
	{
		std::cout << "CONNECTED TO SERVER" << std::endl << std::endl;
		MAVLinkExchanger exchanger{ c };
		Lidar lidar{ "/dev/ttyAMA0" };
		LidarController controller{ lidar, exchanger };
		std::thread controllerThread{ &LidarController::loop, std::ref(controller) };
		controllerThread.detach();
		service.run();
	}
	return 0;
}