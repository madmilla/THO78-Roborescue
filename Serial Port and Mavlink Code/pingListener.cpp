#include "pingListener.h"
#include <iostream>
#include <sys/time.h>
PingListener::PingListener(){
	
}

PingListener::PingListener(MavlinkSubject * m){
	m->addListener(this);
	this->mavlinkSubject = m;
}

double PingListener::getTimeMillis(){
	struct timeval  tv;
gettimeofday(&tv, NULL);

return
         (tv.tv_sec) * 1000 + (tv.tv_usec) / 1000 ;
}

void PingListener::update(mavlink_message_t* msg){
	switch (msg->msgid) {
		case MAVLINK_MSG_ID_PING:
		{
			mavlink_ping_t* testArray = new mavlink_ping_t();
			mavlink_msg_ping_decode(msg,testArray);
			if (testArray->seq % 2 == 0){
				std::cout << ((int)getTimeMillis()-testArray->time_usec);
				testArray->time_usec = getTimeMillis();
			}
			testArray->seq ++;
			mavlink_msg_ping_encode(1, 2, msg, testArray);
			mavlinkSubject->sendMessage(*msg);
			delete testArray;
			break;
		}
	}
}