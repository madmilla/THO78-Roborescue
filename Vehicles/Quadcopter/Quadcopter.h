#ifndef _QUADCOPTER_H
#define _QUADCOPTER_H
#include "../Dependencies/MAVLink/ardupilotmega/mavlink.h"
class SerialPort;

class Quadcopter
{
public:
	void sendMessage(mavlink_message_t & msg);
	
	Quadcopter(SerialPort& serialPort);
	~Quadcopter();
	void liftOff();
	void arm();
	void moveLeft(signed int value);
	void moveRight(signed int value);
	void moveForward();
	void moveBackward();
	void stop();
	void land();
	void changeFlightSpeed(int);
	void changeHeading(int);
private:
	SerialPort& serialPort;
};
#endif