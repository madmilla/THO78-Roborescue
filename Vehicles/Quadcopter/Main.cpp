#include "Quadcopter.h"
#include "../Dependencies/Serial/SerialPort.h"
#include <string>
#include "MAVLinkCommunicator.h"
#include <iostream>
#include <thread>
int main() 
{
	SerialPort serialPort("COM4");
	MAVLinkCommunicator communicator{ serialPort };
	Quadcopter quadcopter(communicator);
	std::thread quadcopterLoopThread { &Quadcopter::loop, &quadcopter};
	std::thread communicatorLoopThread{ &MAVLinkCommunicator::loop, &communicator };
	quadcopterLoopThread.detach();
	communicatorLoopThread.detach();
	while (1)
	{

	}
}
