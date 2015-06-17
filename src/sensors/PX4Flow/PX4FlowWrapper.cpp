#include <iostream>
#include "PX4FlowWrapper.h"

#define PI 3.1415926535897
#define PXTOMETERS 0.0007
#define GYROTODEGREES (1.f * 360.f / 19.f)

#define DEBUGOPTICAL

PX4FlowWrapper::PX4FlowWrapper(){
}

void PX4FlowWrapper::ReceiveMAVLinkMessage(mavlink_message_t* msg){
	switch (msg->msgid){
		case MAVLINK_MSG_ID_OPTICAL_FLOW:
		{
			int xx = mavlink_msg_optical_flow_get_flow_x(msg);
			int yy = mavlink_msg_optical_flow_get_flow_y(msg);
			double direction = atan2(yy,xx);
			double distance = sqrt(xx*xx+yy*yy);
			direction -= heading * PI / 180;
			double height = mavlink_msg_optical_flow_get_ground_distance(msg);
			x += cos(direction)*distance * PXTOMETERS * height;
			y += sin(direction)*distance * PXTOMETERS * height;
			#ifdef DEBUGOPTICAL
			std::cout << "\n\n\n\n\n\n\n\nOptical flow:[\n" << 
			"Heading                  - " << heading << "\n" <<
			"X added (meters)         - " << x << "\n" <<
			"Y added (meters)         - " << y << "\n" << 
			"Distance                 - " << distance << "\n" << 
			"Direction                - " << direction << "\n" << 
			"Ground distance (meters) - " << height << "\n" <<
			"]\n";
			#endif
		}
		break;
		case MAVLINK_MSG_ID_DEBUG_VECT:
			char name[10];
			mavlink_msg_debug_vect_get_name(msg,name);
			if (strcmp(name, "GYRO") == 0){
				heading += mavlink_msg_debug_vect_get_z(msg) *GYROTODEGREES;//19 seems to be one full rotation, so /19*360 to get degrees.
			}
		break;
		default:
			std::cout << "Unsupported MSG: " << (int)msg->msgid << "\n";
			(void)0;
	}
}

void PX4FlowWrapper::setPosition(double x, double y){
	this->x = x;
	this->y = y;
}

void PX4FlowWrapper::setHeading(double headingInDegrees){
	this->heading = headingInDegrees;
}

float PX4FlowWrapper::getX(){
	return x;
}

float PX4FlowWrapper::getY(){
	return y;
}

double PX4FlowWrapper::getHeadingInDegrees(){
	return heading;
}