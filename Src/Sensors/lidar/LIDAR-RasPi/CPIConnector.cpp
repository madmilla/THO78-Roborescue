#include "CPIConnector.h"

//This is an example child class
CPIConnector::CPIConnector(){
	lidar = new Lidar("/dev/ttyAMA0");
`	sendCommand<LIDAR_COMMAND_FUNCTIONS>(message, COMMAND_DESTINATION::CPI, LIDAR_COMMAND_FUNCTIONS::LIDAR_INIT);
	sendCommand<LIDAR_COMMAND_FUNCTIONS>(message, COMMAND_DESTINATION::CPI, LIDAR_COMMAND_FUNCTIONS::LIDAR_INIT);
	sendCommand<LIDAR_COMMAND_FUNCTIONS>(message, COMMAND_DESTINATION::CPI, LIDAR_COMMAND_FUNCTIONS::LIDAR_INIT);
	sendCommand<LIDAR_COMMAND_FUNCTIONS>(message, COMMAND_DESTINATION::CPI, LIDAR_COMMAND_FUNCTIONS::LIDAR_INIT);
}

void CPIConnector::onMessage(mavlink_message_t & msg){

	mavlink_command_long_t function = decodeCommandLongMessage(msg);

	switch (function.command){
		case LIDAR_COMMAND_FUNCTIONS::START:
			std::cout << "Start" << std::endl;
			for (Line l : lidar->start(function.param1, function.param2, function.param3)){
				message.param1 = 0;
				message.param2 = static_cast<float>(l.getLine().begin_pos.x);
				message.param3 = static_cast<float>(l.getLine().begin_pos.y);
				message.param4 = static_cast<float>(l.getLine().end_pos.x);
				message.param5 = static_cast<float>(l.getLine().end_pos.y);
				sendCommand<LIDAR_COMMAND_FUNCTIONS>(message, COMMAND_DESTINATION::CPI, LIDAR_COMMAND_FUNCTIONS::LINEDATA);
			}

			sendCommand<LIDAR_COMMAND_FUNCTIONS>(message, COMMAND_DESTINATION::CPI, LIDAR_COMMAND_FUNCTIONS::STOP);
			break;

		default:
			function.param1 += 1;
			sendCommand<LIDAR_COMMAND_FUNCTIONS>(function, COMMAND_DESTINATION::CPI, LIDAR_COMMAND_FUNCTIONS::STOP );
			break;
	}
}
