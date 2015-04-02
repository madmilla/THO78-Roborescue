#include "Quadcopter.h"
#include "SerialPort.h"
#include <string>
#include "TempMAVSender.h"
#include <iostream>

int main() 
{
	SerialPort serialPort("/dev/ttyUSB0");
	TempMAVSender tempMAVSender{ serialPort };
	Quadcopter quadcopter(tempMAVSender);
	while (1)
	{
	}
}