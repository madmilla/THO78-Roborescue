#ifndef _QUADCOPTER_H
#define _QUADCOPTER_H
#include "ExtendedMAVLinkMessage.h"
#include <iostream>

class MAVLinkExchanger;

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
		SPORT = 13,
		UNKNOWN = -1
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
	void shutdown();
	void changeMode(FlightMode);
	friend std::ostream& operator<<(std::ostream& stream, const FlightMode& mode);
	void loop();

	float getYaw() const;
	float getRoll() const;
	float getPitch() const;
	float getAltitude() const;
	int getHeading() const;
	bool isArmed() const;
	FlightMode getMode() const;

private:
	MAVLinkExchanger& exchanger;
	ExtendedMAVLinkMessage message;
	ExtendedMAVLinkMessage RCOverrideMessage;

	FlightMode flightMode;
	bool armed;
	float yaw;
	float roll;
	float pitch;
	float altitude;
	int heading;

	void handleIncomingMessage(ExtendedMAVLinkMessage incomingMessage);
	void calculateRCChannels();

	const int MEANVALUELEFTRIGHT{ 1487 };
};
#endif
