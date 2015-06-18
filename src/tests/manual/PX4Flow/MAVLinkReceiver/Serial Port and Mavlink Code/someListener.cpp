#include "someListener.h"
#include <iostream>

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
			mavlink_message_t* msg = pX4FlowWrapper->requestImage();
			if (msg != nullptr){
				m->sendMessage(*msg);
			}
			cimg_library::CImg<unsigned char>* img = nullptr;
			while (img == nullptr){
				img = pX4FlowWrapper->getImage();
			}
			img->save("img/images.BMP");
		}
		break;
		
		case MAVLINK_MSG_ID_DATA_TRANSMISSION_HANDSHAKE:
		case MAVLINK_MSG_ID_ENCAPSULATED_DATA:
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