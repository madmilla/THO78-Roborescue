#include "Quadcopter.h"
#include "../Dependencies/Serial/SerialPort.h"
#include <string>
#include "MAVLinkExchanger.h"
#include <iostream>
#include <thread>
#include <string>

void handleInputs();

SerialPort serialPort("COM4");
MAVLinkExchanger exchanger{ serialPort };
Quadcopter quadcopter(exchanger);
int altitude = 0;

int main() 
{
	std::thread exchangerThread{ &MAVLinkExchanger::loop, &exchanger};
	std::thread quadcopterThread{ &Quadcopter::loop, &quadcopter };
	std::thread inputThread{ handleInputs };
	exchangerThread.detach();
	quadcopterThread.detach();
	inputThread.join();
}

void handleInputs()
{
	std::string command;
	std::cout << "######Quadcopter input menu V1.0######\n";
	std::cout << "Type 'help' for all available commands\n\n";
	while (1)
	{
		std::cout << "\ncommand>: ";
		std::cin >> command;
		if (command == "reboot")
		{
			quadcopter.shutdown();
		}
		else if (command == "arm")
		{
			quadcopter.arm();
		}
		else if (command == "disarm")
		{
			quadcopter.disarm();
		}
		else if (command == "mode")
		{
			std::cout << "\nChange the flight mode" << std::endl;
			std::cout << "0 = Stabilize\n1 = Acro\n2 = AltHold\n3 = Auto\n4 = Guided\n5 = Loiter\n6 = RTL\n7 = Circle\n9 = Land\n11 = Drift\n13 = Sport\nCurrent mode is: " << quadcopter.getMode() << "\nNew mode: ";
			int number;
			std::cin >> number;
			quadcopter.changeMode(static_cast<Quadcopter::FlightMode>(number));
		}
		else if (command == "help")
		{
			std::cout << "\nreboot: Reboot the quadcopter\narm: Arm the quadcopter\ndisarm: Disarm the quadcopter\nmode: Set the new flightmode\n";
		}
		else
		{
			std::cout << "\nUnrecognized command: " << command << std::endl;
		}
	}
}