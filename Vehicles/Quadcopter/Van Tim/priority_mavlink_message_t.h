#ifndef _PRIORITY_MAVLINK_MESSAGE_T_H
#define _PRIORITY_MAVLINK_MESSAGE_T_H
#include "../Dependencies/MAVLink/ardupilotmega/mavlink.h"

class priority_mavlink_message_t
{
public:
	explicit priority_mavlink_message_t(mavlink_message_t message, char priority);
	char getPriority();
	mavlink_message_t* getMessage();
	void setHandled(bool h);
	bool getHandled();
	~priority_mavlink_message_t();

private:
	mavlink_message_t & msg;
	char priority;
	bool handled = true;
};
#endif
