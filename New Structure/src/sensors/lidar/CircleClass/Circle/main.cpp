#include "Circle.h"
#include <iostream>

bool runTest() {

	int originX = 10;
	int originY = 20;
	int radius = 7;

	Circle * object = new Circle(originX, originY, radius);

	if (object->getCircle().originX != originX && object->getCircle().originY != originY && object->getCircle().radius != radius) {
		return false;
	}

	originX = 15;
	originY = 25;
	radius = 12;

	object->setCircle(originX, originY, radius);

	if (object->getCircle().originX != originX && object->getCircle().originY != originY && object->getCircle().radius != radius) {
		return false;
	}

	return true;
}

int main(int argc, char *argv[]) {
	bool testComplete = runTest();
	
	std::cout << "Test success: ";
	if (testComplete) {
		std::cout << "True\n";
	} else {
		std::cout << "False\n";
	}

	return EXIT_SUCCESS;
}
