#include "Quadcopter.h"
#include "MAVLinkCommunicator.h"

Quadcopter::Quadcopter(MAVLinkCommunicator& communicator) :
communicator(communicator),
flightMode{ FlightMode::UNKNOWN },
armed{ false }
{
}

void Quadcopter::liftOff(int altitude)
{
	mavlink_msg_command_long_pack(SYSTEMID,
		COMPONENTID,
		&message,
		TARGET_SYSTEMID,
		TARGET_COMPONENTID,
		MAV_CMD_NAV_TAKEOFF,
		UINT16_MIN, 
		UINT16_MIN,
		UINT16_MIN, 
		UINT16_MIN, 
		UINT16_MIN, 
		UINT16_MIN, 
		UINT16_MIN, 
		altitude
		);
	communicator.sendMessage(message);
}

void Quadcopter::arm()
{
	mavlink_msg_command_long_pack(SYSTEMID, 
		COMPONENTID, 
		&message, 
		TARGET_SYSTEMID, 
		TARGET_COMPONENTID, 
		MAV_CMD_COMPONENT_ARM_DISARM, 
		UINT16_MIN, 
		1, 
		UINT16_MIN, 
		UINT16_MIN, 
		UINT16_MIN, 
		UINT16_MIN, 
		UINT16_MIN, 
		UINT16_MIN
		);
	communicator.sendMessage(message);
}

void Quadcopter::disarm()
{
	mavlink_msg_command_long_pack(SYSTEMID, 
		COMPONENTID, 
		&message, 
		TARGET_SYSTEMID, 
		TARGET_COMPONENTID, 
		MAV_CMD_COMPONENT_ARM_DISARM, 
		UINT16_MIN, 
		UINT16_MIN, 
		UINT16_MIN, 
		UINT16_MIN, 
		UINT16_MIN, 
		UINT16_MIN, 
		UINT16_MIN, 
		UINT16_MIN
		);
	communicator.sendMessage(message);
}

void Quadcopter::moveLeft(signed int value)
{
	moveRight(-value);
}

void Quadcopter::moveRight(signed int value)
{
	mavlink_msg_rc_channels_override_pack(SYSTEMID, 
		COMPONENTID, 
		&message, 
		TARGET_SYSTEMID, 
		TARGET_COMPONENTID, 
		MEANVALUELEFTRIGHT+value,
		UINT16_MAX, 
		UINT16_MAX, 
		UINT16_MAX,
		UINT16_MAX, 
		UINT16_MAX, 
		UINT16_MAX, 
		UINT16_MAX
		);
	communicator.sendMessage(message);
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
	mavlink_msg_command_long_pack(SYSTEMID, 
		COMPONENTID, 
		&message, 
		TARGET_SYSTEMID, 
		TARGET_COMPONENTID, 
		MAV_CMD_NAV_LAND, 
		UINT16_MIN, 
		UINT16_MIN, 
		UINT16_MIN, 
		UINT16_MIN, 
		UINT16_MIN, 
		UINT16_MIN, 
		UINT16_MIN, 
		UINT16_MIN
		);
	communicator.sendMessage(message);
}

void Quadcopter::changeFlightSpeed(int)
{
}

void Quadcopter::changeHeading(int value)
{
	mavlink_msg_rc_channels_override_pack(SYSTEMID, 
		COMPONENTID,
		&message, 
		TARGET_SYSTEMID, 
		TARGET_COMPONENTID,
		UINT16_MAX, 
		UINT16_MAX, 
		UINT16_MAX,
		MEANVALUELEFTRIGHT+value,
		UINT16_MAX, 
		UINT16_MAX, 
		UINT16_MAX, 
		UINT16_MAX
		);
	communicator.sendMessage(message);
}

