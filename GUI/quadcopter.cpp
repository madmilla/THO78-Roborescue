#include "Quadcopter.h"
#include "MAVLinkExchanger.h"

Quadcopter::Quadcopter(MAVLinkExchanger& exchanger) :
exchanger(exchanger),
flightMode{ FlightMode::UNKNOWN },
armed{ false }
{
}

void Quadcopter::liftOff(int altitude)
{
	mavlink_msg_command_long_pack(255, 0, &message, 1, 1, MAV_CMD_NAV_TAKEOFF, 0, 0, 0, 0, 0, 0, 0, altitude);
	exchanger.enqueueMessage(message);
}

void Quadcopter::arm()
{
	mavlink_msg_command_long_pack(255, 0, &message, 1, 1, MAV_CMD_COMPONENT_ARM_DISARM, 0, 1, 0, 0, 0, 0, 0, 0);
	exchanger.enqueueMessage(message);
}

void Quadcopter::disarm()
{
	mavlink_msg_command_long_pack(255, 0, &message, 1, 1, MAV_CMD_COMPONENT_ARM_DISARM, 0, 0, 0, 0, 0, 0, 0, 0);
	exchanger.enqueueMessage(message);
}

void Quadcopter::moveLeft(signed int value)
{
	moveRight(-value);
}

void Quadcopter::moveRight(signed int value)
{
	mavlink_msg_rc_channels_override_pack(255, 1, &message, 1 , 1, MEANVALUELEFTRIGHT+value,UINT16_MAX, UINT16_MAX, UINT16_MAX,UINT16_MAX, UINT16_MAX, UINT16_MAX, UINT16_MAX);
	exchanger.enqueueMessage(message);
}

void Quadcopter::moveForward()
{
}

void Quadcopter::moveBackward()
{
}

void Quadcopter::stop()
{
}

void Quadcopter::land()
{
	mavlink_msg_command_long_pack(255, 0, &message, 1, 1, MAV_CMD_NAV_LAND, 0, 0, 0, 0, 0, 0, 0, 0);
	exchanger.enqueueMessage(message);
}

void Quadcopter::changeFlightSpeed(int)
{
}

void Quadcopter::changeHeading(int)
{
}

void Quadcopter::changeAltitude(int altitude)
{
	mavlink_msg_command_long_pack(255, 0, &message, 1, 1, MAV_CMD_NAV_CONTINUE_AND_CHANGE_ALT, 0, 0, 0, 0, 0, 0, 0, altitude);
	exchanger.enqueueMessage(message);
}

void Quadcopter::shutdown()
{
	mavlink_msg_command_long_pack(255, 0, &message, 1, 1, MAV_CMD_PREFLIGHT_REBOOT_SHUTDOWN, 0, 1, 1, 0, 0, 0, 0, 0);
	exchanger.enqueueMessage(message);
}

void Quadcopter::changeMode(FlightMode mode)
{
	mavlink_msg_set_mode_pack(255, 0, &message, 1, 1, static_cast<uint32_t>(mode));
	exchanger.enqueueMessage(message);
}

void Quadcopter::loop()
{
	while (1)
	{
		if (exchanger.receiveQueueSize())
		{
			handleIncomingMessage(exchanger.dequeueMessage());
		}
		//calculateRCChannels();
		//exchanger.enqueueMessage(RCOverrideMessage);
	}
}

void Quadcopter::handleIncomingMessage(ExtendedMAVLinkMessage incomingMessage)
{
	switch (incomingMessage.msgid)
	{
	case MAVLINK_MSG_ID_HEARTBEAT:
		flightMode = static_cast<FlightMode>(mavlink_msg_heartbeat_get_custom_mode(&incomingMessage));
		armed = mavlink_msg_heartbeat_get_base_mode(&incomingMessage) & (1 << 7);
		break;
	case MAVLINK_MSG_ID_VFR_HUD:
		altitude = mavlink_msg_vfr_hud_get_alt(&incomingMessage);
		heading = mavlink_msg_vfr_hud_get_heading(&incomingMessage);
		break;
	case MAVLINK_MSG_ID_ATTITUDE:
		roll = mavlink_msg_attitude_get_roll(&incomingMessage);
		pitch = mavlink_msg_attitude_get_pitch(&incomingMessage);
		yaw = mavlink_msg_attitude_get_yaw(&incomingMessage);
		break;
	}
	notifyListeners();
}

void Quadcopter::calculateRCChannels()
{
	//Do some calculations to determine the new RC channel values
}

std::ostream& operator<<(std::ostream& stream, const Quadcopter::FlightMode& mode)
{
	switch (mode)
	{
	case Quadcopter::FlightMode::STABILIZE:
		stream << "Stabilize";
		break;
	case Quadcopter::FlightMode::ACRO:
		stream << "Acro";
		break;
	case Quadcopter::FlightMode::ALTHOLD:
		stream << "AltHold";
		break;
	case Quadcopter::FlightMode::AUTO:
		stream << "Auto";
		break;
	case Quadcopter::FlightMode::GUIDED:
		stream << "Guided";
		break;
	case Quadcopter::FlightMode::LOITER:
		stream << "Loiter";
		break;
	case Quadcopter::FlightMode::RTL:
		stream << "RTL";
		break;
	case Quadcopter::FlightMode::CIRCLE:
		stream << "Circle";
		break;
	case Quadcopter::FlightMode::LAND:
		stream << "Land";
		break;
	case Quadcopter::FlightMode::DRIFT:
		stream << "Drift";
		break;
	case Quadcopter::FlightMode::SPORT:
		stream << "Sport";
		break;
	default:
		stream << "UNKNOWN";
		break;
	}
	return stream;
}

float Quadcopter::getYaw() const
{
	return yaw;
}

float Quadcopter::getRoll() const
{
	return roll;
}

float Quadcopter::getPitch() const
{
	return pitch;
}

float Quadcopter::getAltitude() const
{
	return altitude;
}

int Quadcopter::getHeading() const
{
	return heading;
}

bool Quadcopter::isArmed() const
{
	return armed;
}

Quadcopter::FlightMode Quadcopter::getMode() const
{
	return flightMode;
}
