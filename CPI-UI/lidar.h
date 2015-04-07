#ifndef LIDAR_H
#define LIDAR_H


class lidar
{
public:
    lidar();
    ~lidar();

    unsigned int init();
    int setRPM(int rpm);
    void startLidar();
    void stopLidar();


};

#endif // LIDAR_H
