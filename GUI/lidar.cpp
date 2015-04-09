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
   int  p;
   if(rpm >=330 || rpm <=600){
        p = rpm;
   }
   else if(rpm <330){
        p = 330;
   }
   else{
       p = 600;
   }

   return p;


}

int lidar::rpmStatus(){
    int rpm = 600;
    return rpm;
}


std::string lidar::getStatus(){
    return std::string("Verbonden");
}
