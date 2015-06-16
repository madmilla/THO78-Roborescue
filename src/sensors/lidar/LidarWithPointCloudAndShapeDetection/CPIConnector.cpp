#include "CPIConnector.h"
#include "LidarInit.h"

CPIConnector::CPIConnector(){
	CPIConnector *tes = this;
	lidar = new LidarInit(tes);
}

CPIConnector::~CPIConnector(){
	delete lidar;
}

void CPIConnector::onMessage(mavlink_message_t & msg){

	mavlink_ralcp_t function = decodeRalcpMessage(msg);

	switch (function.Function){
		case LIDAR_COMMAND_FUNCTIONS::LIDAR_INIT:
			std::cout << "INIITT";
			lidar->start();
			systemID = function.Payload;
			sendCommand(uint64_t(COMMAND_DESTINATION::LIDAR), COMMAND_DESTINATION::CPI, LIDAR_COMMAND_FUNCTIONS::LIDAR_INIT );
			break;

		case LIDAR_COMMAND_FUNCTIONS::LIDAR_GETDEVICE:

			sendCommand(uint64_t(LIDAR_COMMAND_FUNCTIONS::LIDAR_GETDEVICE), COMMAND_DESTINATION::CPI, LIDAR_COMMAND_FUNCTIONS::LIDAR_GETDEVICE );
			break;

		case LIDAR_COMMAND_FUNCTIONS::LINEDATA:

			sendCommand(uint64_t(LIDAR_COMMAND_FUNCTIONS::LINEDATA), COMMAND_DESTINATION::CPI, LIDAR_COMMAND_FUNCTIONS::LINEDATA );
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

		case LIDAR_COMMAND_FUNCTIONS::ROSBEEPOSITION:

			sendCommand(uint64_t(LIDAR_COMMAND_FUNCTIONS::ROSBEEPOSITION), COMMAND_DESTINATION::CPI, LIDAR_COMMAND_FUNCTIONS::ROSBEEPOSITION );
			break;

		case LIDAR_COMMAND_FUNCTIONS::ROSBEEFLANK:

			sendCommand(uint64_t(LIDAR_COMMAND_FUNCTIONS::ROSBEEFLANK), COMMAND_DESTINATION::CPI, LIDAR_COMMAND_FUNCTIONS::ROSBEEFLANK );
			break;

		default:
			break;
	}

}

void CPIConnector::sendCommand(uint64_t payload, COMMAND_DESTINATION dest, LIDAR_COMMAND_FUNCTIONS lcf){
	messages.push(encodeRalcpMessage(payload, dest, lcf ));
}
