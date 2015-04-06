#include <string>
#include "SerialPort.h"
#include "TempMAVSender.h"
#include "ATV.h"
#include <iostream>
#include <cstdlib>
#include <thread>
#include <conio.h>

int forward = 0, steer = 0;

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
			steer++;
			std::cout << "forward :" << forward << '\n';
			std::cout << "steer :" << steer << '\n';
			break;
		case 's':
			forward--;
			std::cout << "forward :" << forward << '\n';
			std::cout << "steer :" << steer << '\n';
			break;
		case 'd':
			steer--;
			std::cout << "forward :" << forward << '\n';
			std::cout << "steer :" << steer << '\n';
			break;
		case 'e':
			exit(0);
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
	SerialPort port{ "COM4" };
	TempMAVSender mavlinkSender{ port };
	ATV atv{ mavlinkSender };
	//atv.emergencyStop();
	std::thread th1(checkforexit);

	while (1)
	{
		atv.turnLeft(steer);
		atv.moveForward(forward);
	}
}