/**
*                __
*    _________  / /_  ____  ________  ____________  _____
*   / ___/ __ \/ __ \/ __ \/ ___/ _ \/ ___/ ___/ / / / _ \
*  / /  / /_/ / /_/ / /_/ / /  /  __(__  ) /__/ /_/ /  __/
* /_/   \____/_.___/\____/_/   \___/____/\___/\__,_/\___/
*
*
* @file 			Quadcopter.h
* @date Created:	01-04-2015
*
*  @author	Kjeld Perquin
*  @author	-
*
*  @section LICENSE
*  License:	newBSD
*
*  Copyright © 2015, HU University of Applied Sciences Utrecht.
* 		All rights reserved.
*
*
*
*	Redistribution and use in source and binary forms,
*	with or without modification, are permitted provided that
*	the following conditions are met:
*	- Redistributions of source code must retain the above copyright notice,
*	  this list of conditions and the following disclaimer.
*	- Redistributions in binary form must reproduce the above copyright notice,
*	  this list of conditions and the following disclaimer in the documentation
*	  and/or other materials provided with the distribution.
*	- Neither the name of the HU University of Applied Sciences Utrecht
*	  nor the names of its contributors may be used to endorse or
*	  promote products derived from this software without
*	  specific prior written permission.
*
*   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
*   "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING,
*	BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY
*	AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
*	IN NO EVENT SHALL THE HU UNIVERSITY OF APPLIED SCIENCES UTRECHT
*   BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
*   CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
*	PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
*	OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
*	OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
*	(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
*	OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
**/

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
	
	/**
	* FlightMode an enumclass containing different flightmodes.
	* 
	*/
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

	/**
	* Quadcopter explicit
	*
	*/
	explicit Quadcopter(MAVLinkExchanger& communicator);

	/**
	* liftOff allows the quadcopter to be liftoff to a specified altitude
	* It will lift off to the passed parameter, and hold its altitude when it 
	* has reached that altitude
	* @param The altitude the quadcopter should rise to
	*
	*/
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
	* moveForward allows the quadcopter to move forward in relation to its
	* orientation.
	* @param value 
	*/
	void moveForward(signed int value);

	/**
	* moveBackward allows the quadcopter to move backward in relation to its
	* orientation.
	* @param value 
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
	*http://copter.ardupilot.com/wiki/flying-arducopter/flight-modes/land-mode/
	*/
	void land();

	/**
	* Not yet implemented
	*
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
	* holdAltitude allows the quadcopter to hold its current altitude
	* Ensures the quadcopter won't move up or down anymore, and just hover at 
	* its current height
	*/
	void holdAltitude();

	/**
	* changeAltitude allows the quadcopter to change its altitude.
	* Sets a new target altitude, and commands the rotors to move upwards or
	* backwards. 
	* @param the new target altitude where the quadcopter should move to.
	*/
	void changeAltitude(float);

	/**
	* restart allows the quadcopter to be restarted.
	* 
	*/
	void restart();

	/**
	* changeMode allows the quadcopter flightmode to be altered
	*
	*/
	void changeMode(FlightMode);
	
	/**
	* operator<< an overloaded shift operator 
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

	/**
	* getYaw 
	*
	*/
	float getYaw() const;

	/**
	* getRoll 
	*
	*/
	float getRoll() const;
	
	/**
	* getPitch 
	*
	*/
	float getPitch() const;

	/**
	* getAltitude 
	*
	*/
	float getAltitude() const;
	
	/**
	* getHeading 
	*
	*/
	int getHeading() const;

	/**
	* isArmed 
	*
	*/
	bool isArmed() const;
	
	/**
	* getMode
	*
	*/
	FlightMode getMode() const;
	
	/**
	* receivedMessageMap
	*
	*/
	std::map<int, int> receivedMessageMap;

	/**
	* statusTextTest
	*
	*/
	void statusTextTest(int s);

	/**
	* setAbsoluteHeading
	*
	*/
	void setAbsoluteHeading(int targetHeading);
	
	/**
	* changeAbsoluteHeading
	*
	*/
	void changeAbsoluteHeading(int headingDifference);

	/**
	* saveQuadcopter
	*
	*/
	void saveQuadcopter();

