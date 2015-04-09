#include "rosbee.h"

#include <QDebug>

Rosbee::Rosbee()
{

}

Rosbee::~Rosbee()
{

}

unsigned int Rosbee::init(){
    qDebug() << "##Init          ##\n";
    return 85;
}

void Rosbee::startMission(){
    qDebug() << "##Start mission ##\n";
}

void Rosbee::abortMission(){
    qDebug() << "##Abort mission ##\n";
}

unsigned char Rosbee::batteryStatus(){
    static unsigned char value = 100;

    if(value > 100) value = 100;
    return value--;
}

void Rosbee::stopMission(){
   qDebug() << "##Stop mission ##\n";
}


std::string Rosbee::getStatus(){
   return std::string("Everythink OK");
}
