#include "mainwindow.h"
#include <QtWidgets/QApplication>
#include "Rosbee.h"
#include "Lidar.h"
#include "Quadcopter.h"
#include "ATV.h"
#include "MAVLinkExchanger.h"
#include "SerialPort.h"
#include "databaseconnector.h"
#include <iostream>

int main(int argc, char *argv[])
{
    SerialPort p{ "" };
    MAVLinkExchanger exch{ p };
    Quadcopter q{ exch };
    ATV a{ exch };
    databaseConnector dbc("127.0.0.1","root","desktop","robodata");
    std::cout << dbc.getMaps().at(0).name;
    
    QApplication app(argc, argv);
    MainWindow w{q, a};
    w.show();

    return app.exec();
}