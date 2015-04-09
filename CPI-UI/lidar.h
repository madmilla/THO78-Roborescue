#ifndef LIDAR_H
#define LIDAR_H

#include <string>

/// this class is here till the lidar class has been made.

class lidar
{
public:
    lidar();
    ~lidar();


    /// initialisation Lidar
    unsigned int init();

    /// Set the hz of the lidar every 30rpm is 0.5 hz
    int setRPM(int rpm);

    /// start the lidar
    void startLidar();

    /// stop the lidar
    void stopLidar();

    /// get the status of the lidar (connected or not
    std::string getStatus();

    /// get the rpm status of the class
    int rpmStatus();


};

#endif // LIDAR_H
