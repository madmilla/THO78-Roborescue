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
    Quadcopter q{ exch };
    ATV a{ exch };
    
    QApplication app(argc, argv);
    MainWindow w{q, a};
    w.show();

    return app.exec();
}