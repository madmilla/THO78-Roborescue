#include <iostream>
#include "Quadcopter.h"
#include "SerialConnection.h"
#include "MAVLinkExchanger.h"
#include "QuadcopterController.h"
#include <boost/asio.hpp>


boost::asio::io_service service;
SerialConnection serialPort { service };
MAVLinkExchanger exchanger { &serialPort };
Quadcopter c{ exchanger };

int main()
{
	return 0;
}