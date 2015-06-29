#include <iostream>
#include <thread>
#include "Quadcopter.h"
#include "SerialConnection.h"
#include "MAVLinkExchanger.h"
#include "QuadcopterController.h"
#include "Coordinate.h"
#include <boost/asio.hpp>
#include "XYLocalisationModule.h"
#include "VictimLocalisationModule.h"


boost::asio::io_service service;
SerialConnection serialPort { service };
MAVLinkExchanger exchanger { &serialPort };
Quadcopter quadcopter{ exchanger };

XYLocalisationModule xyLocalisationModule
	{ service, "192.168.137.39", "10033" };
VictimLocalisationModule victimLocalisationModule
	{ service, "192.168.137.39", "10033" };
	
QuadcopterController quadcopterController {quadcopter, xyLocalisationModule};

int main()
{
	std::thread inputThread{ [&xyLocalisationModule]()
	{
		std::string message;
		while (1)
		{
			char c;
			std::cin >> c;
			if(c == 's')
			{
				std::cout << "Getting position from quad and setting it in controller.\n";
				quadcopterController.setPosition();
				auto coord = quadcopterController.getPosition();
				std::cout << "Current position: " << coord.getX() << ", " << coord.getY() << "\n";
			}

			if(c == 'h')
			{
				std::cout << "Setting height on 1.\n";
				quadcopterController.setHeight(1);
			}
			if(c == 't')
			{
				std::cout << "Setting new target:\nInput X coord:\n";
				int x, y;
				std::cin >> x;
				std::cout << "Input Y coord:\n";
				std::cin >> y;
				
				std::cout << "Setting target (" << x << "," << y << "), 1.\n";
				quadcopterController.setTarget(Coordinate<double>{
					(double)x,(double)y}, 1);
			}
			if(c == 'm')
			{
				std::cout << "Move towards target.\n";
				quadcopterController.moveTowardsTarget();
			}
			//std::cin >> message;
			//if (!message.empty())
			//{
			//}
		}
	} };
	inputThread.detach();
	
	service.run();
	return 0;
}