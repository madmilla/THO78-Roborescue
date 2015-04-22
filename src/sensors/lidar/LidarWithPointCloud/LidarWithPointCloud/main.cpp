#include "Lidar.h"
#include "LidarController.h"
#include <chrono>
#include <thread>

int main()
{
    Lidar lidar("\\\\.\\com3");
    LidarController lController(lidar);
    std::thread lthread(&LidarController::run, &lController);
    lthread.detach();

    while(1) {
        lController.setNumberOfScans(-1);
        lController.resume();
        std::this_thread::sleep_for(std::chrono::milliseconds(5000));
    }

    return 0;
}

