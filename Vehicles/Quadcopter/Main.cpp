#include "Quadcopter.h"
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
	}
}