#include "Quadcopter.h"
#include "SerialPort.h"
#include <string>

int main()
{
	SerialPort port{ "COM4" };
	Quadcopter copter{ port };
	while (1)
	{
	}
}