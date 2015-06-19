#include "CPIConnector.h"

//This is an example child class
CPIConnector::CPIConnector(){

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
		start();
		sendLidarCommand(temp, COMMAND_DESTINATION::CPI, LIDAR_COMMAND_FUNCTIONS::START);
		break;

	case LIDAR_COMMAND_FUNCTIONS::STOP:

		sendLidarCommand(temp, COMMAND_DESTINATION::CPI, LIDAR_COMMAND_FUNCTIONS::STOP);
		break;

	default:
		break;
	}
}


void CPIConnector::init(){
	//ShapeDetector sD;
	//Pointcloud pCloud;
	//Lidar lidar("\\\\.\\com3");
	lidar = new Lidar("/dev/ttyAMA0");
	lidar->connectDriversLidar();
}

void CPIConnector::start(){
	if(lidar == nullptr){
		init();
	}

	ShapeDetector sD;
	Pointcloud pCloud;

	std::vector<scanDot> data = lidar->startSingleLidarScan();

	if (!data.empty()) {
		std::vector<scanCoordinate> scanCoorde = lidar->convertToCoordinates(data);

		for (int pos = 0; pos < (int)scanCoorde.size(); ++pos) {
			pCloud.setPoint(scanCoorde[pos].x, scanCoorde[pos].y);
			fprintf(stderr, "x: %d , y: %d\n", scanCoorde[pos].x, scanCoorde[pos].y);
		}
	}
	
	pCloud.savePointsToFile("pointcuefnef.pcl");
	std::cout << "image maken";
	const Mat & image = sD.createImage(pCloud, 10);
	std::cout << "image gemaakt";
	std::vector<Circle> circles = sD.detectCircles(image);
	std::cout << " circles detected";
	std::vector<Line> lines = sD.searchLines(image);
	std::cout <<  "lines detected" ;
	sD.writeCirclesToConsole(circles);
	sD.writeLinesToConsole(lines);

	for (Line l : lines){
		int32_t beginPosX = static_cast<int32_t>(l.getLine().begin_pos.x);
		int32_t beginPosY = static_cast<int32_t>(l.getLine().begin_pos.y);
		int32_t endPosX = static_cast<int32_t>(l.getLine().end_pos.x);
		int32_t endPosY = static_cast<int32_t>(l.getLine().end_pos.y);
		int32_t data[5] = { 0, beginPosX, beginPosY, endPosX, EndposY };
		sendLidarCommand(data, COMMAND_DESTINATION::CPI, LIDAR_COMMAND_FUNCTIONS::LINEDATA);
	}

	for (Circle c : circles){
		int32_t originX = static_cast<int32_t>(c.getCircle().originX);
		int32_t originY = static_cast<int32_t>(c.getCircle().originY);
		int32_t radius = static_cast<int32_t>(c.getCircle().radius);
		int32_t data[4] = { 1, originX, originY, radius };
		sendLidarCommand(data, COMMAND_DESTINATION::CPI, LIDAR_COMMAND_FUNCTIONS::LINEDATA);

	}




	//LidarController lController(lidar, sD, pCloud);
	//std::thread lthread(&LidarController::run, &lController);
	//lthread.detach();

	// lController.setNumberOfScans(1);
	//lController.resume();
	//std::this_thread::sleep_for(std::chrono::milliseconds(5000));
}
