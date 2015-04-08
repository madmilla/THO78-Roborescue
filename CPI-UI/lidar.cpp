#include "lidar.h"

#include <QDebug>

lidar::lidar()
{

}

lidar::~lidar()
{

}

unsigned int lidar::init(){
    return 85;
}

void lidar::startLidar(){
    qDebug() << "de lidar zal nu starten ";

}

void lidar::stopLidar(){
    qDebug() << "de lidar zal nu stoppen ";
}


int lidar::setRPM(int rpm){
   int p = rpm;
   return 0;

}

int lidar::rpmStatus(){
    int rpm = 600;
    return rpm;
}


std::string lidar::getStatus(){
    return std::string("Verbonden");
}
