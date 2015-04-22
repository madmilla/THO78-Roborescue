#include <string>
#include "ATV.h"
#include "MAVLinkCommunicator.h"
#include "../Dependencies/Serial/SerialPort.h"
#include <iostream>
#include <cstdlib>
#include <thread>
/**
* @author Yorrick Lans
*
* Test program for testing the ATV methods.
*
* CAUTION:
* This program is only for testing the methods of the ATV.
* Do NOT use it to drive around. Put it on its back to test all the methods.
*
* Test the steering of the ATV by either pressing the character 'a' 
* to steer left, pressing the character 'd' to steer right or pressing the
* character ' ' to get the wheels back straight, all require a press of 
* 'enter' to activate.
* Test moving forward and backward by either pressing the character 'w' to
* move forward or the character 's' to move backward, both require a press of
* 'enter' to activate. 
* To stop the ATV moving, press the character 'x' and press 'enter' to activate
* Reset the controller by pressing the 'r' character and press 'enter' to activate
* Press the character 'e' and press 'enter' to exit the program and 
* return the control to the RC.
*
*/

int main()
{
	SerialPort port{ "COM2" };
	MAVLinkCommunicator mavlinkCommunicator{ port };
	ATV atv{ mavlinkCommunicator };
	std::thread atvLoopThread{ &ATV::loop, &atv };
	std::thread communicatorLoopThread{ &MAVLinkCommunicator::loop,
		&mavlinkCommunicator };
	atvLoopThread.detach();
	communicatorLoopThread.detach();

	char c;
	while (1)
	{
		std::cin >> c;

		if (c == 'r')
		{
			std::cout << "reset\n";
			atv.returnControlToRc();
			atv.shutdown();
		}
		else if (c == 'e')
		{
			exit(0);
		}
		else if (c == 'a')
		{
			std::cout << "left\n";
			atv.steer(-300);
		}
		else if (c == 'd')
		{
			std::cout << "right\n";
			atv.steer(300);
		}
		else if (c == ' ')
		{
			std::cout << "straight\n";
			atv.steer(0);
		}
		else if (c == 'w')
		{
			std::cout << "forward\n";
			atv.moveForward(100);
		}
		else if (c == 's')
		{
			std::cout << "backward\n";
			atv.moveBackward(60);
		}
		else if (c == 'x')
		{
			std::cout << "stop\n";
			atv.moveForward(0);
		}
	}
}