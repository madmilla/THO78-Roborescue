#include "XYProvider.h"

double XYProvider::getX(){
	return x;
}
double XYProvider::getY(){
	return y;
}

void XYProvider::calibrate(double x, double y){
	this->x = x;
	this->y = y;
}

void XYProvider::calibrateX(double x){
	this->x = x;
}

void XYProvider::calibrateY(double y){
	this->y = y;
}