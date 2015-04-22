/**
*                __
*    _________  / /_  ____  ________  ____________  _____
*   / ___/ __ \/ __ \/ __ \/ ___/ _ \/ ___/ ___/ / / / _ \
*  / /  / /_/ / /_/ / /_/ / /  /  __(__  ) /__/ /_/ /  __/
* /_/   \____/_.___/\____/_/   \___/____/\___/\__,_/\___/
*
*
* @file 			StatusText.h
* @date Created:	-
*
*  @author	-
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
#ifndef _STATUSTEXT_H
#define _STATUSTEXT_H

#include <map>
#include <string>
/**
* StatusText enum for list of status messages able to be returned
*
*/
enum class StatusText                                                          
{
	NONE,

	THROTTLE_ARMED,
	THROTTLE_DISARMED,
	INITIALISING_APM,

	CALIBRATING_BAROMETER,
	BAROMETER_CALIBRATIONS_COMPLETE,
	BAROMETER_NOT_HEALTHY,

	ALTITUDE_DISPARITY,
	AIRSPEED_NOT_HEALTHY,
	BAD_GPS_POSITION,
	LOGGING_NOT_AVAILABLE,                                                     

	GYROS_NOT_HEALTHY,
	GYROS_NOT_CALIBRATED,
	GYROS_INCONSISTENT,

	ACCELS_NOT_HEALTHY,
	AHRS_NOT_HEALTHY,
	ACCELS_NOT_CALIBRATED,
	ACCELS_INCONSISTENT,

	COMPASS_NOT_HEALTHY,
	COMPASS_NOT_CALIBRATED,
	COMPASS_OFFSETS_TOO_HIGH,
	COMPASS_MAGFIELD_TOO_HIGH,
	COMPASS_INCONSISTENT,

	BATTERY_FAILSAFE_ON,
	HARDWARE_SAFETY_SWITCH,
	RADIO_FAILSAFE_ON,

	RC_NOT_CALIBRATED,
	CHECK_BOARD_VOLTAGE,
	CHECK_ANGLE_MAX,
	EKF_HOME_VARIANCE,
	HIGH_GPS_HDOP,
	LEANING,

	THROTTLE_BELOW_FAILSAFE,
	THROTTLE_TOO_HIGH,
	MODE_NOT_ARMABLE,

	UNKNOWN
};
/**
* Map for mapping strings to StatusText messages
*/
const std::map<std::string, StatusText> statusTextMap
{
	{ "None", StatusText::NONE},

	{ "PreArm: Altitude disparity", StatusText::ALTITUDE_DISPARITY },
	{ "Arm: Altitude disparity", StatusText::ALTITUDE_DISPARITY },
	{ "PreArm: airspeed not healthy", StatusText::AIRSPEED_NOT_HEALTHY },
	{ "PreArm: RC not calibrated", StatusText::RC_NOT_CALIBRATED, },
	{ "PreArm: Bad GPS Position", StatusText::BAD_GPS_POSITION },

	{ "PreArm: Check Board Voltage", StatusText::CHECK_BOARD_VOLTAGE },

	{ "PreArm: Check ANGLE_MAX", StatusText::CHECK_ANGLE_MAX },
	{ "PreArm: EKF-home variance", StatusText::EKF_HOME_VARIANCE },
	{ "PreArm: High GPS HDOP", StatusText::HIGH_GPS_HDOP },
	{ "Arm: Leaning", StatusText::LEANING },
	{ "Arm: Throttle below Failsafe", StatusText::THROTTLE_BELOW_FAILSAFE },
	{ "Arm: Throttle too high", StatusText::THROTTLE_TOO_HIGH },

	{ "Arm: Mode not armable", StatusText::MODE_NOT_ARMABLE },
	{ "PreArm: logging not available", StatusText::LOGGING_NOT_AVAILABLE },

	{ "Throttle armed!", StatusText::THROTTLE_ARMED },
	{ "Throttle disarmed!", StatusText::THROTTLE_DISARMED },
	{ "Initialising APM...", StatusText::INITIALISING_APM },

	{ "PreArm: Barometer not healthy!", StatusText::BAROMETER_NOT_HEALTHY },
	{ "PreArm: Barometer not healthy", StatusText::BAROMETER_NOT_HEALTHY },
	{ "Calibrating barometer", StatusText::CALIBRATING_BAROMETER },
	{ "barometer calibration complete", 
		StatusText::BAROMETER_CALIBRATIONS_COMPLETE },

	{ "PreArm: gyros not healthy!", StatusText::GYROS_NOT_HEALTHY },
	{ "PreArm: gyros not calibrated!", StatusText::GYROS_NOT_CALIBRATED },
	{ "PreArm: inconsistent gyros", StatusText::GYROS_INCONSISTENT },
	{ "PreArm: inconsistent Gyros", StatusText::GYROS_INCONSISTENT },

	{ "PreArm: accels not healthy!", StatusText::ACCELS_NOT_HEALTHY },
	{ "PreArm: Accelerometers not healthy", StatusText::ACCELS_NOT_HEALTHY },
	{ "PreArm: AHRS not healthy!" , StatusText::AHRS_NOT_HEALTHY },
	{ "PreArm: 3D accel cal needed", StatusText::ACCELS_NOT_CALIBRATED },
	{ "PreArm: INS not calibrated", StatusText::ACCELS_NOT_CALIBRATED },
	{ "PreArm: inconsistent Accelerometers", StatusText::ACCELS_INCONSISTENT },

	{ "PreArm: Compass not healthy!", StatusText::COMPASS_NOT_HEALTHY },
	{ "PreArm: Compass not healthy", StatusText::COMPASS_NOT_HEALTHY },
	{ "PreArm: Compass not calibrated", StatusText::COMPASS_NOT_CALIBRATED },
	{ "PreArm: Compass offsets too high", 
		StatusText::COMPASS_OFFSETS_TOO_HIGH },
	{ "PreArm: inconsistent compasses", StatusText::COMPASS_INCONSISTENT },
	{ "PreArm: Check mag field", StatusText::COMPASS_MAGFIELD_TOO_HIGH },

	{ "PreArm: Battery failsafe on.", StatusText::BATTERY_FAILSAFE_ON },
	{ "PreArm: Hardware Safety Switch", StatusText::HARDWARE_SAFETY_SWITCH },
	{ "Arm: Safety Switch", StatusText::HARDWARE_SAFETY_SWITCH },
	{ "PreArm: Radio failsafe on", StatusText::RADIO_FAILSAFE_ON },
	{ "Unknown message", StatusText::UNKNOWN }
};


#endif