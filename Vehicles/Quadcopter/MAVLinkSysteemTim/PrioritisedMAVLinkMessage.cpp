#include "PrioritisedMAVLinkMessage.h"

PrioritisedMAVLinkMessage::PrioritisedMAVLinkMessage(mavlink_message_t & msg, char priority)
{
	mavlink_message_t::operator=(msg);
}

PrioritisedMAVLinkMessage::PrioritisedMAVLinkMessage(mavlink_message_t & msg)
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

PrioritisedMAVLinkMessage::PrioritisedMAVLinkMessage()
{
	priority = -1;
}

PrioritisedMAVLinkMessage::~PrioritisedMAVLinkMessage()
{
}

bool operator<(const PrioritisedMAVLinkMessage & lhs, const PrioritisedMAVLinkMessage & rhs)
{
	return lhs.getPriority() < rhs.getPriority();
}

char PrioritisedMAVLinkMessage::getPriority() const
{
	return priority;
}