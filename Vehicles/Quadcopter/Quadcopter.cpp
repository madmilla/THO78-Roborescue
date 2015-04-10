#include "Quadcopter.h"
#include "MAVLinkExchanger.h"

Quadcopter::Quadcopter(MAVLinkExchanger& communicator) :
communicator(communicator),
flightMode{ FlightMode::UNKNOWN },
armed{ false }
{
}

void Quadcopter::liftOff(int altitude)
{
	mavlink_msg_command_long_pack(
		SYSTEMID, 
		COMPONENTID,
		&message, 
		TARGET_SYSTEMID, 
		TARGET_COMPONENTID,
		MAV_CMD_NAV_TAKEOFF, 
		0, 
		0,
		0,
		0,
		0,
		0,
		0,
		altitude);
	communicator.enqueueMessage(message);
}

void Quadcopter::arm()
{
	mavlink_msg_command_long_pack(
		SYSTEMID, 
		COMPONENTID, 
		&message, 
		TARGET_SYSTEMID, 
		TARGET_COMPONENTID, 
		MAV_CMD_COMPONENT_ARM_DISARM, 
		0,
		1, 
		0,
		0,
		0,
		0,
		0,
		0);
	communicator.enqueueMessage(message);
}

void Quadcopter::disarm()
{
	mavlink_msg_command_long_pack(
		SYSTEMID, 
		COMPONENTID, 
		&message, 
		TARGET_SYSTEMID, 
		TARGET_COMPONENTID, 
		MAV_CMD_COMPONENT_ARM_DISARM, 
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0);
	communicator.enqueueMessage(message);
}

void Quadcopter::moveLeft(signed int value)
{
	moveRight(-value);
}

void Quadcopter::moveRight(signed int value)
{
	sendRCMessage(MEANVALUELEFTRIGHT + value);
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
	changeMode(FlightMode::LAND);
}

void Quadcopter::changeFlightSpeed(int)
{
	std::cout << "Not yet implemented";
}

void Quadcopter::changeHeading(int value)
{
	sendRCMessage(
		UINT16_MAX, 
		UINT16_MAX, 
		UINT16_MAX, 
		MEANVALUELEFTRIGHT + value);
}

void Quadcopter::changeAltitude(int altitude)
{
	mavlink_msg_command_long_pack(
		SYSTEMID, 
		COMPONENTID,
		&message,
		TARGET_SYSTEMID, 
		TARGET_COMPONENTID,
		MAV_CMD_NAV_CONTINUE_AND_CHANGE_ALT, 
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		altitude);
	communicator.enqueueMessage(message);
}

void Quadcopter::shutdown()
{
	mavlink_msg_command_long_pack(
		SYSTEMID, 
		COMPONENTID, 
		&message, 
		TARGET_SYSTEMID, 
		TARGET_COMPONENTID,
		MAV_CMD_PREFLIGHT_REBOOT_SHUTDOWN, 
		0,
		TARGET_SYSTEMID, 
		TARGET_COMPONENTID, 
		0,
		0,
		0,
		0,
		0);
	communicator.enqueueMessage(message);
}

void Quadcopter::changeMode(FlightMode mode)
{
	mavlink_msg_set_mode_pack(
		SYSTEMID, 
		COMPONENTID, 
		&message,
		TARGET_SYSTEMID, 
		TARGET_COMPONENTID,
		static_cast<uint32_t>(mode));
	communicator.enqueueMessage(message);
}

void Quadcopter::loop()
{
	while (1)
	{
		if (communicator.receiveQueueSize())
		{
			handleIncomingMessage(communicator.dequeueMessage());
		}
		if (std::chrono::system_clock::now() - lastRCSent >= 
			RCHeartbeatInterval)
		{
			sendRCMessage();
		}
	}
}

void Quadcopter::handleIncomingMessage(
	PrioritisedMAVLinkMessage incomingMessage)
{
	//std::cout << "Message!\n";
	receivedMessageMap[incomingMessage.msgid]++;

	switch (incomingMessage.msgid)
	{
	case MAVLINK_MSG_ID_HEARTBEAT:
		{
		flightMode = static_cast<FlightMode>
			(mavlink_msg_heartbeat_get_custom_mode(
				&incomingMessage));
		armed = mavlink_msg_heartbeat_get_base_mode(
			&incomingMessage) & (1 << 7);
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
			auto rtn = mavlink_msg_statustext_get_text(
				&incomingMessage, text);
			auto severity = mavlink_msg_statustext_get_severity(
				&incomingMessage);

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
			auto command = mavlink_msg_command_ack_get_command(
				&incomingMessage);
			std::cout << "Ack: " << (int)command << std::endl;
			if (command == MAV_CMD_COMPONENT_ARM_DISARM)
			{
				auto result = mavlink_msg_command_ack_get_result(
					&incomingMessage);
				std::cout << "Result: " << (int)result << std::endl;
			}
			break;
	}
	}
	notifyListeners(StatusText::NONE);
}

std::ostream& operator<<(std::ostream& stream,
	const Quadcopter::FlightMode& mode)
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

void Quadcopter::sendRCMessage(
	unsigned channelOne,
	unsigned channelTwo,
	unsigned channelThree,
	unsigned channelFour,
	unsigned channelFive,
	unsigned channelSix,
	unsigned channelSeven,
	unsigned channelEight)
{
	mavlink_msg_rc_channels_override_pack(
		SYSTEMID,
		COMPONENTID,
		&message,
		TARGET_SYSTEMID,
		TARGET_COMPONENTID,
		channelOne,
		channelTwo,
		channelThree,
		channelFour,
		channelFive,
		channelSix,
		channelSeven,
		channelEight);
	communicator.enqueueMessage(message);
	lastRCSent = std::chrono::system_clock::now();
}

void Quadcopter::statusTextTest(int s)
{
	notifyListeners((StatusText)s);
}
