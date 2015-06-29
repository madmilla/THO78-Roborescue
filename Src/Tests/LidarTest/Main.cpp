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
	if(c.connect( "145.89.161.205", "8000" ))
	{
		std::cout << "CONNECTED TO SERVER" << std::endl << std::endl;
		MAVLinkExchanger exchanger{ &c };
		Lidar lidar{ "/dev/ttyAMA0" };
		LidarController controller{ lidar, exchanger };
		std::thread controllerThread{ &LidarController::loop, std::ref(controller) };
		std::thread exchangerThread{ &MAVLinkExchanger::loop, std::ref(exchanger) };
		controllerThread.detach();
		exchangerThread.detach();
		service.run();
	}
	return 0;
}
