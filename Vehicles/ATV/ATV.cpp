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
	auto sendValue = neutralthrottleValue - value;
	mavlink_msg_rc_channels_override_pack(
		SYSTEMID,
		COMPONENTID,
		&message,
		TARGET_SYSTEMID,
		TARGET_COMPONENTID,
		UINT16_MAX,
		UINT16_MAX,
		sendValue,
		UINT16_MAX,
		UINT16_MAX,
		UINT16_MAX,
		UINT16_MAX,
		UINT16_MAX);
	mavlinkCommunicator.sendMessage(message);
}


void ATV::moveBackward(int value)
{
	auto sendValue = neutralthrottleValue + value;
	mavlink_msg_rc_channels_override_pack(
		SYSTEMID,
		COMPONENTID,
		&message,
		TARGET_SYSTEMID,
		TARGET_COMPONENTID,
		UINT16_MAX,
		UINT16_MAX,
		sendValue,
		UINT16_MAX,
		UINT16_MAX,
		UINT16_MAX,
		UINT16_MAX,
		UINT16_MAX);
	mavlinkCommunicator.sendMessage(message);
}



void ATV::steer(int value)
{
	steeringDirection = value;
	auto sendValue = neutralSteeringValue + value;
	mavlink_msg_rc_channels_override_pack(
		SYSTEMID,
		COMPONENTID,
		&message,
		TARGET_SYSTEMID,
		TARGET_COMPONENTID,
		sendValue,
		UINT16_MAX,
		UINT16_MAX,
		UINT16_MAX,
		UINT16_MAX,
		UINT16_MAX,
		UINT16_MAX,
		UINT16_MAX);
	mavlinkCommunicator.sendMessage(message);
}

void ATV::shutdown()
{
	mavlink_msg_command_long_pack(SYSTEMID,
		0,
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
	mavlinkCommunicator.sendMessage(message);
}

void ATV::returnControlToRc()
{
	mavlink_msg_rc_channels_override_pack(
		SYSTEMID,
		COMPONENTID,
		&message,
		TARGET_SYSTEMID,
		TARGET_COMPONENTID,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0);
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
		//flightMode = static_cast<FlightMode>(mavlink_msg_heartbeat_get_custom_mode(&incomingMessage));
		break;
	case MAVLINK_MSG_ID_VFR_HUD:
		heading = mavlink_msg_vfr_hud_get_heading(&incomingMessage);
		groundSpeed = mavlink_msg_vfr_hud_get_groundspeed(&incomingMessage);
		break;
	case MAVLINK_MSG_ID_SYS_STATUS:
		batteryRemaining = mavlink_msg_sys_status_get_battery_remaining(&incomingMessage);
		break;

	}
}

float ATV::getHeading(){
	return heading;
}

int ATV::getBatteryRemaining(){
	return batteryRemaining;
}

float ATV::getGroundSpeed(){
	return groundSpeed;
}

int ATV::getSteeringDirection(){
	return steeringDirection;
}
