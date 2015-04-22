/*
 * Lidar.cpp
 *
 *  Created on: Apr 1, 2015
 *     Author: hamza
 */
#include "Lidar.h"

void Lidar::getData(){
   encoder->send(COMMAND_DESTINATION::LIDAR, LIDAR_COMMAND_FUNCTIONS::GETDATA, 0);
}

void Lidar::getRpm(){
   encoder->send(COMMAND_DESTINATION::LIDAR, LIDAR_COMMAND_FUNCTIONS::GETRPM, 0);
}

void Lidar::sendRpm(int rpm){
   encoder->send(COMMAND_DESTINATION::LIDAR, LIDAR_COMMAND_FUNCTIONS::SENDRPM, rpm);
}

void Lidar::Start(){
   encoder->send(COMMAND_DESTINATION::LIDAR, LIDAR_COMMAND_FUNCTIONS::START, 0);
}

void Lidar::Stop(){
   encoder->send(COMMAND_DESTINATION::LIDAR, LIDAR_COMMAND_FUNCTIONS::STOP, 0);
}

void Lidar::sendRosbeePositie(int postion[]){
   encoder->send(COMMAND_DESTINATION::LIDAR, LIDAR_COMMAND_FUNCTIONS::ROSBEEPOSITION, postion);
}

void Lidar::sendRosbeeFlank(int degrees){
   encoder->send(COMMAND_DESTINATION::LIDAR, LIDAR_COMMAND_FUNCTIONS::ROSBEEPOSITION, degrees);
}
