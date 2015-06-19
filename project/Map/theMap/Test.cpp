#include <map.hpp>
#include <vector>
#include "Test.hpp"
#include <ctime>
#include <limits.h>


map testMap = map();

point p1{ 11, 21 };
point p2{ 13, 22 };
point p3{ 14, 23 };
point p4{ 15, 24 };
point p5{ 16, 25 };
point p6{ 17, 26 };
point p7{ 18, 27 };
point p8{ 19, 28 };
//point with huge integer
point p9{ INT_MIN, INT_MIN };
point p10{ INT_MAX, INT_MAX };

point p11{ INT_MIN -1, INT_MIN -1 };
point p12{ INT_MAX +1, INT_MAX +1 };

line l1{ p1, p2 };
line l2{ p3, p4 };
line l3{ p5, p6 };
line l4{ p7, p8 };
//line with huge integer
line l5{ p9, p10 };
line l6{ p11, p12 };


//Test 1 add lines to map
void test1(){
	testMap.appendLine(l1);
	testMap.appendLine(l2);
	testMap.appendLine(l3);
	testMap.appendLine(l4);

	std::cout << "testmap: " << testMap << "\n";
}

//check if max integer is accepted
void test2(){
	if (l5.getPoints().first.getX() <= INT_MAX && l5.getPoints().first.getY() <= INT_MAX &&l5.getPoints().first.getX() <= INT_MIN && l5.getPoints().first.getY() <= INT_MIN){
		testMap.appendLine(l5);
	}
	else if (l6.getPoints().first.getX() <= INT_MAX && l6.getPoints().first.getY() <= INT_MAX && l6.getPoints().first.getX() <= INT_MIN && l6.getPoints().first.getY() <= INT_MIN){
		testMap.appendLine(l6);
	}
	else{
		std::cout << "Error: value out of bounds\n";
	}
}

//performance with 1 million lines
void test3(){
	std::clock_t start = std::clock();
	double duration;
	for (int i = 0; i < 1000000; i++){
		testMap.appendLine(l1);
		testMap.removeLine(l1);
	}
		
	duration = (std::clock() - start) / (double) CLOCKS_PER_SEC;
	std::cout << "Test 3 duration: " << duration << " sec\n";
}
	
int main() {
	test1();
	test2();
	test3();
}