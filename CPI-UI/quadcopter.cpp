#include "quadcopter.h"

#include <QDebug>

Quadcopter::Quadcopter()
{

}

Quadcopter::~Quadcopter()
{

}

unsigned int Quadcopter::Init(unsigned int maxAltitude, ControlMode controlMode){
    qDebug() << "##Init          ## MaxAltitiude " << maxAltitude << " ControlMode " << (unsigned int)controlMode << '\n';
    return 0;
}

bool Quadcopter::startMission(DPoint location, unsigned int maximumTimeMin, Map mapData){
    qDebug() << "##Start mission ## Start location " << location.x << ',' << location.y << ',' << location.z << " MaximumTime: " << maximumTimeMin << "min \n";
    return true;
}

void Quadcopter::stopMission(){
    qDebug() << "##Stop mission  ##\n";
}

void Quadcopter::abortMission(){
    qDebug() << "##Abort mission ##\n";
}

unsigned char Quadcopter::batteryStatus(){
    qDebug() << "##Battery perc  ##\n";
    return 100;
}

void Quadcopter::setSteeringMode(ControlMode controlMode){
    qDebug() << "##Change str mod## Control mode " << (unsigned int)controlMode << "\n";
}

void Quadcopter::land(){
    qDebug() << "##Land          ##\n";
}

void Quadcopter::stop(){
    qDebug() << "##Stop          ##\n";
}

void Quadcopter::fixConnection(){
    qDebug() << "##Fix connection##\n";
}

Quadcopter::dataPacket Quadcopter::getAllData(){
    qDebug() << "##All data      ##\n";

    Quadcopter::dataPacket data;
    data.currentLocation.x = 0;
    data.currentLocation.y = 0;
    data.currentLocation.z = 0;
    data.signalStrength = 100;
    return data;
}
