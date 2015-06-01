#include "someListener.h"
#include <iostream>
#include "CImg/CImg.h"
				#define IMGSIZE 64
int pixel = 0;
cimg_library::CImg<unsigned char> image(IMGSIZE,IMGSIZE,1,3);
std::string imgS = "";

SomeListener::SomeListener(){
	
}

SomeListener::SomeListener(MavlinkSubject * m){
	m->addListener(this);
	this->m = m;
	//m->addListener(this);
	//m->addListener(this);
}
void SomeListener::update(mavlink_message_t* msg){
	
	switch (msg->msgid){
		case MAVLINK_MSG_ID_HEARTBEAT:
			std::cout << "Heartbeat\n";
		break;
		
		case MAVLINK_MSG_ID_DATA_TRANSMISSION_HANDSHAKE:
			{
				std::cout << "Data transmission handshake -- \n	quality: [" << ((int)mavlink_msg_data_transmission_handshake_get_jpg_quality(msg)) << "]\n	seq: [" << ((int)msg->seq) << "]\n	type: [" << ((int)mavlink_msg_data_transmission_handshake_get_type(msg)) << "]\n	size: [" << ((int)mavlink_msg_data_transmission_handshake_get_size(msg)) << "]\n	packets: [" << ((int)mavlink_msg_data_transmission_handshake_get_packets(msg)) << "]\n	width: [" << ((int)mavlink_msg_data_transmission_handshake_get_width(msg)) << "]\n	height: [" << ((int)mavlink_msg_data_transmission_handshake_get_height(msg)) << "]\n";
				if (imgS!=""){
					image.save(imgS.c_str());
				}
				pixel = 0;
				imgS = "img/image";
				imgS += std::to_string(img);
				imgS +=".BMP";
				std::cout << "Creating "<<imgS<<".\n";
				//image.fill(128);
					
					
				std::cout << "Created "<<imgS<<".\n";
				//m->sendMessage(*msg);
				img ++;
				size = mavlink_msg_data_transmission_handshake_get_size(msg);
			}
		break;
		
		case MAVLINK_MSG_ID_ENCAPSULATED_DATA:
		{
			uint8_t buffer[253];
			mavlink_encapsulated_data_t* data = new mavlink_encapsulated_data_t();
			mavlink_msg_encapsulated_data_decode(msg,data);
			int size = mavlink_msg_encapsulated_data_get_data(msg,buffer);
			std::cout << "frame ["<<size<<"]\n";
			for (int i = 0; i < size; i ++){
				std::cout <<buffer[i];
				if (pixel < IMGSIZE*IMGSIZE){
					image(pixel % IMGSIZE,pixel / IMGSIZE,0,0) = buffer[i]; //R
					image(pixel % IMGSIZE,pixel / IMGSIZE,0,1) = buffer[i]; //G
					image(pixel % IMGSIZE,pixel / IMGSIZE,0,2) = buffer[i]; //B
				}
				pixel++;
			}
			std::cout << "\n";
			//imgFile.write((char*)buffer,size);
		}
		break;
		
		case MAVLINK_MSG_ID_DEBUG_VECT:
			std::cout << "Debug vect -- time_usec:[" << mavlink_msg_debug_vect_get_time_usec(msg)<<"]\n";
		break;
		
		case MAVLINK_MSG_ID_OPTICAL_FLOW:
			std::cout << "Optical flow -- ground distance:["<< mavlink_msg_optical_flow_get_ground_distance(msg) << "]\n";
		break;
		
		case MAVLINK_MSG_ID_OPTICAL_FLOW_RAD:
			std::cout << "Optical flow rad -- ground distance:["<< mavlink_msg_optical_flow_rad_get_distance(msg) << "]\n";
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