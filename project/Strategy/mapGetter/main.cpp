#include <QCoreApplication>
#include <iostream>
#include <QElapsedTimer>

#include "databaseconnector.h"

#define times 100000

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QElapsedTimer timer;
    try{
        databaseConnector dbc("127.0.0.1","root","desktop","robodata");
        dbc.setMap(1);

        point p1(2800, 3000);
        point p2(4400, 3000);
        point p3(4400, 4000);
        point p4(2800, 4000);

        std::vector<point> polygon{p1,p2,p3,p4};

        std::cout<<"starting "<<times<<" time isAccessable with a point\n";
        timer.start();
        for(int i=0;i<times;i++){
            dbc.isAccessable(p1);
        }
        auto durMs = timer.elapsed();
        auto durPerCountMs = durMs/times;

        std::cout << "Measured time          : " << durMs << " ms\n";
        std::cout << "Measured time per count: " << durPerCountMs << " ms\n";
        std::cout << "--------------------------------------------------------------------------------------------------\n";



        std::cout<<"starting "<<times<<" time isAccessable with a polygon\n";
        timer.start();
        for(int i=0;i<times;i++){
            dbc.isAccessable(polygon);
        }
        durMs = timer.elapsed();
        durPerCountMs = durMs/times;

        std::cout << "Measured time          : " << durMs << " ms\n";
        std::cout << "Measured time per count: " << durPerCountMs << " ms\n";
        std::cout << "--------------------------------------------------------------------------------------------------\n";
    }catch(std::exception &e){
        std::cout << e.what();
    }
return a.exec();
}
