#include "mainwindow.h"
#include <QtWidgets/QApplication>
#include "Rosbee.h"
#include "Lidar.h"
#include "Quadcopter.h"
#include "ATV.h"
#include "MAVLinkExchanger.h"
#include "SerialPort.h"

int main(int argc, char *argv[])
{
    SerialPort p{ "" };
    MAVLinkExchanger exch{ p };
    Rosbee r;
    Lidar l;
    Quadcopter q{ exch };
    ATV a{ exch };
    
    QApplication app(argc, argv);
    MainWindow w{q, r, l, a};
    w.show();

    return app.exec();
}