#include "Quadcopter.h"
#include "../Dependencies/Serial/SerialPort.h"
#include <string>
#include "MAVLinkExchanger.h"
#include <iostream>
#include <thread>
#include <conio.h>
#include <map>

SerialPort serialPort("COM7");
MAVLinkExchanger communicator{ serialPort };
Quadcopter quadcopter(communicator);
std::map<int,int> msgids;
void inputs();

int main() 
{
<<<<<<< HEAD

	//std::thread quadcopterLoopThread { &Quadcopter::loop, &quadcopter};
	std::thread communicatorLoopThread{ &MAVLinkExchanger::loop, &communicator };
	std::thread inputThread{ inputs };
	inputThread.detach();
=======
	SerialPort serialPort("COM5");
	MAVLinkCommunicator communicator{ serialPort };
	Quadcopter quadcopter(communicator);
	std::thread quadcopterLoopThread { &Quadcopter::loop, &quadcopter};
	std::thread communicatorLoopThread{ &MAVLinkCommunicator::loop, &communicator };
	quadcopterLoopThread.detach();
>>>>>>> origin/master
	communicatorLoopThread.detach();
	
	/*while (1)
	{
		if (communicator.receiveQueueSize())
		{
			msgids[communicator.dequeueMessage().msgid] += 1;
		}
	}
}

<<<<<<< HEAD
void inputs()
{
	while (1)
	{
		switch (_getch())
		{
		case 'l':
			for (auto& item : msgids)
			{
				std::cout << "Message: " << (int)item.first << ", " << (int)item.second << " Times" << std::endl;
			}
			std::cout << std::endl;
			break;
		case 'a':
			quadcopter.arm();
			break;
		case 'r':
			quadcopter.shutdown();
			break;
		}
	}
=======
	}*/

	std::cout << "Arming";
	quadcopter.arm();
	std::cout << "Disarming";
	quadcopter.disarm();
>>>>>>> origin/master
}
