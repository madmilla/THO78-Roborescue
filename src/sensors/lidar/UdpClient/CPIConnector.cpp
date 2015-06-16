#include "CPIConnector.h"

CPIConnector::CPIConnector(){
}

void CPIConnector::onMessage(mavlink_message_t & msg){

	mavlink_ralcp_t function = decodeRalcpMessage(msg);

	switch (function.Function){
		case LIDAR_COMMAND_FUNCTIONS::LIDAR_INIT:
			systemID = function.Payload;
			messages.push(encodeRalcpMessage(uint64_t(COMMAND_DESTINATION::LIDAR), COMMAND_DESTINATION::CPI, LIDAR_COMMAND_FUNCTIONS::LIDAR_INIT ));

			break;

		case LIDAR_COMMAND_FUNCTIONS::LIDAR_GETDEVICE:
			messages.push(encodeRalcpMessage(uint64_t(LIDAR_COMMAND_FUNCTIONS::LIDAR_GETDEVICE), COMMAND_DESTINATION::CPI, LIDAR_COMMAND_FUNCTIONS::LIDAR_GETDEVICE ));
			break;

		case LIDAR_COMMAND_FUNCTIONS::LINEDATA:
			messages.push(encodeRalcpMessage(uint64_t(LIDAR_COMMAND_FUNCTIONS::LINEDATA), COMMAND_DESTINATION::CPI, LIDAR_COMMAND_FUNCTIONS::LINEDATA ));
			break;

		case LIDAR_COMMAND_FUNCTIONS::RPM:
			messages.push(encodeRalcpMessage(uint64_t(LIDAR_COMMAND_FUNCTIONS::RPM), COMMAND_DESTINATION::CPI, LIDAR_COMMAND_FUNCTIONS::RPM ));
			break;

		case LIDAR_COMMAND_FUNCTIONS::START:
			messages.push(encodeRalcpMessage(uint64_t(LIDAR_COMMAND_FUNCTIONS::START), COMMAND_DESTINATION::CPI, LIDAR_COMMAND_FUNCTIONS::START ));
			break;

		case LIDAR_COMMAND_FUNCTIONS::STOP:
			messages.push(encodeRalcpMessage(uint64_t(LIDAR_COMMAND_FUNCTIONS::STOP), COMMAND_DESTINATION::CPI, LIDAR_COMMAND_FUNCTIONS::STOP ));
			break;

		case LIDAR_COMMAND_FUNCTIONS::ROSBEEPOSITION:
			messages.push(encodeRalcpMessage(uint64_t(LIDAR_COMMAND_FUNCTIONS::ROSBEEPOSITION), COMMAND_DESTINATION::CPI, LIDAR_COMMAND_FUNCTIONS::ROSBEEPOSITION ));
			break;

		case LIDAR_COMMAND_FUNCTIONS::ROSBEEFLANK:
			messages.push(encodeRalcpMessage(uint64_t(LIDAR_COMMAND_FUNCTIONS::ROSBEEFLANK), COMMAND_DESTINATION::CPI, LIDAR_COMMAND_FUNCTIONS::ROSBEEFLANK ));
			break;

		default:
			break;
	}

}
