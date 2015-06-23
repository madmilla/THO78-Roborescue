#include <QApplication>
#include "Quadcopter.h"
#include "SerialPort.h"
#include <string>
#include "MAVLinkCommunicator.h"
#include <iostream>
#include <thread>
#include "MainWindow.h"

int main(int argc, char ** argv)
{
    SerialPort serialPort("COM7");

    MAVLinkCommunicator exchanger{ serialPort };

    //MAVLinkExchanger exchanger{ serialPort };

    Quadcopter quadcopter(exchanger);
    std::thread quadcopterLoopThread { &Quadcopter::loop, &quadcopter};
    std::thread exchangerLoopThread { &MAVLinkCommunicator::loop, &exchanger};
    quadcopterLoopThread.detach();
    exchangerLoopThread.detach();

    ATV atv(exchanger);
    std::thread atvLoopThread { &ATV::loop, &atv};
    atvLoopThread.detach();


    Rosbee rosbee;
    lidar l;

    QApplication a(argc, argv);
    MainWindow w(quadcopter, rosbee, l, atv);
    w.show();
    return a.exec();
}
