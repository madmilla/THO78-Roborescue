#ifndef _QUADCOPTER_H
#define _QUADCOPTER_H
#include "../Dependencies/MAVLink/ardupilotmega/mavlink.h"
class TempMAVSender;
class SerialPort;

class Quadcopter
{
public:
	explicit Quadcopter(TempMAVSender& tempMAVSender);
	void liftOff();
	void arm();
	/**
	* moveLeft allows the quadcopter to move to it's left. This means the left side of the quadcopter, not relative to the orientation.
	* @param value is a value between -400 and 400. A value between -200 and 200 is suggested. Positive values mean left, negative values mean right.
	* @warning If you put this value beyond the reccomended values (-200 and 200), the quadcopter will bank dangerously far, and will be unable to maintain altitude. This will most likely result in the quadcopter diving into the ground.
	*/
	void moveLeft(signed int value);

	/**
	* moveRight allows the quadcopter to move to it's right. This means the right side of the quadcopter, not relative to the orientation.
	* @param value is a value between -400 and 400. A value between -200 and 200 is suggested. Positive values mean right, negative values mean left.
	* @warning If you put this value beyond the reccomended values (-200 and 200), the quadcopter will bank dangerously far, and will be unable to maintain altitude. This will most likely result in the quadcopter diving into the ground.
	*/
	void moveRight(signed int value);
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