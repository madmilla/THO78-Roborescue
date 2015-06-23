#include <iostream>
#include "PX4FlowWrapper.h"

#define PI 3.1415926535897
#define PXTOMETERS 0.0007
#define GYROTODEGREES (1.f * 360.f / 19.f)

int pixel = 0;

//#define DEBUGOPTICAL
//#define DEBUGIMAGES

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
		case MAVLINK_MSG_ID_DATA_TRANSMISSION_HANDSHAKE:
			{
				#ifdef DEBUGIMAGES
				std::cout << "Data transmission handshake -- \n	quality: [" << ((int)mavlink_msg_data_transmission_handshake_get_jpg_quality(msg)) << "]\n	seq: [" << ((int)msg->seq) << "]\n	type: [" << ((int)mavlink_msg_data_transmission_handshake_get_type(msg)) << "]\n	size: [" << ((int)mavlink_msg_data_transmission_handshake_get_size(msg)) << "]\n	packets: [" << ((int)mavlink_msg_data_transmission_handshake_get_packets(msg)) << "]\n	width: [" << ((int)mavlink_msg_data_transmission_handshake_get_width(msg)) << "]\n	height: [" << ((int)mavlink_msg_data_transmission_handshake_get_height(msg)) << "]\n";
				#endif
				pixel = 0;
				size = mavlink_msg_data_transmission_handshake_get_size(msg);
				imageWidth = mavlink_msg_data_transmission_handshake_get_width(msg);
				imageHeight = mavlink_msg_data_transmission_handshake_get_height(msg);
				imageSize = imageWidth*imageHeight;
				image.assign(imageWidth,imageHeight,1,1);
			}
		break;
		
		case MAVLINK_MSG_ID_ENCAPSULATED_DATA:
		{
			uint8_t buffer[253];
			mavlink_encapsulated_data_t* data = new mavlink_encapsulated_data_t();
			mavlink_msg_encapsulated_data_decode(msg,data);
			int size = mavlink_msg_encapsulated_data_get_data(msg,buffer);
			#ifdef DEBUGIMAGES
			std::cout << "frame ["<<size<<"]\n";
			#endif
			for (unsigned int i = 0; i < size; i ++){
				unsigned char px = buffer[i];
				for (unsigned int a = 0; a < 8; a++){
					if (pixel < imageSize){
						image(pixel % imageWidth,pixel / imageWidth,0,0) = (px & (1<<7)?255:0);//((buffer[i]>>a)&&1 != 0)*255; //R
						px <<= 1;
						pixel++;
					}
				}
			}
			if (pixel >= imageSize){
				#ifdef DEBUGIMAGES
					std::cout << "Image full.\n";
				#endif
				imageFull();
			}
		}
		break;
		
		default:
			//std::cout << "Unsupported MSG: " << (int)msg->msgid << "\n";
			(void)0;
	}
}

void PX4FlowWrapper::setHeading(double headingInDegrees){
	this->heading = headingInDegrees;
}

double PX4FlowWrapper::getHeadingInDegrees(){
	return heading;
}

mavlink_message_t* PX4FlowWrapper::requestImage(){
	if (isImageRequested()){
		return nullptr;
	}
	imageRequested = true;
	imageReady = false;
	
	mavlink_message_t* msg = new mavlink_message_t();

	mavlink_msg_param_set_pack(SYSTEMID, COMPONENTID, msg, PX4FLOWSYSTEMID, PX4FLOWCOMPONENTID, "USB_SEND_VIDEO", true, true);
	return msg;
}
	
bool PX4FlowWrapper::isImageRequested(){
	return imageRequested;
}

bool PX4FlowWrapper::isImageReady(){
	return imageReady;
}

cv::Mat* PX4FlowWrapper::getImage(){
	if (!isImageRequested() || !isImageRequested()){
		return nullptr;
	}
	imageReady = false;
	imageRequested = false;
	return getImage();
}

void PX4FlowWrapper::imageFull(){
	imageRequested = false;
	imageReady = true;
	//provideImage<cimg_library::CImg>(image,ImageType::CIMG);
}