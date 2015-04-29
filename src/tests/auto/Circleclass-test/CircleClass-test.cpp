#include "../../../sensors/lidar/CircleClass/Circle/Circle.h"
#include "../../../sensors/lidar/LineClass/Line.h"
#include <iostream>
#include <fstream>
#include <vector>

class Circle;
class Line;

void runTest() {

	int originX = 10;
	int originY = 20;
	int radius = 7;
	std::ofstream output("results/CircleClass-test.txt", std::ofstream::out);

	Circle * object = new Circle(originX, originY, radius);

	if (object == NULL) {
		output << "Create Circle object: Failed" << std::endl;
	} else {
		output << "Create Circle object: Success" << std::endl;
	}

	if (object->getCircle().originX != originX && object->getCircle().originY != originY && object->getCircle().radius != radius) {
		output << "Compare parameters with getter: Failed" << std::endl;
	} else {
		output << "Compare parameters with getter: Success" << std::endl;
	}
	
	std::vector<Line> lines = object->getLinesAroundCircle();

	if (!lines.empty()) {
		output << "check lines around circle: succes" << std::endl;
	}
	else {
		output << "check lines around circle: failed" << std::endl;
	}

	originX = 15;
	originY = 25;
	radius = 12;

	object->setCircle(originX, originY, radius);

	if (object->getCircle().originX != originX && object->getCircle().originY != originY && object->getCircle().radius != radius) {
		output << "Compare parameters after setter: Failed" << std::endl;
	}
	else {
		output << "Compare parameters after getter: Success" << std::endl;
	}

	lines = object->getLinesAroundCircle();

	if (!lines.empty()) {
		output << "check lines around circle after setter: succes" << std::endl;
	}
	else {
		output << "check lines around circle after setter: failed" << std::endl;
	}

	output.close();
}

int main(int argc, char *argv[]) {
	runTest();

	return EXIT_SUCCESS;
}
