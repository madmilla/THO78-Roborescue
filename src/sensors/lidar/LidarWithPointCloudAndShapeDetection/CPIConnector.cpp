#include "CPIConnector.h"
//This is an example child class
CPIConnector::CPIConnector(){
	lidar = new Lidar("/dev/ttyAMA0");
}

CPIConnector::~CPIConnector(){
	delete lidar;
}

void CPIConnector::onMessage(mavlink_message_t & msg){

	mavlink_lidar_message_t function = decodeLidarMessage(msg);
	int32_t temp[5] = { 1, 1, 1, 1, 1 };

	switch (function.Function){
	case LIDAR_COMMAND_FUNCTIONS::LIDAR_INIT:

		systemID = function.Payload[1];
		sendLidarCommand(temp, COMMAND_DESTINATION::CPI, LIDAR_COMMAND_FUNCTIONS::LIDAR_INIT);
		break;

	case LIDAR_COMMAND_FUNCTIONS::RPM:

		sendLidarCommand(temp, COMMAND_DESTINATION::CPI, LIDAR_COMMAND_FUNCTIONS::RPM);
		break;

	case LIDAR_COMMAND_FUNCTIONS::START:
		for (Line l : lidar->start()){
			int32_t beginPosX = static_cast<int32_t>(l.getLine().begin_pos.x);
			int32_t beginPosY = static_cast<int32_t>(l.getLine().begin_pos.y);
			int32_t endPosX = static_cast<int32_t>(l.getLine().end_pos.x);
			int32_t endPosY = static_cast<int32_t>(l.getLine().end_pos.y);
			int32_t data[5] = { 0, beginPosX, beginPosY, endPosX, endPosY };
			sendLidarCommand(data, COMMAND_DESTINATION::CPI, LIDAR_COMMAND_FUNCTIONS::LINEDATA);
		}
		sendLidarCommand(temp, COMMAND_DESTINATION::CPI, LIDAR_COMMAND_FUNCTIONS::START);
		break;

	case LIDAR_COMMAND_FUNCTIONS::STOP:

		sendLidarCommand(temp, COMMAND_DESTINATION::CPI, LIDAR_COMMAND_FUNCTIONS::STOP);
		break;

	default:
		break;
	}
}