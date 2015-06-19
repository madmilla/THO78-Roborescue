#ifndef TEST_H
#define TEST_H

#include <map.hpp>
#include <vector>

class Test{
public:
	map testMap = map();

	point p1;
	point p2;
	point p3;
	point p4;
	point p5;
	point p6;
	point p7;
	point p8;

	line l1;
	line l2;
	line l3;
	line l4;


	//Test 1 add lines to map
	void test1();
	//Test 2 make cells accessible/not accessible
	void test2();
	//Test 3 make cells seen/unseen
	void test3();

};
#endif