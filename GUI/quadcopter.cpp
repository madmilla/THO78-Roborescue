
#include "Quadcopter.h"
#include <QDebug>

Quadcopter::Quadcopter(){
    qDebug() << "Quadcopter class built";
}

Quadcopter::~Quadcopter(){

}

void Quadcopter::liftOff(){

}

void Quadcopter::arm(){
    qDebug() << "Quadcopter armed";
}

void Quadcopter::moveLeft(){

}

void Quadcopter::moveRight(){

}

void Quadcopter::moveForward(){

}

void Quadcopter::moveBackward(){

}

void Quadcopter::stop(){

}

void Quadcopter::land(){

}

bool Quadcopter::isFlying(){

}

bool Quadcopter::isArmed(){

}

bool Quadcopter::isManual(){
    return manual;
}

void Quadcopter::setManual(bool b){
    manual = b;
}

void Quadcopter::changeFlightSpeed(int){

}

void Quadcopter::changeHeading(int){

}
