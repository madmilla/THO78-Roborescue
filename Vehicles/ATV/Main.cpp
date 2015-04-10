#include <string>
#include "ATV.h"
#include "MAVLinkCommunicator.h"
#include "../Dependencies/Serial/SerialPort.h"
#include <iostream>
#include <cstdlib>
#include <thread>
#include <conio.h>
#include <windows.h>


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


	while (1)
	{
		if (GetAsyncKeyState(VK_RETURN) || GetAsyncKeyState(0x52)){
			std::cout << "reset\n";
			atv.returnControlToRc();
			atv.shutdown();
		}
		if (GetAsyncKeyState(0x45)){
			exit(0);
		}


		if (GetAsyncKeyState(VK_LEFT)){
			std::cout << "left\n";
			atv.steer(-300);
		}
		else if (GetAsyncKeyState(VK_RIGHT)){
			std::cout << "right\n";
			atv.steer(300);
		}
		else{
			std::cout << "straight\n";
			atv.steer(0);
		}

		if (GetAsyncKeyState(VK_UP)){
			std::cout << "forward\n";
			atv.moveForward(100);
		}
		else if (GetAsyncKeyState(VK_DOWN)){
			std::cout << "backward\n";
			atv.moveBackward(60);
		}
		else{
			std::cout << "stop\n";
			atv.moveForward(0);
		}
		std::cout << "Heading: " << atv.getHeading() << "\n";
		std::cout << "Steer Direction: "<<atv.getSteeringDirection() << "\n";
		std::cout << "Battery Remaining: " << 
			atv.getBatteryRemaining() << "\n";
		std::cout << "GroundSpeed: " << atv.getGroundSpeed() << "\n";

		Sleep(100);
	}
}