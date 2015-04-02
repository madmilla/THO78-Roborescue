#include "Quadcopter.h"
#include "SerialPort.h"
#include <string>

int main()
{
	Quadcopter copter;
	std::string s("localhost");
	SerialPort port{ 15440, s };
	while (1)
	{
	}
}