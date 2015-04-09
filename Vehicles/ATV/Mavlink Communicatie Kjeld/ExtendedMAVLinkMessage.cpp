#include "ExtendedMAVLinkMessage.h"
#include <iostream>
#include <algorithm>

ExtendedMAVLinkMessage::ExtendedMAVLinkMessage(const mavlink_message_t& baseMessage):
timeCreated{ std::chrono::system_clock::now() }
{
	mavlink_message_t::operator=(baseMessage);
}

ExtendedMAVLinkMessage::ExtendedMAVLinkMessage()
{
	msgid = -1;
}

bool operator<(const ExtendedMAVLinkMessage& lhs, const ExtendedMAVLinkMessage& rhs)
{
	return lhs.getPriority() < rhs.getPriority();
}

ExtendedMAVLinkMessage::Priority ExtendedMAVLinkMessage::getPriority() const
{
	if (std::find(std::begin(EXTREME_PRIORITIES), std::end(EXTREME_PRIORITIES), msgid) != std::end(EXTREME_PRIORITIES))
	{
		return Priority::EXTREME_PRIORITY;
	}
	if (std::find(std::begin(HIGH_PRIORITIES), std::end(HIGH_PRIORITIES), msgid) != std::end(HIGH_PRIORITIES))
	{
		return Priority::HIGH_PRIORITY;
	}
	if (std::find(std::begin(MEDIUM_PRIORITIES), std::end(MEDIUM_PRIORITIES), msgid) != std::end(MEDIUM_PRIORITIES))
	{
		return Priority::MEDIUM_PRIORITY;
	}
	return Priority::LOW_PRIORITY;
}

std::ostream& operator<<(std::ostream& stream, const ExtendedMAVLinkMessage::Priority& priority)
{
	switch (priority)
	{
	case ExtendedMAVLinkMessage::Priority::LOW_PRIORITY: 
		stream << "LOW PRIORITY";
		break;
	case ExtendedMAVLinkMessage::Priority::MEDIUM_PRIORITY: 
		stream << "MEDIUM PRIORITY";
		break;
	case ExtendedMAVLinkMessage::Priority::HIGH_PRIORITY: 
		stream << "HIGH PRIORITY";
		break;
	case ExtendedMAVLinkMessage::Priority::EXTREME_PRIORITY: 
		stream << "EXTREME PRIORITY";
		break;
	default: 
		stream << "UNKNOWN";
		break;
	}
	return stream;
}