void Quadcopter::changeAltitude(int altitude)
{
	mavlink_msg_command_long_pack(SYSTEMID, 
		COMPONENTID, 
		&message, 
		TARGET_SYSTEMID, 
		TARGET_COMPONENTID, 
		MAV_CMD_NAV_CONTINUE_AND_CHANGE_ALT, 
		UINT16_MIN, 
		UINT16_MIN, 
		UINT16_MIN, 
		UINT16_MIN, 
		UINT16_MIN, 
		UINT16_MIN, 
		UINT16_MIN, 
		altitude
		);
	communicator.sendMessage(message);
}

void Quadcopter::shutdown()
{
	mavlink_msg_command_long_pack(SYSTEMID, 
		COMPONENTID, 
		&message, 
		TARGET_SYSTEMID, 
		TARGET_COMPONENTID, 
		MAV_CMD_PREFLIGHT_REBOOT_SHUTDOWN, 
		UINT16_MIN, 
		TARGET_SYSTEMID, 
		TARGET_COMPONENTID, 
		UINT16_MIN, 
		UINT16_MIN, 
		UINT16_MIN, 
		UINT16_MIN, 
		UINT16_MIN
		);
	communicator.sendMessage(message);
}

void Quadcopter::changeMode(FlightMode mode)
{
	mavlink_msg_set_mode_pack(SYSTEMID, 
		COMPONENTID, 
		&message, 
		TARGET_SYSTEMID, 
		TARGET_COMPONENTID, 
		static_cast<uint32_t>(mode)
		);
	communicator.sendMessage(message);
}

void Quadcopter::loop()
{
	while (true)
	{
		if (communicator.receiveQueueSize())
		{
			handleIncomingMessage(communicator.receiveMessage());
		}
		//calculateRCChannels();
		//exchanger.sendMessage(RCOverrideMessage);
	}
}

void Quadcopter::handleIncomingMessage(PriorityMessage incomingMessage)
{
	//std::cout << "Message!\n";
	receivedMessageMap[incomingMessage.msgid]++;

	switch (incomingMessage.msgid)
	{
		case MAVLINK_MSG_ID_HEARTBEAT:
		{
			flightMode = static_cast<FlightMode>(mavlink_msg_heartbeat_get_custom_mode(&incomingMessage));
			armed = mavlink_msg_heartbeat_get_base_mode(&incomingMessage) & (1 << 7);
			break;
		}
		case MAVLINK_MSG_ID_VFR_HUD:
		{
			altitude = mavlink_msg_vfr_hud_get_alt(&incomingMessage);
			heading = mavlink_msg_vfr_hud_get_heading(&incomingMessage);
			break;
		}
		case MAVLINK_MSG_ID_ATTITUDE:
		{
			roll = mavlink_msg_attitude_get_roll(&incomingMessage);
			pitch = mavlink_msg_attitude_get_pitch(&incomingMessage);
			yaw = mavlink_msg_attitude_get_yaw(&incomingMessage);
			break;
		}
		case MAVLINK_MSG_ID_STATUSTEXT:
		{
			char text[50];
			auto rtn = mavlink_msg_statustext_get_text(&incomingMessage, text);
			auto severity = mavlink_msg_statustext_get_severity(&incomingMessage);

			text[rtn - 1] = '\0';
			if (statusTextMap.count(text) > 0)
			{
				notifyListeners(statusTextMap.at(text));
			}
			else
			{
				notifyListeners(StatusText::UNKNOWN);
			}
			//std::cout << "Severity: " << (int)severity << std::endl;
			break;
		}
		case MAVLINK_MSG_ID_COMMAND_ACK:
		{
			auto command = mavlink_msg_command_ack_get_command(&incomingMessage);
			std::cout << "Ack: " << (int)command << std::endl;
			if (command == MAV_CMD_COMPONENT_ARM_DISARM)
			{
				auto result = mavlink_msg_command_ack_get_result(&incomingMessage);
				std::cout << "Result: " << (int)result << std::endl;
			}
			break;
		}		
	}
	notifyListeners(StatusText::NONE);
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

void Quadcopter::statusTextTest(int s)
{
	notifyListeners((StatusText)s);
}