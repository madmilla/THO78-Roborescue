#include <iostream>
#include "PX4FlowWrapper.h"
PX4FlowWrapper::PX4FlowWrapper(){
}

void PX4FlowWrapper::ReceiveMAVLinkMessage(mavlink_message_t* msg){
	switch (msg->msgid){
		case MAVLINK_MSG_ID_OPTICAL_FLOW:
			x += mavlink_msg_optical_flow_get_flow_x(msg);
			y += mavlink_msg_optical_flow_get_flow_y(msg);
			std::cout << "Optical flow:[\n" << 
			"X (meters)               - " << mavlink_msg_optical_flow_get_flow_x(msg) << "\n" <<
			"Y (meters)               - " << mavlink_msg_optical_flow_get_flow_y(msg) << "\n" << 
			"X added (meters)         - " << x << "\n" <<
			"Y added (meters)         - " << y << "\n" << 
			"Ground distance (meters) - " << mavlink_msg_optical_flow_get_ground_distance(msg) << "\n" <<
			"]\n";
		break;
		case MAVLINK_MSG_ID_OPTICAL_FLOW_RAD:
			
		break;
		default:
			std::cout << "Unsupported MSG: " << (int)msg->msgid << "\n";
	}
}