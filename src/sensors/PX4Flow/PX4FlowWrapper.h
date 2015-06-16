#include "mavlink.h"

class PX4FlowWrapper{
public:
	PX4FlowWrapper();
	void ReceiveMAVLinkMessage(mavlink_message_t* msg);
	void setPosition(double x, double y);
	void setHeading(double headingInDegrees);
	float getX();
	float getY();
	double getHeadingInDegrees();
private:
	float x=0.f,y=0.f;
	float heading=0;
};