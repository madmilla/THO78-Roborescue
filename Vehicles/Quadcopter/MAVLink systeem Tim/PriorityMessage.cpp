#include "PriorityMessage.h"

PriorityMessage::PriorityMessage(mavlink_message_t & msg, char priority)
{
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

mavlink_message_t * PriorityMessage::getMessage() const
{
	return message;
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
