#include <string>
#include "SerialPort.h"
#include "TempMAVSender.h"
#include "ATV.h"
#include <iostream>
#include <cstdlib>
#include <thread>
#include <conio.h>

int forward = 0, steer = 0;
bool reset = false;

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
			steer -= 10;
			std::cout << "forward :" << forward << '\n';
			std::cout << "steer :" << steer << '\n';
			break;
		case 's':
			forward--;
			std::cout << "forward :" << forward << '\n';
			std::cout << "steer :" << steer << '\n';
			break;
		case 'd':
			steer += 10;
			std::cout << "forward :" << forward << '\n';
			std::cout << "steer :" << steer << '\n';
			break;
		case 'e':
			exit(0);
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
	SerialPort port{ "COM5" };
	TempMAVSender mavlinkSender{ port };
	ATV atv{ mavlinkSender };
	//atv.emergencyStop();
	std::thread th1(checkforexit);

	while (1)
	{
		atv.turnRight(steer);
		atv.moveForward(forward);
		if (reset)
		{
			atv.returnControlToRc();
			atv.emergencyStop();
		}
	}
}