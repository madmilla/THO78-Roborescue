#include "LidarController.h"
#include "PointCloud.h"

LidarController::LidarController(Lidar &l):
    Stop(false),
    isPaused(false),
    lidar(l),
    numberOfScans(1),
    scanCount(0)
{
    lidar.connectDriversLidar();
}

void LidarController::run()
{
    resetScanCount();

    while(!Stop) {

        if(scanCount >= numberOfScans && numberOfScans != -1) {
            pause();
        }

        // Check if thread needs to be paused
        {
            std::unique_lock<std::mutex> lck(csync);
            if(isPaused){
                cpauseCond.wait(lck);
            }
        }

        std::vector<scanDot> data = lidar.startSingleLidarScan();

        if(!data.empty()) {
            std::vector<scanCoordinate> scanCoorde = lidar.convertToCoordinates(data);

            for (int pos = 0; pos < (int)scanCoorde.size(); ++pos) {
                pCloud.setPoint(scanCoorde[pos].x, scanCoorde[pos].y);
                fprintf(stderr,"scan: %d | x: %d , y: %d\n", scanCount, scanCoorde[pos].x, scanCoorde[pos].y);
            }
        }
        ++scanCount;
    }
    // reset the number of scans to make because scanning has stopped
    resetNumberOfScans();
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

void LidarController::setNumberOfScans(int number)
{
    resetScanCount();
    numberOfScans = number;
}

void LidarController::resetNumberOfScans()
{
    numberOfScans = 0;
}

void LidarController::resetScanCount()
{
    scanCount = 0;
}

