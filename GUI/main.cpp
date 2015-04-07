#include "mainwindow.h"
//#include "quadcopterwindow.h"
#include <QApplication>
#include <thread>
#include "../Vehicles/Quadcopter/Quadcopter.h"
#include "../Vehicles/Dependencies/Serial/SerialPort.h"
#include "../Vehicles/Quadcopter/MAVLinkExchanger.h"

int main(int argc, char *argv[])
{
	SerialPort serial{"COM4"};
	MAVLinkExchanger exchanger{ serial };
	Quadcopter quadcopter{ exchanger };
	std::thread exchangerThread{ &MAVLinkExchanger::loop, &exchanger };
	std::thread quadcopterThread{ &Quadcopter::loop, &quadcopter };
	exchangerThread.detach();
	quadcopterThread.detach();
	
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    //QuadCopterWindow q;
    //q.show();

    return a.exec();
}
