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
#include "UDPServer.h"
int main(int argc, char *argv[])
{
    RobotManager robotmanager;
    SerialPort p{ "" };
    UDPServer server(robotmanager);
    Rosbee rosbee = robotmanager.getRobot<rosbee>                                 >
    MAVLinkExchanger exch{ p };
    Quadcopter q{ exch };
    ATV a{ exch };
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