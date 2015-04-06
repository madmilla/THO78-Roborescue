#include "Quadcopter.h"
#include "../Dependencies/Serial/SerialPort.h"
#include <string>
#include "MAVLinkExchanger.h"
#include <iostream>

int main() 
{
	SerialPort serialPort("COM4");
	MAVLinkExchanger exchanger{ serialPort };
	Quadcopter quadcopter(exchanger);
	while (1)
	{

	}
}