#include <string>
#include "ATV.h"
#include "../Dependencies/Serial/SerialPort.h"
#include <iostream>
#include <cstdlib>
#include <thread>
#include <conio.h>
#include <windows.h>


int main()
{
	SerialPort port{ "COM2" };
	MAVLinkExchanger mavlinkSender{ port };
	ATV atv{ mavlinkSender };
	//atv.emergencyStop();
	std::thread atvLoopThread{ &ATV::loop, &atv };
	std::thread exchangerLoopThread{ &MAVLinkExchanger::loop, &mavlinkSender };
	atvLoopThread.detach();
	exchangerLoopThread.detach();


	while (1)
	{
		if (GetAsyncKeyState(VK_RETURN)){
			std::cout << "reset\n";
			atv.returnControlToRc();
			atv.emergencyStop();
		}


		if (GetAsyncKeyState(VK_LEFT)){
			std::cout << "left\n";
			atv.turnLeft(300);
		}
		else if (GetAsyncKeyState(VK_RIGHT)){
			std::cout << "right\n";
			atv.turnRight(300);
		}
		else{
			//std::cout << "straight\n";
			atv.turnRight(0);
		}

		if (GetAsyncKeyState(VK_UP)){
			std::cout << "forward\n";
			//atv.moveForward(60);
		}
		else if (GetAsyncKeyState(VK_DOWN)){
			std::cout << "backward\n";
			//atv.moveBackward(60);
		}
		else{
			std::cout << "stop\n";
			//atv.moveForward(0);
		}


		Sleep(10);
	}
}