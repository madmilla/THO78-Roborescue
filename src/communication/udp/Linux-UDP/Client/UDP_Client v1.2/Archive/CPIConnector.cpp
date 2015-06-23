#include "CPIConnector.h"

//This is an example child class
CPIConnector::CPIConnector(){}

void CPIConnector::onMessage(mavlink_message_t & msg){

	mavlink_lidar_message_t function = decodeLidarMessage(msg);
	int32_t temp[5] = {1, 1, 1, 1, 1};

	switch (function.Function){
		case LIDAR_COMMAND_FUNCTIONS::LIDAR_INIT:

			systemID = function.Payload[1];
			sendLidarCommand(temp, COMMAND_DESTINATION::CPI, LIDAR_COMMAND_FUNCTIONS::LIDAR_INIT );
			break;

		case LIDAR_COMMAND_FUNCTIONS::RPM:

			sendLidarCommand(temp, COMMAND_DESTINATION::CPI, LIDAR_COMMAND_FUNCTIONS::RPM );
			break;

		case LIDAR_COMMAND_FUNCTIONS::START:

			sendLidarCommand(temp, COMMAND_DESTINATION::CPI, LIDAR_COMMAND_FUNCTIONS::START );
			break;

		case LIDAR_COMMAND_FUNCTIONS::STOP:

			sendLidarCommand(temp, COMMAND_DESTINATION::CPI, LIDAR_COMMAND_FUNCTIONS::STOP );
			break;

		default:
			break;
	}
}
