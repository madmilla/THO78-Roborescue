#include "Quadcopter.h"
#include "MAVLinkExchanger.h"

Quadcopter::Quadcopter(MAVLinkExchanger& exchanger) :
exchanger(exchanger),
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
}

void Quadcopter::moveRight(signed int value)
{
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

bool Quadcopter::isArmed()
{
	return armed;
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

Quadcopter::FlightMode Quadcopter::getMode()
{
	while (1)
	{
		if (exchanger.peek().msgid == MAVLINK_MSG_ID_HEARTBEAT)
		{
			return static_cast<FlightMode>(mavlink_msg_heartbeat_get_custom_mode(&message));
		}
	}
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