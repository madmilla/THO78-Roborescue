#include "ATV.h"
#include <iostream>


ATV::ATV(TempMAVSender & mavlinkSender) :
mavlinkSender(mavlinkSender)
{
}


ATV::~ATV()
{
}


void ATV::moveForward(int value)
{
	mavlink_message_t msg;
	int sendValue = 1500 + value;
	mavlink_msg_rc_channels_override_pack(
		255, 200, &msg, 1, 250, UINT16_MAX, UINT16_MAX, sendValue,
		UINT16_MAX, UINT16_MAX, UINT16_MAX, UINT16_MAX, UINT16_MAX);
	mavlinkSender.sendMessage(msg);
}

void ATV::moveBackward()
{

}

void ATV::turnLeft(int value)
{//1467
	//turnRight(-value);
	mavlink_message_t msg;
	int sendValue = 1467 - value;
	mavlink_msg_rc_channels_override_pack(
		255, 200, &msg, 1, 1, sendValue, UINT16_MAX, UINT16_MAX,
		UINT16_MAX, UINT16_MAX, UINT16_MAX, UINT16_MAX, UINT16_MAX);
	mavlinkSender.sendMessage(msg);
}

void ATV::turnRight(int value)
{
	turnLeft(-value);
	mavlink_message_t msg;
	int sendValue = 1467 + value;
	mavlink_msg_rc_channels_override_pack(
		255, 200, &msg, 1, 1, sendValue, UINT16_MAX, UINT16_MAX,
		UINT16_MAX, UINT16_MAX, UINT16_MAX, UINT16_MAX, UINT16_MAX);
	mavlinkSender.sendMessage(msg);
}

void ATV::emergencyStop()
{
	mavlink_message_t message;
	mavlink_msg_command_long_pack(255, 0, &message, 1, 1, MAV_CMD_PREFLIGHT_REBOOT_SHUTDOWN, 0, 1, 1, 0, 0, 0, 0, 0);
	mavlinkSender.sendMessage(message);
}

void ATV::returnControlToRc()
{
	mavlink_message_t msg;
	mavlink_msg_rc_channels_override_pack(
		255, 200, &msg, 1, 1, 0, 0, 0,
		0, 0, 0, 0, 0);
	mavlinkSender.sendMessage(msg);
}