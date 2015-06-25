#include <iostream>
#include "Quadcopter.h"
#include "SerialPort.h"
#include "MAVLinkExchanger.h"

SerialPort serialPort { "bla" };
MAVLinkExchanger exchanger { serialPort };
Quadcopter c{ exchanger };

int main()
{
	return 0;
}