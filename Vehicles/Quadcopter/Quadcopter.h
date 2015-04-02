#ifndef _QUADCOPTER_H
#define _QUADCOPTER_H
#include "../Dependencies/MAVLink/ardupilotmega/mavlink.h"
class TempMAVSender;
class SerialPort;

class Quadcopter
{
public:
	explicit Quadcopter(TempMAVSender& tempMAVSender);
	~Quadcopter();
	void liftOff();
	void arm();
	void moveLeft();
	void moveRight();
	void moveForward();
	void moveBackward();
	void stop();
	void land();
	void changeFlightSpeed(int);
	void changeHeading(int);
private:
	TempMAVSender& tempMAVSender;
};
#endif