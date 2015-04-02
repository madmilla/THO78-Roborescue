#include "ATV.h"


ATV::ATV(TempMAVSender & mavlinkSender) :
mavlinkSender( mavlinkSender )
{
}


ATV::~ATV()
{
}





void ATV::moveForward()
{
	auto msg = mavlink_message_t();
	mavlink_msg_rc_channels_override_pack(255, 200, &msg, 1, 250, 1460, UINT16_MAX, 1525, UINT16_MAX, UINT16_MAX, UINT16_MAX, UINT16_MAX, UINT16_MAX);
	mavlinkSender.sendMessage(msg);
}