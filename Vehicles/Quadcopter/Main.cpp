#include "Quadcopter.h"
#include "../Dependencies/Serial/SerialPort.h"
#include <string>
#include "MAVLinkExchanger.h"
#include <iostream>
#include "TempListener.h"
#include <thread>

int main() 
{
	SerialPort serialPort("COM6");
	MAVLinkExchanger communicator{ serialPort };
	Quadcopter quadcopter(communicator);
	//Make a tempListener to check if the quad notifies correctly
	TempListener tempListener;
	quadcopter.registerListener(&tempListener);
	std::thread quadcopterLoopThread { &Quadcopter::loop, &quadcopter};
	std::thread communicatorLoopThread{ &MAVLinkExchanger::loop, &communicator };
	quadcopterLoopThread.detach();
	communicatorLoopThread.detach();
	while (1)
	{
		//std::cout << "BLU";
		char c;
		std::cin >> c;
		if (c == 'p')
		{
			std::cout << "Messages: " << quadcopter.receivedMessageMap.size() << std::endl;
			for (auto &pair : quadcopter.receivedMessageMap)
			{
				std::cout << "[" << std::to_string(pair.first) << "]: " << std::to_string(pair.second) << std::endl;
			}
		}
		else if (c == 'a')
		{
			quadcopter.arm();
		}
		else if (c == 'd')
		{
			quadcopter.disarm();
		}
		else if (c == 's')
		{
			quadcopter.shutdown();
		}
		else if (c == 'g')
		{
			std::cout << quadcopter.isArmed();
		}
		else if (c == 'l')
		{
			quadcopter.land();
		}
		else if (c == 'u')
		{
			quadcopter.liftOff(20);
		}
		else if (c == 'o')
		{
			std::cout << (int)quadcopter.getMode();
		}
	}
}
