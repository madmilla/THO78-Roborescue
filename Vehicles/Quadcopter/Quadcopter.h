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
#include "PrioritisedMAVLinkMessage.h"
#include "Subject.h"
#include <iostream>
#include <map>
#include <chrono>

class MAVLinkExchanger;

class Quadcopter : public Subject
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

	explicit Quadcopter(MAVLinkExchanger& communicator);
	void liftOff(int);
	/**
	* arm allows the quadcopter to be armed. Sends a message to the quadcopter 
	* to arm the quadcopter.
	* If the quadcopter is armed after the command is sent, it has to be 
	* checked  through isArmed().
	* Status messages can be returned by registering as a Listener to the 
	* QuadCopter - it will send a StatusText message if it fails
	*
	*/
	void arm();
	/**
	* disarm allows the quadcopter to be disarmed. Sends a message to the 
	* quadcopter to disarm the quadcopter.
	* If the quadcopter is disarmed after the command is sent, it has to be 
	* checked through isArmed().
	* Status messages can be returned by registering as a Listener to the 
	* QuadCopter - it will send a StatusText message if it fails
	*/
	void disarm();

	/**
	* moveLeft allows the quadcopter to move to its left. This means the left
	* side of the quadcopter, not relative to the orientation.
	* @param value is a value between -400 and 400. A value between -200 and
	* 200 is suggested. Positive values mean left, negative values mean right.
	* @warning If you put this value beyond the reccomended values (-200 and
	* 200), the quadcopter will bank dangerously far, and will be unable to 
	* maintain altitude. This will most likely result in the quadcopter diving
	* into the ground.
	*/
	void moveLeft(signed int value);

	/**
	* moveRight allows the quadcopter to move to its right. This means the 
	* right side of the quadcopter, not relative to the orientation.
	* @param value is a value between -400 and 400. A value between -200 and
	* 200 is suggested. Positive values mean right, negative values mean left.
	* @warning If you put this value beyond the reccomended values (-200 and
	* 200), the quadcopter will bank dangerously far, and will be unable to
	* maintain altitude. This will most likely result in the quadcopter diving 
	* into the ground.
	*/
	void moveRight(signed int value);
	/**
	* moveForward
	*
	*/
	void moveForward(signed int value);
	/**
	* moveBackward
	*
	*/
	void moveBackward(signed int value);
	/**
	* stop allows the quadcopter to change to ALTHOLD. Overrides the 
	* RC channels in order to set the quadcopter in a stable hovering mode.
	*/
	void stop();

	/**
	* land puts the quadcopter in land flight mode.
	* Documentation about how land mode works can be found at:
	http://copter.ardupilot.com/wiki/flying-arducopter/flight-modes/land-mode/
	*/
	void land();

	/**
	* Not yet implemented
	*/
	void changeFlightSpeed(int);

	/**
	* changeHeading allows the quadcopter to change its heading.
	* @param value is a value between -400 and 400. A value between -200 and
	* 200 is suggested. Positive values means the quadcopter will start turning
	* to the right, negative values means the quadcopter will start turning to
	* the left.
	* @warning If you put this value beyond the recommended values (-200 and
	* 200), the quadcopter will start turning dangerously fast, and will be 
	* unable to stabilize quickly.
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
	friend std::ostream& operator<<(
		std::ostream& stream, 
		const FlightMode& mode);
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

	void statusTextTest(int s);
	
	void setHeading(int targetHeading);

private:
	MAVLinkExchanger& communicator;
	PrioritisedMAVLinkMessage message;
	PrioritisedMAVLinkMessage RCOverrideMessage;
	FlightMode flightMode;
	bool armed;
	float yaw;
	float roll;
	float pitch;
	float altitude;
	int heading;
	const std::chrono::seconds RCHeartbeatInterval{ 1 };
	std::chrono::system_clock::time_point lastRCSent;

	int targetHeading;
	void orient();
	bool orienting = false;
	void setHeadingSpeed(int i);
	
	/**
	* Value of the RC-sticks in neutral position
	*/
	const int MEANVALUELEFTRIGHT{ 1487 };
	const int MEANVALUEPITCH{ 1454 };
	const int SYSTEMID{ 255 };
	const int COMPONENTID{ 0 };
	const int TARGET_SYSTEMID{ 1 };
	const int TARGET_COMPONENTID{ 1 };

	void handleIncomingMessage(PrioritisedMAVLinkMessage incomingMessage);
	void sendRCMessage
		(unsigned int channelOne = UINT16_MAX, 
		unsigned int channelTwo = UINT16_MAX,
		unsigned int channelThree = UINT16_MAX,
		unsigned int channelFour = UINT16_MAX,
		unsigned int channelFive = UINT16_MAX,
		unsigned int channelSix = UINT16_MAX,
		unsigned int channelSeven = UINT16_MAX,
		unsigned int channelEight = UINT16_MAX);
};
#endif