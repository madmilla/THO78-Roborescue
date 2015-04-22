#include <string>
#include "ATV.h"
#include "MAVLinkCommunicator.h"
#include "../Dependencies/Serial/SerialPort.h"
#include <iostream>
#include <cstdlib>
#include <thread>

int main()
{
	SerialPort port{ "COM2" };
	MAVLinkCommunicator mavlinkCommunicator{ port };
	ATV atv{ mavlinkCommunicator };
	std::thread atvLoopThread{ &ATV::loop, &atv };
	std::thread communicatorLoopThread{ &MAVLinkCommunicator::loop,
		&mavlinkCommunicator };
	atvLoopThread.detach();
	communicatorLoopThread.detach();

	char c;
	while (1)
	{
		std::cin >> c;

		if (c == 'r')
		{
			std::cout << "reset\n";
			atv.returnControlToRc();
			atv.shutdown();
		}
		else if (c == 'e')
		{
			exit(0);
		}
		else if (c == 'a')
		{
			std::cout << "left\n";
			atv.steer(-300);
		}
		else if (c == 'd')
		{
			std::cout << "right\n";
			atv.steer(300);
		}
		else if (c == ' ')
		{
			std::cout << "straight\n";
			atv.steer(0);
		}
		else if (c == 'w')
		{
			std::cout << "forward\n";
			atv.moveForward(100);
		}
		else if (c == 's')
		{
			std::cout << "backward\n";
			atv.moveBackward(60);
		}
		else if (c == 'x')
		{
			std::cout << "stop\n";
			atv.moveForward(0);
		}
		std::cout << "Heading: " << atv.getHeading() << "\n";
		std::cout << "Steer Direction: " << atv.getSteeringDirection() << "\n";
		std::cout << "Battery Remaining: " << 
			atv.getBatteryRemaining() << "\n";
		std::cout << "GroundSpeed: " << atv.getGroundSpeed() << "\n";

		Sleep(100);
	}
}