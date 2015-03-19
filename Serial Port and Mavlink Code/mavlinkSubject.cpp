#include "mavlinkSubject.h"

MavlinkSubject::MavlinkSubject(){
}

void MavlinkSubject::start(std::string & portname){
	std::cout << portname;
	SP = new Serial(portname);
}

void MavlinkSubject::stop(){
	
}

void MavlinkSubject::addListener(MavlinkListener * ml){
	list.push_back(ml);
}

void MavlinkSubject::update(){
	while (SP->isConnected()) {
			mavlink_message_t  receiveMessage;
			mavlink_status_t  status;

			if (SP->getBufferSize() < 1){
				continue;
			}
			char c;
			SP->readData(&c,1);
			if (mavlink_parse_char(MAVLINK_COMM_0, c, &receiveMessage,&status)) {
				for(MavlinkListener * ml : list){
					ml->update(&receiveMessage);
				} 
			}
		}
	
}