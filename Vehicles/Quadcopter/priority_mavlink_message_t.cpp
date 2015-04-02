#include "priority_mavlink_message_t.h"


priority_mavlink_message_t::priority_mavlink_message_t(mavlink_message_t & message, char priority) :
msg{ message },
priority{priority}
{
}

char priority_mavlink_message_t::getPriority()
{
	return priority;
}

mavlink_message_t priority_mavlink_message_t::getMessage()
{
	return msg;
}

void priority_mavlink_message_t::setHandled(bool h)
{
	handled = h;
}

bool priority_mavlink_message_t::getHandled()
{
	return handled;
}

priority_mavlink_message_t::~priority_mavlink_message_t()
{
}
