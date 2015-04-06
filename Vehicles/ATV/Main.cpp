#include <string>
#include "SerialPort.h"
#include "TempMAVSender.h"
#include "ATV.h"
#include <iostream>
#include <cstdlib>
#include <thread>

void checkforexit()
{
	std::string chars;
	while (1)
	{
		std::cin >> chars;
		if (chars == "exit")
		{
			exit(0);
		}
	}
}

int main()
{
	SerialPort port{ "COM4" };
	TempMAVSender mavlinkSender{ port };
	ATV atv{ mavlinkSender };
	atv.emergencyStop();
	std::thread th1(checkforexit);

	while (1)
	{
		//atv.turnLeft(100);
		//atv.moveForward(20);
	}
}