#include "CPIConnector.h"

//This is an example child class
CPIConnector::CPIConnector(){
	lidar = new Lidar("/dev/ttyAMA0");
}

void CPIConnector::onMessage(mavlink_message_t & msg){

	mavlink_command_long_t function = decodeCommandLongMessage(msg);

	switch (function.command){
		case LIDAR_COMMAND_FUNCTIONS::LIDAR_INIT:

			systemID = function.param1;
			sendCommand<LIDAR_COMMAND_FUNCTIONS>(message, COMMAND_DESTINATION::CPI, LIDAR_COMMAND_FUNCTIONS::LIDAR_INIT );
			break;

		case LIDAR_COMMAND_FUNCTIONS::LIDAR_GETDEVICE:

			sendCommand<LIDAR_COMMAND_FUNCTIONS>(message, COMMAND_DESTINATION::CPI, LIDAR_COMMAND_FUNCTIONS::RPM );
			break;

		case LIDAR_COMMAND_FUNCTIONS::LINEDATA:
			for (Line l : lidar->start()){
				int32_t beginPosX = static_cast<int32_t>(l.getLine().begin_pos.x);
				int32_t beginPosY = static_cast<int32_t>(l.getLine().begin_pos.y);
				int32_t endPosX = static_cast<int32_t>(l.getLine().end_pos.x);
				int32_t endPosY = static_cast<int32_t>(l.getLine().end_pos.y);
				int32_t data[5] = { 0, beginPosX, beginPosY, endPosX, endPosY };
				sendCommand<LIDAR_COMMAND_FUNCTIONS>(data, COMMAND_DESTINATION::CPI, LIDAR_COMMAND_FUNCTIONS::LINEDATA);
			}

			sendCommand<LIDAR_COMMAND_FUNCTIONS>(message, COMMAND_DESTINATION::CPI, LIDAR_COMMAND_FUNCTIONS::START );
			break;

		case LIDAR_COMMAND_FUNCTIONS::RPM:

			sendCommand<LIDAR_COMMAND_FUNCTIONS>(message, COMMAND_DESTINATION::CPI, LIDAR_COMMAND_FUNCTIONS::STOP );
			break;

		default:
			function.param1 += 1;
			sendCommand<LIDAR_COMMAND_FUNCTIONS>(function, COMMAND_DESTINATION::CPI, LIDAR_COMMAND_FUNCTIONS::STOP );
			break;
	}
}
