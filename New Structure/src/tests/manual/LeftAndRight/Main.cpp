#include "Quadcopter.h"
#include "../Dependencies/Serial/SerialPort.h"
#include <string>
/** Quadcopter Test
* Left and Right Tests
*
* This test was designed for moving the Quadcopter left and/or right
* The values being used are properly the best values for going left and/or right
*/
#include "MAVLinkExchanger.h"
#include <iostream>
#include "TempListener.h"
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
		case 'a':
			std::cout << "Move Left\n";
			quadcopter.moveLeft (100);
			break;
		case 'd':
			std::cout << "Move Right\n";
			quadcopter.moveRight (100);
			break;
		}
	}
}
