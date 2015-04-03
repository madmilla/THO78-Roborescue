#ifndef _QUADCOPTER_H
#define _QUADCOPTER_H
#include "ExtendedMAVLinkMessage.h"
#include <iostream>

class MAVLinkExchanger;
class TempMAVSender;
class SerialPort;

class Quadcopter
{
public:
	enum class FlightMode
	{
		STABILIZE = 0,
		ACRO = 1,
		ALTHOLD = 2,
		AUTO = 3,
		GUIDED = 4,
		LOITER = 5,
		RTL = 6,
		CIRCLE = 7,
		LAND = 9,
		DRIFT = 11,
		SPORT = 13
	};

	explicit Quadcopter(MAVLinkExchanger& exchanger);
	void liftOff(int);
	void arm();
	void disarm();
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
	void changeAltitude(int);
	bool isArmed();
	void shutdown();
	void changeMode(FlightMode);
	FlightMode getMode();
	friend std::ostream& operator<<(std::ostream& stream, const FlightMode& mode);
private:
	MAVLinkExchanger& exchanger;
	ExtendedMAVLinkMessage message;
	bool armed;
};
#endif