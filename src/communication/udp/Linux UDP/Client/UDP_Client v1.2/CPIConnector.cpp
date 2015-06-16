#include "CPIConnector.h"

//This is an example child class
CPIConnector::CPIConnector(){
}

void CPIConnector::onMessage(mavlink_message_t & msg){

	mavlink_ralcp_t function = decodeRalcpMessage(msg);

	switch (function.Function){
		case LIDAR_COMMAND_FUNCTIONS::LIDAR_INIT:

			systemID = function.Payload;
			sendCommand(uint64_t(70), COMMAND_DESTINATION::CPI, LIDAR_COMMAND_FUNCTIONS::LIDAR_INIT );
			break;

		case LIDAR_COMMAND_FUNCTIONS::RPM:

			sendCommand(uint64_t(LIDAR_COMMAND_FUNCTIONS::RPM), COMMAND_DESTINATION::CPI, LIDAR_COMMAND_FUNCTIONS::RPM );
			break;

		case LIDAR_COMMAND_FUNCTIONS::START:

			sendCommand(uint64_t(LIDAR_COMMAND_FUNCTIONS::START), COMMAND_DESTINATION::CPI, LIDAR_COMMAND_FUNCTIONS::START );
			break;

		case LIDAR_COMMAND_FUNCTIONS::STOP:

			sendCommand(uint64_t(LIDAR_COMMAND_FUNCTIONS::STOP), COMMAND_DESTINATION::CPI, LIDAR_COMMAND_FUNCTIONS::STOP );
			break;

		default:
			break;
	}
}
