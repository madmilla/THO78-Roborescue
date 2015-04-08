#include "PriorityMessage.h"

PriorityMessage::PriorityMessage(mavlink_message_t & msg, char priority)
{
	mavlink_message_t::operator=(msg);
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

bool PriorityMessage::getHandled() const
{
	return handled;
}

void PriorityMessage::setHandled(const bool h)
{
	handled = h;
}
