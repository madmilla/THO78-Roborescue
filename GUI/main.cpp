#include <QApplication>
#include "Quadcopter.h"
#include "SerialPort.h"
#include <string>
#include "MAVLinkExchanger.h"
#include <iostream>
#include <thread>
#include "MainWindow.h"

int main(int argc, char ** argv)
{
    SerialPort serialPort("COM4");
    MAVLinkExchanger exchanger{ serialPort };
    Quadcopter quadcopter(exchanger);
    std::thread quadcopterLoopThread { &Quadcopter::loop, &quadcopter};
    std::thread exchangerLoopThread { &MAVLinkExchanger::loop, &exchanger};
    quadcopterLoopThread.detach();
    exchangerLoopThread.detach();

    Rosbee rosbee;
    lidar l;
    ATV atv;

    QApplication a(argc, argv);
    MainWindow w(quadcopter, rosbee, l, atv);
    w.show();
    return a.exec();
}
