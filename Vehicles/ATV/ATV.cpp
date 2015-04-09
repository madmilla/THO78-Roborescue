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


void ATV::steer(int value)
{
	//mavlink_message_t msg;
	steerDirection = value;
	int sendValue = 1467 + value;
	mavlink_msg_rc_channels_override_pack(
		255, 200, &message, 1, 1, sendValue, UINT16_MAX, UINT16_MAX,
		UINT16_MAX, UINT16_MAX, UINT16_MAX, UINT16_MAX, UINT16_MAX);
	mavlinkCommunicator.sendMessage(message);
}

void ATV::reset()
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
	switch (incomingMessage.msgid)
	{
	case MAVLINK_MSG_ID_HEARTBEAT:
		flightMode = static_cast<FlightMode>(mavlink_msg_heartbeat_get_custom_mode(&incomingMessage));
		break;
	case MAVLINK_MSG_ID_VFR_HUD:
		heading = mavlink_msg_vfr_hud_get_heading(&incomingMessage);
		groundspeed = mavlink_msg_vfr_hud_get_groundspeed(&incomingMessage);
		break;
	case MAVLINK_MSG_ID_BATTERY_STATUS:
		batteryRemaining = mavlink_msg_battery_status_get_battery_remaining(&incomingMessage);
		break;
	}
}
