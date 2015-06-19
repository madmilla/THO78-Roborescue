#include <iostream>
//#include "../../../sensors/lidar/LineClass/Line.h"
#include "Line.h"
#include <fstream>

class Line;

void test() {

	Line::Point begin1{ 239, 124 };
	Line::Point end1{268,141 };
	Line testLine(begin1, end1);

	Line::Point begin2{239,118 };
	Line::Point end2{272, 136};
	Line testLine2(begin2, end2);

	std::cout << "\nintersect functie " << testLine.intersect(testLine2) << "%s\n";
	std::cout << "\nintersect functie " << testLine2.intersect(testLine) << "%s\n";
	std::cout << "\n................................................\n";
	Line::Point begin5{23,210 };
	Line::Point end5{23, 220};
	
	
	Line testLine5(begin2, end2);


	Line::Point begin4{ 33.33, 250 };
	Line::Point end4{ 200, 0 };
	Line testLine4(begin4, end4);

	//std::cout << "\nintersect functie " << testLine5.intersect(testLine) << "%\n";

	std::cout << "................................................\n";
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
	system("pause");
	
	return 0;
}