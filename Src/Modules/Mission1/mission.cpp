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

    while(robotmanager.getRobots<Rosbee>().size()==0){}
    Rosbee* rosbee =robotmanager.getRobot<Rosbee>(1);

    //while(robotmanager.getRobots<Quadcopter>().size()==0){}
    //Quadcopter* actualQuad =robotmanager.getRobot<Quadcopter>(1);

    while(robotmanager.getRobots<Lidar>().size()==0){}
    Lidar* actualLidar =robotmanager.getRobot<Lidar>(1);

    VirtualQuadCopter copter(Dimension(1,1),Dimension(3,3),1,1);
    virtualRosbee bee(1,1,rosbee);
    VirtualATV atv(Dimension(1,1),1,1);
    virtualLidar lidar;
    Map map;
    StrategyController controller(map,copter,bee,lidar);
    controller.scanArea();
    std::cout << "Scan Area Done";
    getchar();
    controller.searchArea();
    controller.movePairwise();
    QApplication app(argc, argv);
    MainWindow w{q, a};
    w.show();

    return app.exec();
}