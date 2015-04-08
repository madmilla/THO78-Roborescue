#ifndef _PRIORITYMESSAGE_H
#define _PRIORITYMESSAGE_H
#include "../Dependencies/MAVLink/ardupilotmega/mavlink.h"

class PriorityMessage : public mavlink_message_t
{
public:
	explicit PriorityMessage(mavlink_message_t & msg, char priority);
	PriorityMessage();
	~PriorityMessage();

	friend bool operator<(const PriorityMessage & lhs, const PriorityMessage & rhs);
	char getPriority() const;

	bool getHandled() const;
	void setHandled(const bool h);

private:
	char priority;
	bool handled = true;
};
#endif

