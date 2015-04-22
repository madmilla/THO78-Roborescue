#include "Quadcopter.h"
#include "../Dependencies/Serial/SerialPort.h"
#include <string>
#include "MAVLinkExchanger.h"
#include <iostream>
#include "TempListener.h"
#include <thread>
#include <unistd.h>

SerialPort serialPort("/dev/ttyUSB0");
MAVLinkExchanger communicator{ serialPort };
Quadcopter quadcopter(communicator);

int main() 
{
	TempListener tempListener;
	quadcopter.registerListener(&tempListener);
	std::thread quadcopterLoopThread { &Quadcopter::loop, &quadcopter};
	std::thread communicatorLoopThread{ &MAVLinkExchanger::loop, 
		&communicator };
	quadcopterLoopThread.detach();
	communicatorLoopThread.detach();
	while (!quadcopter.isArmed()){
		quadcopter.arm();
		std::cout << "arm\n";
		sleep(1);
	}
	while (1)
	{
		  unsigned char c;
		  std::cin >> c;
		  quadcopter.setAbsoluteHeading(90);
		  std::cin >> c;
		  quadcopter.setAbsoluteHeading(180);
		  std::cin >> c;
		  quadcopter.setAbsoluteHeading(270);
		  std::cin >> c;
		  quadcopter.setAbsoluteHeading(90);
		  std::cin >> c;
		  quadcopter.setAbsoluteHeading(0);
		  std::cin >> c;
		  quadcopter.changeAbsoluteHeading(90);
		  std::cin >> c;
		  quadcopter.changeAbsoluteHeading(90);
		  std::cin >> c;
		  quadcopter.changeAbsoluteHeading(-270);
		  std::cin >> c;
		  quadcopter.changeAbsoluteHeading(90);
		  std::cin >> c;
		  quadcopter.changeAbsoluteHeading(180);
		  std::cin >> c;
		  quadcopter.changeAbsoluteHeading(-90);
		  std::cin >> c;
		  quadcopter.setAbsoluteHeading(0);
	}
}
