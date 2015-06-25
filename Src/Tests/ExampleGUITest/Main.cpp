#include <iostream>
#include "Quadcopter.h"
#include "SerialPort.h"
#include "MAVLinkExchanger.h"
#include "quadcopterwindow.h"
#include <QtWidgets/QApplication>

SerialPort serialPort { "COM4" };
MAVLinkExchanger exchanger { serialPort };
Quadcopter c{ exchanger };

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);
    QuadCopterWindow w { c };
    w.show();
	return app.exec();
}