private:
	
	/**
	* communicator
	*
	*/
	MAVLinkExchanger& communicator;
	
	/**
	* message
	*
	*/
	PrioritisedMAVLinkMessage message;
	
	/**
	* RCOverrideMessage
	*
	*/
	PrioritisedMAVLinkMessage RCOverrideMessage;
	
	/**
	* flightmode
	*
	*/
	FlightMode flightMode;
	
	/**
	* armed
	*
	*/
	bool armed;
	
	/**
	* yaw
	*
	*/
	float yaw;
	
	/**
	* roll
	*
	*/
	float roll;
	
	/**
	* pitch
	*
	*/
	float pitch;
	
	/**
	* altitude
	*
	*/
	float altitude;
	
	/**
	* heading
	*
	*/
	int heading;
	
	/**
	* RCHeartbeatInterval
	*
	*/
	const std::chrono::seconds RCHeartbeatInterval{ 1 };
	
	/**
	* lastRCsent
	*
	*/
	std::chrono::system_clock::time_point lastRCSent;

	/**
	* channelThreeLow
	*
	*/
	const int channelThreeLow{ 1077 };
	
	/**
	* channelThreeHigh
	*
	*/
	const int channelThreeHigh{ 1902 };
	
	/**
	* targetAltitude
	*
	*/
	float targetAltitude;
	
	/**
	* ascending
	*
	*/
	bool ascending;
	
	/**
	* descending
	*
	*/
	bool descending;
	
	/**
	* failsafe
	*
	*/
	bool failsafe;

	/**
	* targetHeading
	*
	*/
	int targetHeading;
	
	/**
	* orient
	*
	*/
	void orient();
	
	/**
	* orienting
	*
	*/
	bool orienting = false;
	
	/**
	* setHeadingStreamSpeed
	*
	*/
	void setHeadingStreamSpeed(int i);
	
	/**
	* MEANVALUELEFTRIGHT
	* Value of the RC-sticks in neutral position
	*/
	const int MEANVALUELEFTRIGHT{ 1487 };
	
	/**
	* SYSTEMID
	* 
	*/
	const int SYSTEMID{ 255 };
	
	/**
	* COMPONENTID
	*
	*/
	const int COMPONENTID{ 0 };
	
	/**
	* TARGET_SYSTEMID
	*
	*/
	const int TARGET_SYSTEMID{ 1 };
	
	/**
	* TARGET_COMPONENTID
	*
	*/
	const int TARGET_COMPONENTID{ 1 };

	/**
	* MAX_PERCENTAGE
	*
	*/
	const int MAX_PERCENTAGE{ 100 };
	
	/**
	* ASCEND_PERCENTAGE
	*
	*/
	const int ASCEND_PERCENTAGE{ 75 };
	
	/**
	* HOLD_PERCENTAGE
	*
	*/
	const int HOLD_PERCENTAGE{ 50 };
	
	/**
	* DESCEND_PERCENTAGE
	*
	*/
	const int DESCEND_PERCENTAGE{ 25 };

	/**
	* incomingMessage
	*
	*/
	void handleIncomingMessage(PrioritisedMAVLinkMessage incomingMessage);
	
	/**
	* sendRCMessage
	*
	*/
	void sendRCMessage
		(unsigned int channelOne = UINT16_MAX, 
		unsigned int channelTwo = UINT16_MAX,
		unsigned int channelThree = UINT16_MAX,
		unsigned int channelFour = UINT16_MAX,
		unsigned int channelFive = UINT16_MAX,
		unsigned int channelSix = UINT16_MAX,
		unsigned int channelSeven = UINT16_MAX,
		unsigned int channelEight = UINT16_MAX);

	/**
	* TrimValues
	* A struct containing ..
	*/
	struct TrimValues
	{
		int CHANNEL_ONE_LOW;
		int CHANNEL_ONE_HIGH;
		int CHANNEL_TWO_LOW;
		int CHANNEL_TWO_HIGH;
		int CHANNEL_THREE_LOW;
		int CHANNEL_THREE_HIGH;
		int CHANNEL_FOUR_LOW;
		int CHANNEL_FOUR_HIGH;
		int CHANNEL_FIVE_LOW;
		int CHANNEL_FIVE_HIGH;
		int CHANNEL_SIX_LOW;
		int CHANNEL_SIX_HIGH;
		int CHANNEL_SEVEN_LOW;
		int CHANNEL_SEVEN_HIGH;
		int CHANNEL_EIGHT_LOW;
		int CHANNEL_EIGHT_HIGH;
	} RCTrimValues;
};
#endif
