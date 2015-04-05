#include <string>
#include "SerialPort.h"
#include "TempMAVSender.h"
#include "ATV.h"


int main()
{
	SerialPort port{ "COM9" };
	TempMAVSender mavlinkSender{ port };
	ATV atv{ mavlinkSender };
	
	while (1)
	{
		atv.moveForward();
	}
}