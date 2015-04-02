#include <string>
#include "SerialPort.h"
#include "TempMAVSender.h"
#include "ATV.h"


int main()
{
	SerialPort port{ "COM8" };
	TempMAVSender mavlinkSender{ port };
	ATV atv{ mavlinkSender };
	while (1)
	{
	}
}