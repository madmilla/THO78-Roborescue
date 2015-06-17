#include "CPIConnector.h"

CPIConnector::CPIConnector(){
}

void CPIConnector::onMessage(mavlink_message_t & msg){

	mavlink_ralcp_t function = decodeRalcpMessage(msg);

	switch (function.Function){
		case LIDAR_COMMAND_FUNCTIONS::LIDAR_INIT:
			std::cout << "INIITT";
			start();
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

void CPIConnector::start(){
	ShapeDetector sD;
	Pointcloud pCloud;
	//Lidar lidar("\\\\.\\com3");
	Lidar lidar("/dev/ttyAMA0");
	lidar.connectDriversLidar();

	std::vector<scanDot> data = lidar.startSingleLidarScan();

	if (!data.empty()) {
		std::vector<scanCoordinate> scanCoorde = lidar.convertToCoordinates(data);

		for (int pos = 0; pos < (int)scanCoorde.size(); ++pos) {
			pCloud.setPoint(scanCoorde[pos].x, scanCoorde[pos].y);
			fprintf(stderr, "x: %d , y: %d\n", scanCoorde[pos].x, scanCoorde[pos].y);
		}
	}

	const Mat & image = sD.createImage(pCloud);
	std::vector<Circle> circles = sD.detectCircles(image);
	std::vector<Line> lines = sD.searchLines(image);
	sD.writeCirclesToConsole(circles);
	sD.writeLinesToConsole(lines);

	for (Line l : lines){
		sendCommand(20000, COMMAND_DESTINATION::CPI, LIDAR_COMMAND_FUNCTIONS::LINEDATA);
	}

	for (Circle c : circles){
		sendCommand(18766776, COMMAND_DESTINATION::CPI, LIDAR_COMMAND_FUNCTIONS::LINEDATA);
	}




	//LidarController lController(lidar, sD, pCloud);
	//std::thread lthread(&LidarController::run, &lController);
	//lthread.detach();

	// lController.setNumberOfScans(1);
	//lController.resume();
	//std::this_thread::sleep_for(std::chrono::milliseconds(5000));
}

