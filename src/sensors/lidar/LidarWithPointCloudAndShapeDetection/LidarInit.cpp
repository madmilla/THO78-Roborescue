#include "LidarInit.h"
#include "rplidar.h"
#include "Lidar.h"
//#include "LidarController.h"
#include <chrono>
//#include <thread>
#include "shapedetector.h"
#include "PointCloud.h"
#include "CPIConnector.h"

LidarInit::LidarInit(CPIConnector *CPI) :
CPI(CPI)
{}

void LidarInit::start(){
	ShapeDetector sD;
	Pointcloud pCloud;
  //Lidar lidar("\\\\.\\com3");
  Lidar lidar("/dev/ttyAMA0");
	lidar.connectDriversLidar();

	std::vector<scanDot> data = lidar.startSingleLidarScan();

	if(!data.empty()) {
		std::vector<scanCoordinate> scanCoorde = lidar.convertToCoordinates(data);

		for (int pos = 0; pos < (int)scanCoorde.size(); ++pos) {
			pCloud.setPoint(scanCoorde[pos].x, scanCoorde[pos].y);
			fprintf(stderr,"x: %d , y: %d\n", scanCoorde[pos].x, scanCoorde[pos].y);
		}
	}

	const Mat & image = sD.createImage(pCloud);
	std::vector<Circle> circles = sD.detectCircles(image);
	std::vector<Line> lines = sD.searchLines(image);
	sD.writeCirclesToConsole(circles);
	sD.writeLinesToConsole(lines);

	for (Line l : lines){
		CPI->sendCommand(l, COMMAND_DESTINATION::CPI, LIDAR_COMMAND_FUNCTIONS::LINEDATA);
	}

	for (Circle c : circles){
		CPI->sendCommand(c, COMMAND_DESTINATION::CPI, LIDAR_COMMAND_FUNCTIONS::LINEDATA);
	}

	


	//LidarController lController(lidar, sD, pCloud);
    //std::thread lthread(&LidarController::run, &lController);
    //lthread.detach();

   // lController.setNumberOfScans(1);
    //lController.resume();
    //std::this_thread::sleep_for(std::chrono::milliseconds(5000));
}
