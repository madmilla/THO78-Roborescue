#include <iostream>

#include "VehicleState.h"
#include "VehicleUpdater.h"

int main() {
	std::cout << "#####CONSTRUCTOR#####" << std::endl;
	std::cout << "VehicleState(4, 3, 2, 1.0f)" << std::endl;
	VehicleState state1(4, 3, 2, 1.0f);
	std::cout << state1 << std::endl;
	std::cout << "VehicleState()" << std::endl;
	VehicleState state2;
	std::cout << state2 << std::endl;

	std::cout << std::endl;

	std::cout << "#####GETTERS#####" << std::endl;
	std::cout << "VehicleState(1, 2, 3, 4.0f)" << std::endl;
	VehicleState getter(1, 2, 3, 4.0f);
	std::cout << getter << std::endl;
	std::cout << "getX()" << std::endl;
	std::cout << getter.getX() << std::endl;
	std::cout << "getY()" << std::endl;
	std::cout << getter.getY() << std::endl;
	std::cout << "getZ()" << std::endl;
	std::cout << getter.getZ() << std::endl;
	std::cout << "getTheta()" << std::endl;
	std::cout << getter.getTheta() << std::endl;

	std::cout << std::endl;

	std::cout << "#####SETTERS#####" << std::endl;
	std::cout << "VehicleState()" << std::endl;
	VehicleState setter;
	std::cout << setter << std::endl;
	std::cout << "setX(1)" << std::endl;
	setter.setX(1);
	std::cout << setter << std::endl;
	std::cout << "setY(2)" << std::endl;
	setter.setY(2);
	std::cout << setter << std::endl;
	std::cout << "setZ(3)" << std::endl;
	setter.setZ(3);
	std::cout << setter << std::endl;
	std::cout << "setTheta(4)" << std::endl;
	setter.setTheta(4);
	std::cout << setter << std::endl;

	std::cout << std::endl;

	std::cout << "#####VEHICLES#####" << std::endl;
	std::cout << "GetRosbeePosition" << std::endl;
	VehicleState rosbee = VehicleUpdater::getRosbeePosition();
	std::cout << rosbee << std::endl;
	std::cout << "GetATVPosition" << std::endl;
	VehicleState atv = VehicleUpdater::getATVPosition();
	std::cout << atv << std::endl;
	std::cout << "GetQuadCopterPositon" << std::endl;
	VehicleState quadcopter = VehicleUpdater::getQuadCopterPositon();
	std::cout << quadcopter << std::endl;
}