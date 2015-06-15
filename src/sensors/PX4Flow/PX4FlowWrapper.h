#include "mavlink.h"

class PX4FlowWrapper{
public:
	PX4FlowWrapper();
	void ReceiveMAVLinkMessage(mavlink_message_t* msg);
private:
	float x=0.f,y=0.f;
};