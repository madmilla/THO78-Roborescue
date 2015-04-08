#include <string>
#include "ATV.h"
#include "../Dependencies/Serial/SerialPort.h"
#include <iostream>
#include <cstdlib>
#include <thread>
#include <conio.h>
#include <windows.h>
int forward = 0, steer = 0;
bool reset = false;
bool goExit = false;
void checkforexit()
{
	std::string chars;
	while (1)
	{
		switch (_getch())
		{
		case 'w':
			forward++;
			std::cout << "forward :" << forward << '\n';
			std::cout << "steer :" << steer << '\n';
			break;
		case 'a':
			steer = -400;
			std::cout << "forward :" << forward << '\n';
			std::cout << "steer :" << steer << '\n';
			break;
		case 's':
			forward--;
			std::cout << "forward :" << forward << '\n';
			std::cout << "steer :" << steer << '\n';
			break;
		case 'd':
			steer = 400;
			std::cout << "forward :" << forward << '\n';
			std::cout << "steer :" << steer << '\n';
			break;
		case ' ':
			steer = 0;
			std::cout << "forward :" << forward << '\n';
			std::cout << "steer :" << steer << '\n';
			break;
		case 'e':
			goExit = true;
			break;
		case 'r':
			reset = true;
			break;
		}
		/*std::cin >> chars;
		if (chars == "exit")
		{
			exit(0);
		}
		if (chars == "w")
		{
			forward++;
		}
		if (chars == "s")
		{
			forward--;
		}
		if (chars == "a")
		{
			steer++;
		}
		if (chars == "d")
		{
			steer--;
		}
		std::cout << "forward :" << forward << '\n';
		std::cout << "steer :" << steer << '\n';*/
	}
}

int main()
{
	SerialPort port{ "COM1" };
	MAVLinkExchanger mavlinkSender{ port };
	ATV atv{ mavlinkSender };
	//atv.emergencyStop();
	std::thread th1(checkforexit);
	std::thread atvLoopThread{ &ATV::loop, &atv };
	std::thread exchangerLoopThread{ &MAVLinkExchanger::loop, &mavlinkSender };
	atvLoopThread.detach();
	exchangerLoopThread.detach();

	while (1)
	{
		atv.turnRight(steer);
		atv.moveForward(forward);
		Sleep(1);	
		if (reset)
		{
			atv.returnControlToRc();
			atv.emergencyStop();
		} 
		if (goExit)
		{
			atv.returnControlToRc();
			exit(0);
		}
	}
}