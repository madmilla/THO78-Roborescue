#include "ATV.h"
#include <iostream>


ATV::ATV(MAVLinkCommunicator & mavlinkCommunicator) :
mavlinkCommunicator(mavlinkCommunicator)
{
}


ATV::~ATV()
{
}


void ATV::moveForward(int value)
{
	//mavlink_message_t msg;
	int sendValue = 1500 - value;
	mavlink_msg_rc_channels_override_pack(
		255, 200, &message, 1, 250, UINT16_MAX, UINT16_MAX, sendValue,
		UINT16_MAX, UINT16_MAX, UINT16_MAX, UINT16_MAX, UINT16_MAX);
	mavlinkCommunicator.sendMessage(message);
}


void ATV::moveBackward(int value)
{
	//mavlink_message_t msg;
	int sendValue = 1500 + value;
	mavlink_msg_rc_channels_override_pack(
		255, 200, &message, 1, 250, UINT16_MAX, UINT16_MAX, sendValue,
		UINT16_MAX, UINT16_MAX, UINT16_MAX, UINT16_MAX, UINT16_MAX);
	mavlinkCommunicator.sendMessage(message);
}

void ATV::turnLeft(int value)
{//1467
	//turnRight(-value);
	//mavlink_message_t msg;
	int sendValue = 1467 - value;
	mavlink_msg_rc_channels_override_pack(
		255, 200, &message, 1, 1, sendValue, UINT16_MAX, UINT16_MAX,
		UINT16_MAX, UINT16_MAX, UINT16_MAX, UINT16_MAX, UINT16_MAX);
	mavlinkCommunicator.sendMessage(message);
}

void ATV::turnRight(int value)
{
	turnLeft(-value);
	//mavlink_message_t msg;
	int sendValue = 1467 + value;
	mavlink_msg_rc_channels_override_pack(
		255, 200, &message, 1, 1, sendValue, UINT16_MAX, UINT16_MAX,
		UINT16_MAX, UINT16_MAX, UINT16_MAX, UINT16_MAX, UINT16_MAX);
	mavlinkCommunicator.sendMessage(message);
}

void ATV::emergencyStop()
{
	//mavlink_message_t message;
	mavlink_msg_command_long_pack(255, 0, &message, 1, 1, MAV_CMD_PREFLIGHT_REBOOT_SHUTDOWN, 0, 1, 1, 0, 0, 0, 0, 0);
	mavlinkCommunicator.sendMessage(message);
}

void ATV::returnControlToRc()
{
	//mavlink_message_t msg;
	mavlink_msg_rc_channels_override_pack(
		255, 200, &message, 1, 1, 0, 0, 0,
		0, 0, 0, 0, 0);
	mavlinkCommunicator.sendMessage(message);
}

void ATV::loop()
{
	while (1)
	{
		if (mavlinkCommunicator.receiveQueueSize())
		{
			handleIncomingMessage(mavlinkCommunicator.receiveMessage());
		}
		//calculateRCChannels();
		//exchanger.enqueueMessage(RCOverrideMessage);
	}
}

void ATV::handleIncomingMessage(PriorityMessage incomingMessage)
{
	/*switch (incomingMessage.msgid)
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
	}*/
}
