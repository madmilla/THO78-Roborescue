#include "LidarController.h"
#include "PointCloud.h"
#include <thread>

LidarController::LidarController(Lidar &l):
    Stop(false),
    isPaused(false),
    lidar(l)
{}

void LidarController::run()
{
    lidar.connectDriversLidar();
    while(!Stop) {

        // Check if thread needs to be paused
        {
            std::unique_lock<std::mutex> lck(csync);
            if(isPaused){
                cpauseCond.wait(lck);
            }
        }

        std::vector<scanDot> data = lidar.startSingleLidarScan();

        if(!data.empty()) {
            std::vector<scanCoordinate> scanCoord = lidar.convertToCoordinates(data);

            for(int i = 0; i < (int)scanCoord.size(); ++i) {
                pCloud.setPoint(scanCoord[i].x,scanCoord[i].y);
            }
        }
    }
}

void LidarController::resume()
{
    csync.lock();
    isPaused = false;
    csync.unlock();
    cpauseCond.notify_all();
}

void LidarController::pause()
{
    csync.lock();
    isPaused = true;
    csync.unlock();
}

