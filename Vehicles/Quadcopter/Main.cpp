#include "Quadcopter.h"
<<<<<<< HEAD
#include "SerialPort.h"
#include <string>
#include "TempMAVSender.h"

int main()
{
	SerialPort port{ "COM4" };
	TempMAVSender mavlinkSender{ port };
	Quadcopter copter{ mavlinkSender };
	while (1)
	{
=======
#include "SerialPort.h" 
#include <unistd.h>
#include <iostream>

int main() {
	SerialPort serialPort("/dev/ttyUSB0");
	Quadcopter quadcopter(serialPort);
	while (1){
		std::cout << "moveLeft\n";
		quadcopter.moveLeft (400);
		sleep(300000);
		std::cout << "moveRight\n";
		quadcopter.moveRight (400);
		sleep(300000);
>>>>>>> LeftRight-Translation
	}
}