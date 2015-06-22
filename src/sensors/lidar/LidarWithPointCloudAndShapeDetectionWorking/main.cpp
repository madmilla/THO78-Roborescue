#include "rplidar.h"
#include "Lidar.h"
//#include "LidarController.h"
#include <chrono>
#include "time.h"
#include "ctime"
//#include <thread>
#include "shapedetector.h"
#include "PointCloud.h"

int main()
{
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
	pCloud.savePointsToFile("scan");
	/*
	std::cout << "Create image \n";
	clock_t Start = clock();
	const Mat & image = sD.createImage(pCloud, 10);
	std::cout << "Detect circles - Time: \n";
	std::vector<Circle> circles = sD.detectCircles(image);
	std::cout << "Detect Lines - Time: \n";
	std::vector<Line> lines = sD.searchLines(image);
	sD.writeCirclesToConsole(circles);
	sD.writeLinesToConsole(lines);
	clock_t end = clock();
	float time = (float)(end - Start) / CLOCKS_PER_SEC;
	std::cout << "Time: " << time << "\n";
*/
	//LidarController lController(lidar, sD, pCloud);
    //std::thread lthread(&LidarController::run, &lController);
    //lthread.detach();

   // lController.setNumberOfScans(1);
    //lController.resume();
    //std::this_thread::sleep_for(std::chrono::milliseconds(5000));

    return 0;
}
