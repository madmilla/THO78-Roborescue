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
	std::cout << "Setting new target:\nInput X coord:\n";
	int x, y;
	std::cin >> x;
	std::cout << "Input Y coord:\n";
	std::cin >> y;
	
	std::cout << "Setting target (" << x << "," << y << "), height: 1.\n";
	quadcopterController.setTarget(Coordinate<double>{
		(double)x,(double)y}, 1);					
					
	std::cout << "Setting current height on 1.\n";
	quadcopterController.setHeight(1);
	
	
	std::thread xyThread{ [&xyLocalisationModule]()
	{
		std::string message;
		while (1)
		{
			std::this_thread::sleep_for (std::chrono::seconds(1));
			
			quadcopterController.setPosition();
			
			auto coord = quadcopterController.getPosition();
			std::cout << "Current position: " << coord.getX() << ", " << coord.getY() << "\n";
			
			quadcopterController.moveTowardsTarget();
			std::cout << std::endl << std::endl;
		}
	} };
	std::thread victimThread{ [&victimLocalisationModule]()
	{	
		bool victimFound = false;

		while(1)
		{
			if(victimLocalisationModule.isVictimFound() && !victimFound)
			{
				std::cout <<"Victim found!" << std::endl; 
				std::cout << "Victim id is " << 
					victimLocalisationModule.getVictimId() << std::endl;
				victimFound = true;
			}	
		}
	}};
	victimThread.detach();
	xyThread.detach();
	
	service.run();
	return 0;
}