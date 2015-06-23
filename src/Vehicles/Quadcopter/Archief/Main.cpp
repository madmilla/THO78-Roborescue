#include "Quadcopter.h"
#include "../Dependencies/Serial/SerialPort.h"
#include <string>
#include "MAVLinkExchanger.h"
#include <iostream>
#include <thread>
#include <conio.h>

SerialPort serialPort("COM7");
MAVLinkExchanger communicator{ serialPort };
Quadcopter quadcopter(communicator);

int main() 
{
	std::thread quadcopterLoopThread { &Quadcopter::loop, &quadcopter};
	std::thread communicatorLoopThread{ &MAVLinkExchanger::loop,
		&communicator };
	quadcopterLoopThread.detach();
	communicatorLoopThread.detach();
	while (1)
	{
		switch (_getch())
		{
		case 'u':
			quadcopter.changeAltitude(5);
			break;
		case 'd':
			quadcopter.changeAltitude(1);
			break;
		case 'l':
			quadcopter.land();
			break;
		case 'h':
			quadcopter.changeMode(Quadcopter::FlightMode::ALTHOLD);
			break;
		case 's':
			quadcopter.saveQuadcopter();
			break;
		case 'r':
			quadcopter.restart();
			break;
		case 'a':
			quadcopter.arm();
			break;
		case 'q':
			quadcopter.disarm();
			break;
		}
	}
}
