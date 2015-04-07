/*
 * Lidar.cpp
 *
 *  Created on: Apr 1, 2015
 *      Author: hamza
 */
#include "Lidar.h"

Lidar::Lidar(bool equipmentStatus),
CPIBoundaryObject(Socket sock, Uint32_t id){}

virtual Lidar::~Lidar(){}

string Lidar::getData(){return "";}

int Lidar::getRpm(){return 0;}

void Lidar::sendRpm(int rpm){}

void Lidar::Start(int rpm){}

void Lidar::Stop(){}

void Lidar::sendRosbeePositie(){}

void Lidar::sendRosbeeFlank(){}
