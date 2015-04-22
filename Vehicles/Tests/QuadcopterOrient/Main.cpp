/**
 * @file Main.cpp
 * @author Daniel van den Berg
 * 
 * Use this program to test the Quadcopter::orient() function. This program will first arm the quad copter, and then wait for a keypress followed by an enter.
 * The quad copter will try to lock on heading 90. After that it waits for another input, before locking onto heading 180. This'll continue as you can see in the while loop.
 * For testing, using the testing rig is reccomended. 
 * When flying outdoors you'll have to control the altitude and position yourself, which is pretty much impossible when the quadcopter changes heading.
 */

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
