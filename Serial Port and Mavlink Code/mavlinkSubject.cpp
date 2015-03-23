#include "mavlinkSubject.h"

MavlinkSubject::MavlinkSubject(){
}

void MavlinkSubject::start(IoDevice *ioDevice){
	SP = ioDevice;
}

void MavlinkSubject::stop(){
	
}

void MavlinkSubject::sendMessage(mavlink_message_t & msg){
	unsigned char* buffer =
					new unsigned char[MAVLINK_NUM_NON_PAYLOAD_BYTES
							+ (uint16_t) msg.len];
							
	int length = mavlink_msg_to_send_buffer(buffer, &msg);
	
	sendMutex.lock();
	char* charPBuffer = reinterpret_cast<char*>(buffer);
	SP->writeData(charPBuffer,length);
	sendMutex.unlock();
	
	delete [] buffer;
}

void MavlinkSubject::addListener(MavlinkListener * ml){
	list.push_back(ml);
}

bool MavlinkSubject::update(){
	if (!SP->isConnected()) {
		return false;
	}
	mavlink_message_t  receiveMessage;
	mavlink_status_t  status;

	if (SP->getBufferSize() < 1){
		return true;
	}
	char c;
	SP->readData(&c,1);
	if (mavlink_parse_char(MAVLINK_COMM_0, c, &receiveMessage,&status)) {
		for(MavlinkListener * ml : list){
			ml->update(&receiveMessage);
		} 
	}
	return true;
}