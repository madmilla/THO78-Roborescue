#include "CPIConnector.h"

//This is an example child class
CPIConnector::CPIConnector(){}

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
