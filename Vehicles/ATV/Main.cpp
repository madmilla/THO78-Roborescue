#include <string>
#include "ATV.h"
#include "../Dependencies/Serial/SerialPort.h"
#include <iostream>
#include <cstdlib>
#include <thread>
#include <conio.h>
#include <windows.h>
int movement = 0, steering = 0;
bool reset = false;
bool goExit = false;

void input()
{
	while (1)
	{
		switch (_getch())
		{
		case 'w':
			movement = 1;
			break;
		case 's':
			movement = -1;
			break;
		case 'a':
			steering = -1;
			break;
		case 'd':
			steering = 1;
			break;

		case 'r':
			reset = true;
			break;
		}
	}
}


int main()
{
	SerialPort port{ "COM2" };
	MAVLinkExchanger mavlinkSender{ port };
	ATV atv{ mavlinkSender };
	//atv.emergencyStop();
	std::thread inputThread(input);
	std::thread atvLoopThread{ &ATV::loop, &atv };
	std::thread exchangerLoopThread{ &MAVLinkExchanger::loop, &mavlinkSender };
	atvLoopThread.detach();
	exchangerLoopThread.detach();

	while (1)
	{
		std::cout << "steering: " << steering << " | " << "movement: " << movement << '\n';
		switch (movement)
		{
			case 1:
				atv.moveForward(55);
				movement = 0;
				break;
			case -1:
				atv.moveBackward(55);
				movement = 0;
				break;
			default:
				atv.moveBackward(0);
				break;
	
		}

		switch(steering)
		{
			case -1:
				atv.turnLeft(400);
				steering = 0;
				break;
			case 1:
				atv.turnRight(400);
				steering = 0;
				break;
			default:
				atv.turnLeft(0);
				break;
		}





		Sleep(100);

			
		if (reset)
		{
			atv.returnControlToRc();
			atv.emergencyStop();
			reset = false;
		} 
		if (goExit)
		{
			atv.returnControlToRc();
			exit(0);
		}
	}
}