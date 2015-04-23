#include "Circle.h"
#include <iostream>
#include <fstream>

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

	output.close();
}

int main(int argc, char *argv[]) {
	runTest();

	return EXIT_SUCCESS;
}
