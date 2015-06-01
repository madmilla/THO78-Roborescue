#ifndef MAVLINKLISTENER_H_INCLUDED
#define MAVLINKLISTENER_H_INCLUDED

#include "mavlinkSubject.h"
class MavlinkListener{
	public:
		virtual void update(mavlink_message_t* msg) = 0;
};

#endif