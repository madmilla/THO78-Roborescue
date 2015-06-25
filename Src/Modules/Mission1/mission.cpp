#include "mainwindow.h"
#include <QtWidgets/QApplication>
#include "Rosbee.h"
#include "Lidar.h"
#include "Quadcopter.h"
#include "ATV.h"
#include "MAVLinkExchanger.h"
#include "SerialPort.h"
#include "StrategyController.h"
#include "VirtualRosbee.h"
#include "VirtualATV.h"
#include "VirtualQuadCopter.h"
#include "databaseconnector.h"
#include <iostream>

int main(int argc, char *argv[])
{
    RobotManager robotmanager;
    SerialPort p{ "" };
    //Rosbee = robotmanager.getRobot<rosbee>                                  >
    MAVLinkExchanger exch{ p };
    //Quadcopter q{ exch };
    //ATV a{ exch };
    VirtualQuadCopter copter(Dimension(1,1),Dimension(3,3),1,1);
    //virtualRosbee bee(1,1);
    VirtualATV atv(Dimension(1,1),1,1);
    virtualLidar lidar;
    Map map;
    //StrategyController controller(map,copter,bee,lidar);
    //controller.scanArea();
    std::cout << "Scan Area Done";
    getchar();
    //controller.searchArea();
    //controller.movePairwise();
    QApplication app(argc, argv);
    //MainWindow w{q, a};
    //w.show();
    databaseConnector dbc("127.0.0.1","root","desktop","robodata");
    std::cout << dbc.getMaps().at(0).name;
    
    
    return app.exec();
}