#include <vector>
#include "Test.hpp"
#include <ctime>
#include <limits.h>

Test::Test(){
	testMap = map();

	p1 = point(11, 21);
	p2 = point(13, 22);
	p3 = point(14, 23);
	p4 = point(15, 24);
	p5 = point(16, 25);
	p6 = point(17, 26);
	p7 = point(18, 27);
	p8 = point(19, 28);

	//points with max and min integer
	p9 = point(INT_MIN, INT_MIN);
	p10 = point(INT_MAX, INT_MAX);
	//points with max+1 and min-1 integer
	p11 = point(INT_MIN - 10, INT_MIN - 10);
	p12 = point(INT_MAX + 10, INT_MAX + 10);

	l1 = line(p1, p2);
	l2 = line(p3, p4);
	l3 = line(p5, p6);
	l4 = line(p7, p8);

	//line with huge integer
	l5 = line(p9, p10);
	l6 = line(p11, p12);
}

Test::~Test(){}


//Test 1 add lines to map

void Test::test1(){
	std::cout << l1 << "\n";
	testMap.appendLine(l1);
	testMap.appendLine(l2);
	testMap.appendLine(l3);
	testMap.appendLine(l4);
	testMap.translateToPoints();

	std::cout << "testmap: " << testMap << "\n";
}

//check if max integer is accepted
void Test::test2(){
	if (l5.getPoints().first.getX() <= INT_MAX && l5.getPoints().first.getY() <= INT_MAX &&l5.getPoints().first.getX() >= INT_MIN && l5.getPoints().first.getY() >= INT_MIN){
		testMap.appendLine(l5);
		std::cout << "testmap: " << testMap << "\n";
	}
	else{
		std::cout << "Line 5 Error: value out of bounds\n";
	}
	if (l6.getPoints().first.getX() <= INT_MAX && l6.getPoints().first.getY() <= INT_MAX && l6.getPoints().first.getX() >= INT_MIN && l6.getPoints().first.getY() >= INT_MIN){
		testMap.appendLine(l6);
		std::cout << "testmap: " << testMap << "\n";
	}
	else{
		std::cout << "Line 6 Error: value out of bounds\n";
	}
}

//performance with 1 million lines
void Test::test3(){
	std::clock_t start = std::clock();
	double duration;
	for (int i = 0; i < 1000; i++){
		testMap.appendLine(l1);
		testMap.removeLine(l1);
	}

	duration = (std::clock() - start) / (double)CLOCKS_PER_SEC;
	std::cout << "Test 3 duration: " << duration << " sec\n";
	for (;;){}
}