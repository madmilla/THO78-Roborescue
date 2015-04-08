#include "atv.h"

#include <QDebug>

ATV::ATV()
{

}

ATV::~ATV()
{

}

unsigned int ATV::Init(ControlMode controlMode){
    qDebug() << "##Init          ## ControlMode " << (unsigned int)controlMode << '\n';
    return 0;
}

bool ATV::startMission(DPoint location, unsigned int maximumTimeMin, Map mapData){
    qDebug() << "##Start mission ## Start location " << location.x << ',' << location.y << ',' << location.z << " MaximumTime: " << maximumTimeMin << "min \n";
    return true;
}

void ATV::stopMission(){
    qDebug() << "##Stop mission  ##\n";
}

void ATV::abortMission(){
    qDebug() << "##Abort mission ##\n";
}

unsigned char ATV::batteryStatus(){
    qDebug() << "##Battery perc  ##\n";
    return 100;
}

void ATV::setSteeringMode(ControlMode controlMode){
    qDebug() << "##Change str mod## Control mode " << (unsigned int)controlMode << "\n";
}

void ATV::stop(){
    qDebug() << "##Stop          ##\n";
}

void ATV::fixConnection(){
    qDebug() << "##Fix connection##\n";
}

void ATV::arm(){
   qDebug() << "##ATV armed##\n";
}
