#include "someListener.h"
#include <iostream>
SomeListener::SomeListener(){
	
}

SomeListener::SomeListener(MavlinkSubject * m){
	m->addListener(this);
	m->addListener(this);
	m->addListener(this);
}
void SomeListener::update(mavlink_message_t* msg){
	switch (msg->msgid) {
		case MAVLINK_MSG_ID_ARRAY_TEST_0:
		{
			std::cout << "Test message received. Message content: [";
			mavlink_array_test_0_t* testArray = new mavlink_array_test_0_t();
			mavlink_msg_array_test_0_decode(msg,testArray);
			for (int i = 0; i < 32; i++) {
				std::cout << testArray->ar_c[i];
			}
			std::cout << "]\n";
			delete testArray;
			break;
		}
	}
}