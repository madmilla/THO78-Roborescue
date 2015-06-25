#include <iostream>
#include "Quadcopter.h"
#include "SerialPort.h"
#include "MAVLinkExchanger.h"
#include "quadcopterwindow.h"
#include <QtWidgets/QApplication>
#include <thread>
#include <functional>

SerialPort serialPort { "COM3" };
MAVLinkExchanger exchanger { serialPort };
Quadcopter quadcopter{ exchanger };

std::thread quadcopterThread{ &Quadcopter::loop, std::ref(quadcopter) };
std::thread exchangerThread{ &MAVLinkExchanger::loop, std::ref(exchanger) };

int main(int argc, char *argv[])
{
	quadcopterThread.detach();
	exchangerThread.detach();
	QApplication app(argc, argv);
    QuadCopterWindow w { quadcopter };
    w.show();
	return app.exec();
}