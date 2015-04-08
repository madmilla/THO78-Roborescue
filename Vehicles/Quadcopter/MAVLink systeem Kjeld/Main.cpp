#include "Quadcopter.h"
#include "../Dependencies/Serial/SerialPort.h"
#include <string>
#include "MAVLinkExchanger.h"
#include <iostream>
#include <thread>
int main() 
{
	SerialPort serialPort("COM4");
	MAVLinkExchanger exchanger{ serialPort };
	Quadcopter quadcopter(exchanger);
	std::thread quadcopterLoopThread { &Quadcopter::loop, &quadcopter};
	std::thread exchangerLoopThread { &MAVLinkExchanger::loop, &exchanger};
	quadcopterLoopThread.detach();
	exchangerLoopThread.detach();
	while (1)
	{

	}
}
