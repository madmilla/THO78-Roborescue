#include <iostream>
#include "../../../sensors/lidar/LineClass/Line.h"
#include <fstream>

class Line;

void test() {
	std::cout << "running test..." << std::endl << std::endl;

	std::ofstream output("LineClass Results.txt", std::ofstream::out);

	Line::Point p1{ 50, 50 };
	Line::Point p2{ 200, 200 };

	Line line(p1, p2);

	std::cout << "line Data:" << std::endl << line << std::endl << std::endl;

	output << "checks the line begin position and end position are correct: ";
	if (line.getLine().begin_pos == p1 && line.getLine().end_pos == p2) {
		output << "succes" << std::endl;
	}
	else {
		output << "failed" << std::endl;
	}

	p1 = Line::Point{ 100, 100 };
	p2 = Line::Point{ 400, 400 };

	line.setLine(p1, p2);

	std::cout << "changed line Data:" << std::endl << line << std::endl;

	output << "checks the changed line begin position and end position are correct: ";
	if (line.getLine().begin_pos == p1 && line.getLine().end_pos == p2) {
		output << "succes" << std::endl;
	}
	else {
		output << "failed" << std::endl;
	}
	output.close();
}

int main() {
	test(); //run test
	
	return 0;
}