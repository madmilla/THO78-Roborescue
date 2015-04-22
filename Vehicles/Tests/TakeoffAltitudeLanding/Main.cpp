#include "Quadcopter.h"
#include "../../Dependencies/Serial/SerialPort.h"
#include <string>
#include "MAVLinkExchanger.h"
#include <iostream>
#include "StatusMessageListener.h"
#include <thread>
/**
* @author Kjeld Perquin
* @author Feiko Wielsma
*
* Test program for testing if the quadcopter correctly takes off, 
* changes altitude and lands.
* Is also a test for the changeMode and saveQuadcopter commands.
* Common usage is arming('a') the quadcopter, lifting off('o'), 
* changing altitude to 5('u') and 1('d') meters and landing('l') again.
*
* SaveQuadcopter('s') is used to give all control back to 
* the radio control operator
*
* changeMode(with parameter althold)('h') is used to 
* put the quad in althold 
*
*/
int main() 
{
	SerialPort serialPort("COM6");
	MAVLinkExchanger communicator{ serialPort };
	Quadcopter quadcopter(communicator);
	
	//Make a tempListener to test if the quad notifies correctly
	StatusMessageListener statusMessageListener;
	quadcopter.registerListener(&tempListener);
	
	std::thread quadcopterLoopThread { &Quadcopter::loop, &quadcopter};
	std::thread communicatorLoopThread{ &MAVLinkExchanger::loop, &communicator };
	quadcopterLoopThread.detach();
	communicatorLoopThread.detach();
	
	while (1)
	{
		char c;
		std::cin >> c;
		
		switch (c)
		{
		case 'u':
			quadcopter.changeAltitude(5);
			break;
		case 'd':
			quadcopter.changeAltitude(1);
			break;
		case 'o':
			quadcopter.liftOff(10);
			break;
		case 'l':
			quadcopter.land();
			break;
		case 'h':
			quadcopter.changeMode(Quadcopter::FlightMode::ALTHOLD);
			break;
		case 's':
			quadcopter.saveQuadcopter();
			break;
		case 'r':
			quadcopter.restart();
			break;
		case 'a':
			quadcopter.arm();
			break;
		case 'q':
			quadcopter.disarm();
			break;
		}
	}
}