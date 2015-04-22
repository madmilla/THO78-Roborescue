#include "Quadcopter.h"
#include "../Dependencies/Serial/SerialPort.h"
#include <string>
/** Quadcopter Test
* Forward and backward Tests
*
* This test was designed for moving the Quadcopter forward and/or backward
* The values being used are properly the best values for going forward and/or backward
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
		case 'w':
			std::cout << "Move Forward\n";
			quadcopter.moveForward (25);
			break;
		case 's':
			std::cout << "Move Backward\n";
			quadcopter.moveBackward (25);
			break;
		}
	}
}
