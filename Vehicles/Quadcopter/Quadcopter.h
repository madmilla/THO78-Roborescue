/*!
* \class Quadcopter
*
* \brief 
* 
*
* \author Kjeld Perquin
* \co-author Feiko Wielsma
* \date April 2015
*/

#ifndef _QUADCOPTER_H
#define _QUADCOPTER_H
#include "ExtendedMAVLinkMessage.h"
#include <iostream>
#include <map>

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

	enum class StatusText
	{
		NONE,
		BAROMETER_NOT_HEALTHY,
		AIRSPEED_NOT_HEALTHY,
		LOGGING_NOT_AVAILABLE,
		GYROS_NOT_HEALTHY,
		GYROS_NOT_CALIBRATED,
		ACCELS_NOT_HEALTHY,
		AHRS_NOT_HEALTHY,
		ACCELS_NOT_CALIBRATED,
		INCONSISTENT_ACCELS,
		INCONSISTENT_GYROS,
		COMPASS_NOT_HEALTHY,
		COMPASS_NOT_CALIBRATED,
		COMPASS_OFFSETS_TOO_HIGH,
		COMPASS_MAGFIELD_TOO_HIGH,
		BAD_GPS_POSITION,
		BATTERY_FAILSAFE_ON,
		HARDWARE_SAFETY_SWITCH,
		RADIO_FAILSAFE_ON,
		THROTTLE_ARMED,
		THROTTLE_DISARMED
	};

	explicit Quadcopter(MAVLinkExchanger& exchanger);
	/**
	* liftOff allows the quadcopter to take off. 
	*
	*/
	void liftOff(int);
	/**
	* arm allows the quadcopter to be armed.
	*
	*/
	void arm();
	/**
	* disarm allows the quadcopter to be disarmed.
	*
	*/
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
	/**
	* moveForward
	*
	*/
	void moveForward();
	/**
	* moveBackward
	*
	*/
	void moveBackward();
	/**
	* stop
	*
	*/
	void stop();
	/**
	* land
	*
	*/
	void land();
	/**
	* changeFlightSpeed
	*
	*/
	void changeFlightSpeed(int);
	/**
	* changeHeading
	*
	*/
	void changeHeading(int);
	/**
	* changeAltitude
	*
	*/
	void changeAltitude(int);
	/**
	* shutdown
	*
	*/
	void shutdown();
	/**
	* changeMode
	*
	*/
	void changeMode(FlightMode);
	/**
	* operator<<
	*
	*/
	friend std::ostream& operator<<(std::ostream& stream, const FlightMode& mode);
	/**
	* loop
	*
	*/
	void loop();

	float getYaw() const;
	float getRoll() const;
	float getPitch() const;
	float getAltitude() const;
	int getHeading() const;
	bool isArmed() const;
	FlightMode getMode() const;
	std::map<int, int> receivedMessageMap;

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
