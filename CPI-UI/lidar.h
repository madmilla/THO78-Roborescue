#ifndef LIDAR_H
#define LIDAR_H

#include <string>

class lidar
{
public:
    lidar();
    ~lidar();

    unsigned int init();
    int setRPM(int rpm);
    void startLidar();
    void stopLidar();
    std::string getStatus();
    int rpmStatus();


};

#endif // LIDAR_H
