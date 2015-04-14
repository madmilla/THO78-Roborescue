#include <iostream>
#include "Line.h"

bool test() {
	std::cout << "running test..." << std::endl << std::endl;

	Line::Point p1{ 50, 50 };
	Line::Point p2{ 200, 200 };

	Line line(p1, p2);

	std::cout << "line Data:" << std::endl << line << std::endl << std::endl;

	p1 = Line::Point{ 100, 100 };
	p2 = Line::Point{ 400, 400 };

	line.setLine(p1, p2);

	std::cout << "changed line Data:" << std::endl << line << std::endl;

	return true;
}

int main() {

	if (test()) {
		std::cout << std::endl << "test finished succesfully" << std::endl;	
		char c;
		while (std::cin >> c && c != 'q');
		return EXIT_SUCCESS;
	}
	else {
		std::cout << " test failed" << std::endl;
		return EXIT_FAILURE;
	}
}