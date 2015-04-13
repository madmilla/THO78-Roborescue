#include <iostream>
#include "Line.h"

std::ostream& operator<<(std::ostream & stream, const Point & point) {
	stream << '(' << point.x << ' ' << point.y << ')';
	return stream;
}

bool test() {
	std::cout << "running test..." << std::endl << std::endl;

	Point p1{ 50, 50 };
	Point p2{ 200, 200 };

	Line line(p1, p2);

	std::cout << "line Data:" << std::endl << line.getLine().begin_pos << ' ' << line.getLine().end_pos << std::endl << std::endl;

	p1 = Point{ 100, 100 };
	p2 = Point{ 400, 400 };

	line.setLine(p1, p2);

	std::cout << "changed line Data:" << std::endl << line.getLine().begin_pos << ' ' << line.getLine().end_pos << std::endl;

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