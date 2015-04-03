#include "Quadcopter.h"
#include "SerialPort.h"
#include <string>
#include "MAVLinkExchanger.h"
#include <iostream>
#include <thread>
#include <chrono>
#include <conio.h>

const std::chrono::seconds HEARTBEAT_TIMER{ 1 };

void handleInputs();
void heartbeat();

SerialPort serialPort("COM4");
MAVLinkExchanger exchanger{ serialPort };
Quadcopter quadcopter(exchanger);
int altitude = 0;

int main() 
{
	std::thread inputThread{ handleInputs };
	std::thread heartbeatThread{ heartbeat };
	std::thread exchangerThread{ &MAVLinkExchanger::loop, &exchanger};
	exchangerThread.detach();
	inputThread.detach();
	heartbeatThread.join();
}

void handleInputs()
{
	while (1)
	{
		char c = _getch();
		switch (c)
		{
		case 's':
			quadcopter.shutdown();
			break;
		case 'a':
			quadcopter.arm();
			break;
		case 'd':
			quadcopter.disarm();
			break;
		case 'c':
			std::cout << "#########Change the current flight mode#########" << std::endl;
			std::cout << "0 = Stabilize\n1 = Acro\n2 = AltHold\n3 = Auto\n4 = Guided\n5 = Loiter\n6 = RTL\n7 = Circle\n9 = Land\n11 = Drift\n13 = Sport\nNew mode: ";
			int number;
			std::cin >> number;
			quadcopter.changeMode(static_cast<Quadcopter::FlightMode>(number));
			break;
		}
	}
}

void heartbeat()
{
	ExtendedMAVLinkMessage message;
	mavlink_msg_heartbeat_pack(255, 0, &message, MAV_TYPE_GCS, MAV_AUTOPILOT_INVALID, 0, 10, 0);
	auto start = std::chrono::system_clock::now();
	while (1)
	{
		if (std::chrono::system_clock::now() - start >= HEARTBEAT_TIMER)
		{
			exchanger.enqueueMessage(message);
			start = std::chrono::system_clock::now();
		}
	}
}