#include "Lidar.h"
#include "LidarController.h"
#include <chrono>
#include <thread>
#include "shapedetector.h"
#include "PointCloud.h"

int main()
{
	ShapeDetector sD;
	Pointcloud pCloud;
    //Lidar lidar("\\\\.\\com3");
    Lidar lidar("/dev/ttyAMA0");
	LidarController lController(lidar, sD, pCloud);
    std::thread lthread(&LidarController::run, &lController);
    lthread.detach();

   // lController.setNumberOfScans(1);
    //lController.resume();
    //std::this_thread::sleep_for(std::chrono::milliseconds(5000));

    return 0;
}

