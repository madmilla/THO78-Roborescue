#include "PrioritisedMAVLinkMessage.h"

PrioritisedMAVLinkMessage::PrioritisedMAVLinkMessage(
	mavlink_message_t & msg, char priority)
{
	mavlink_message_t::operator=(msg);
}

PrioritisedMAVLinkMessage::PrioritisedMAVLinkMessage(mavlink_message_t & msg)
{
	switch (msg.msgid)
	{
	case MAVLINK_MSG_ID_HEARTBEAT:
		priority = _NORMAL_PRIORITY; break;
	case MAVLINK_MSG_ID_RC_CHANNELS_OVERRIDE:
		priority = _HIGH_PRIORITY; break;
	default:
		priority = _NORMAL_PRIORITY; break;
	}
}

PrioritisedMAVLinkMessage::PrioritisedMAVLinkMessage()
{
	priority = -1; // Checking the priority can now indicate
				   // that this is an empty message.
}

PrioritisedMAVLinkMessage::~PrioritisedMAVLinkMessage()
{
}

bool operator<(const PrioritisedMAVLinkMessage & lhs,
	const PrioritisedMAVLinkMessage & rhs)
{
	return lhs.getPriority() < rhs.getPriority();
}

char PrioritisedMAVLinkMessage::getPriority() const
{
	return priority;
}