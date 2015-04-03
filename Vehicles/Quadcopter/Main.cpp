#include "Quadcopter.h"
#include "SerialPort.h"
#include <string>
#include "TempMAVSender.h"
#include <iostream>
#include <thread>
#include <chrono>
#include <conio.h>

const std::chrono::seconds HEARTBEAT_TIMER{ 1 };

void handleInputs();
void heartbeatThread();

SerialPort serialPort("COM7");
TempMAVSender tempMAVSender{ serialPort };
Quadcopter quadcopter(tempMAVSender);
int altitude = 0;

int main() 
{
	std::thread inputThread{ handleInputs };
	std::thread heartbeat{ heartbeatThread };
	heartbeat.detach();
	inputThread.join();
}

void handleInputs()
{
	while (1)
	{
		char c = _getch();
		switch (c)
		{
		case 'o': 
			altitude--;
			quadcopter.changeAltitude(altitude);
			break;
		case 'p':
			altitude++;
			quadcopter.changeAltitude(altitude);
			break;
		case 't':
			quadcopter.liftOff(10);
			break;
		case 'l':
			quadcopter.land();
			break;
		case 's':
			quadcopter.shutdown();
			break;
		case 'a':
			quadcopter.arm();
			break;
		case 'd':
			quadcopter.disarm();
			break;
		case '0':
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':
			quadcopter.changeMode(c - '0');
			break;
		}
	}
}

void heartbeatThread()
{
	mavlink_message_t message;
	mavlink_msg_heartbeat_pack(255, 0, &message, MAV_TYPE_GCS, MAV_AUTOPILOT_INVALID, 0, 0, 0);
	auto start = std::chrono::system_clock::now();
	while (1)
	{
		if (std::chrono::system_clock::now() - start >= HEARTBEAT_TIMER)
		{
			tempMAVSender.sendMessage(message);
			start = std::chrono::system_clock::now();
		}
	}
}