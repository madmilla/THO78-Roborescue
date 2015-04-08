#include "PriorityMessage.h"

PriorityMessage::PriorityMessage(mavlink_message_t & msg, char priority)
{
	mavlink_message_t::operator=(msg);
}

PriorityMessage::PriorityMessage(mavlink_message_t & msg)
{
	switch (msg.msgid)
	{
	case MAVLINK_MSG_ID_HEARTBEAT:
		priority = 128; break;
	case MAVLINK_MSG_ID_RC_CHANNELS_OVERRIDE:
		priority = 192; break;
	default:
		priority = 128; break;
	}
}

PriorityMessage::PriorityMessage()
{
	priority = -1;
}

PriorityMessage::~PriorityMessage()
{
}

bool operator<(const PriorityMessage & lhs, const PriorityMessage & rhs)
{
	return lhs.getPriority() < rhs.getPriority();
}

char PriorityMessage::getPriority() const
{
	return priority;
}