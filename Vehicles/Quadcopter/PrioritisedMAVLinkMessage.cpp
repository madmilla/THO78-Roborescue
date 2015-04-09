#include "PrioritisedMAVLinkMessage.h"
#include <iostream>
#include <algorithm>

PrioritisedMAVLinkMessage::PrioritisedMAVLinkMessage(const mavlink_message_t& baseMessage):
timeCreated{ std::chrono::system_clock::now() }
{
	mavlink_message_t::operator=(baseMessage);
}

PrioritisedMAVLinkMessage::PrioritisedMAVLinkMessage()
{
	msgid = -1;
}

bool operator<(const PrioritisedMAVLinkMessage& lhs, const PrioritisedMAVLinkMessage& rhs)
{
	return lhs.getPriority() < rhs.getPriority();
}

PrioritisedMAVLinkMessage::Priority PrioritisedMAVLinkMessage::getPriority() const
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

std::ostream& operator<<(std::ostream& stream, const PrioritisedMAVLinkMessage::Priority& priority)
{
	switch (priority)
	{
	case PrioritisedMAVLinkMessage::Priority::LOW_PRIORITY: 
		stream << "LOW PRIORITY";
		break;
	case PrioritisedMAVLinkMessage::Priority::MEDIUM_PRIORITY: 
		stream << "MEDIUM PRIORITY";
		break;
	case PrioritisedMAVLinkMessage::Priority::HIGH_PRIORITY: 
		stream << "HIGH PRIORITY";
		break;
	case PrioritisedMAVLinkMessage::Priority::EXTREME_PRIORITY: 
		stream << "EXTREME PRIORITY";
		break;
	default: 
		stream << "UNKNOWN";
		break;
	}
	return stream;
}