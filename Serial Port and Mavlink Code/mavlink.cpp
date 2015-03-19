#include "mavlink.h"
Mavlink * Mavlink::mavlink = NULL;
Mavlink::Mavlink(){}

Mavlink * Mavlink::getInstance()
{
	if(mavlink == NULL)
		mavlink = new Mavlink(); 
	return mavlink;
}

void Mavlink::start(std::string & portname){
	SP = new Serial(portname);
}

void Mavlink::stop(){
	
}

void Mavlink::addListener(int id,MavlinkListener * ml){
	if(map[id] == NULL){
		map[id] = new std::vector<MavlinkListener *>;
	}
	map[id]->push_back(ml);
}

void Mavlink::update(){
	while (SP->isConnected()) {
			mavlink_message_t receiveMessage;
			mavlink_status_t status;

			if (SP->getBufferSize() < 1){
				continue;
			}

			char c;
			SP->readData(&c,1);
			if (mavlink_parse_char(MAVLINK_COMM_0, c, &receiveMessage,
					&status)) {
				std::vector<MavlinkListener *> vi = *map[receiveMessage.msgid];
				for(MavlinkListener * ml : vi){
					ml->update(&receiveMessage);
				} 
			}
		}
	
}