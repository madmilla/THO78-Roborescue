#include "someListener.h"
#include <iostream>
#include "CImg/CImg.h"
#include <bitset>

int pixel = 0;
cimg_library::CImg<unsigned char> image;
std::string imgS = "";
int imageWidth, imageHeight, imageSize;

SomeListener::SomeListener(){
	
}

SomeListener::SomeListener(MavlinkSubject * m){
	m->addListener(this);
	this->m = m;
	//m->addListener(this);
	//m->addListener(this);
	//pX4FlowWrapper = new PX4FlowWrapper();
}
void SomeListener::update(mavlink_message_t* msg){
	
	switch (msg->msgid){
		case MAVLINK_MSG_ID_HEARTBEAT:
		{
			std::cout << "Heartbeat\n";
			mavlink_message_t* msg = pX4FlowWrapper->requestImage(96);
			if (msg != nullptr){
				m->sendMessage(*msg);
			}
		}
		break;
		
		case MAVLINK_MSG_ID_DATA_TRANSMISSION_HANDSHAKE:
			{
				std::cout << "Data transmission handshake -- \n	quality: [" << ((int)mavlink_msg_data_transmission_handshake_get_jpg_quality(msg)) << "]\n	seq: [" << ((int)msg->seq) << "]\n	type: [" << ((int)mavlink_msg_data_transmission_handshake_get_type(msg)) << "]\n	size: [" << ((int)mavlink_msg_data_transmission_handshake_get_size(msg)) << "]\n	packets: [" << ((int)mavlink_msg_data_transmission_handshake_get_packets(msg)) << "]\n	width: [" << ((int)mavlink_msg_data_transmission_handshake_get_width(msg)) << "]\n	height: [" << ((int)mavlink_msg_data_transmission_handshake_get_height(msg)) << "]\n";
				if (imgS!=""){
					image.save(imgS.c_str());
					std::cout << "Saved "<<imgS<<".\n";
				}
				pixel = 0;
				imgS = "img/image";
				imgS += std::to_string(img);
				imgS +=".BMP";
				std::cout << "Creating "<<imgS<<".\n";
				img ++;
				size = mavlink_msg_data_transmission_handshake_get_size(msg);
				imageWidth = mavlink_msg_data_transmission_handshake_get_width(msg);
				imageHeight = mavlink_msg_data_transmission_handshake_get_height(msg);
				imageSize = imageWidth*imageHeight;
				image.assign(imageWidth,imageHeight,1,1);
				std::cout << "Created "<<imgS<<".\n";
			}
		break;
		
		case MAVLINK_MSG_ID_ENCAPSULATED_DATA:
		{
			uint8_t buffer[253];
			mavlink_encapsulated_data_t* data = new mavlink_encapsulated_data_t();
			mavlink_msg_encapsulated_data_decode(msg,data);
			int size = mavlink_msg_encapsulated_data_get_data(msg,buffer);
			std::cout << "frame ["<<size<<"]\n";
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
				pX4FlowWrapper->imageFull();
			}
		}
		break;
		
		case MAVLINK_MSG_ID_DEBUG_VECT:
		case MAVLINK_MSG_ID_OPTICAL_FLOW:
		case MAVLINK_MSG_ID_OPTICAL_FLOW_RAD:
			pX4FlowWrapper->ReceiveMAVLinkMessage(msg);
		break;
		
		default:
			std::cout << "Unknown msgID [" << ((int)msg->msgid) << "]\n";
		break;
	}
	/*mavlink_array_test_0_t* testArray = new mavlink_array_test_0_t();
	mavlink_msg_array_test_0_decode(msg,testArray);
	for (int i = 0; i < 32; i++) {
		std::cout << testArray->ar_c[i];
	}
	std::cout << "]\n";
	delete testArray;*/
}