#include "atv.h"

#include <QDebug>

ATV::ATV()
{

}

ATV::~ATV()
{

}

unsigned int ATV::Init(ControlMode controlMode){
    qDebug() << "##Init          ## ControlMode " << (unsigned int)controlMode;
    return 0;
}

bool ATV::startMission(DPoint location, unsigned int maximumTimeMin, Map mapData){
    qDebug() << "##Start mission ## Start location " << location.x << ',' << location.y << ',' << location.z << " MaximumTime: " << maximumTimeMin << "min";
    return true;
}

void ATV::stopMission(){
    qDebug() << "##Stop mission  ##";
}

void ATV::abortMission(){
    qDebug() << "##Abort mission ##";
}

unsigned char ATV::batteryStatus(){
   static unsigned char value = 100;

   qDebug() << "##Battery perc  ##";
   if(value > 100) value = 100;
   return value--;
}

void ATV::setSteeringMode(ControlMode controlMode){
    qDebug() << "##Change str mod## Control mode " << (unsigned int)controlMode;
}

void ATV::stop(){
    qDebug() << "##Stop          ##";
}

void ATV::fixConnection(){
    qDebug() << "##Fix connection##";
}

void ATV::arm(){
   qDebug() << "##ATV armed      ##";
}

void ATV::moveForward(int value){
   qDebug() << "##ATV forward    ## Value:" << value;
}

void ATV::moveBackward(int value){
   qDebug() << "##ATV backward   ## Value:" << value;
}

void ATV::turnLeft(int value){
   qDebug() << "##ATV turn left  ## Value:" << value;
}

void ATV::turnRight(int value){
   qDebug() << "##ATV turn right ## Value:" << value;
}

void ATV::emergencyStop(){
   qDebug() << "##ATV emercy stop##";
}

void ATV::returnControlToRc(){
   qDebug() << "##ATV control    ##";
}

int ATV::speed(){
   static int value = 0;

   qDebug() << "##ATV speed      ##";
   if(value > 130) value = 0;
   return value++;
}

void ATV::disarm(){
   qDebug() << "##ATV disarm     ##";
}
