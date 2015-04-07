#include <QApplication>
#include "Quadcopter.h"
#include "SerialPort.h"
#include <string>
#include "MAVLinkExchanger.h"
#include <iostream>
#include <thread>
#include "QuadCopterWindow.h"

int main(int argc, char ** argv)
{
    SerialPort serialPort("COM4");
    MAVLinkExchanger exchanger{ serialPort };
    Quadcopter quadcopter(exchanger);
    std::thread quadcopterLoopThread { &Quadcopter::loop, &quadcopter};
    std::thread exchangerLoopThread { &MAVLinkExchanger::loop, &exchanger};
    quadcopterLoopThread.detach();
    exchangerLoopThread.detach();

    QApplication a(argc, argv);
    QuadCopterWindow w{ quadcopter };
    w.show();
    return a.exec();
}
