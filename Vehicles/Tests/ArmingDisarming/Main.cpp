#include "Quadcopter.h"
#include "../../Dependencies/Serial/SerialPort.h"
#include <string>
#include "MAVLinkExchanger.h"
#include <iostream>
#include "StatusMessageListener.h"
#include <thread>
/**
* @author Feiko Wielsma
*
* Test program for testing if the quadcopter arms and disarms.
* Common usage is arming('a'), then issueing the isArmed() command ('g').
* If it returns 1, the quad is armed, if it returns 0, the quad is disarmed.
* When finishing test the disarm ('d') function and test isArmed() again.
*
*/
int main() 
{
	SerialPort serialPort("COM6");
	MAVLinkExchanger communicator{ serialPort };
	Quadcopter quadcopter(communicator);
	
	//Make a tempListener to test if the quad notifies correctly
	StatusMessageListener statusMessageListener;
	quadcopter.registerListener(&statusMessageListener);
	
	std::thread quadcopterLoopThread { &Quadcopter::loop, &quadcopter};
	std::thread communicatorLoopThread{ &MAVLinkExchanger::loop, &communicator };
	quadcopterLoopThread.detach();
	communicatorLoopThread.detach();
	
	while (1)
	{
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
	}
}