/*
 * Lidar.cpp
 *
 *  Created on: Apr 1, 2015
 *     Author: hamza
 */
#include "Lidar.h"

void Lidar::recieveLine(){
   encoder->send(COMMAND_DESTINATION::LIDAR, LIDAR_COMMAND_FUNCTIONS::RECEIVELINE, 0);
}

void Lidar::recieveRpm(){
   encoder->send(COMMAND_DESTINATION::LIDAR, LIDAR_COMMAND_FUNCTIONS::RECIEVERPM, rpm);
}

void Lidar::Start(){
   encoder->send(COMMAND_DESTINATION::LIDAR, LIDAR_COMMAND_FUNCTIONS::START, 0);
}

void Lidar::Stop(){
   encoder->send(COMMAND_DESTINATION::LIDAR, LIDAR_COMMAND_FUNCTIONS::STOP, 0);
}

void Lidar::sendRosbeePositie(int postion[]){
   encoder->send(COMMAND_DESTINATION::LIDAR, LIDAR_COMMAND_FUNCTIONS::SENDROSBEEPOSITION, postion);
}

void Lidar::sendRosbeeFlank(int degrees){
   encoder->send(COMMAND_DESTINATION::LIDAR, LIDAR_COMMAND_FUNCTIONS::SENDROSBEEFLANK, degrees);
}
