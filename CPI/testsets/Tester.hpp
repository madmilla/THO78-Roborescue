#pragma once
#include "BaseTest.hpp"
#include <vector>
class Tester
{
public:
	Tester();
	~Tester();
	void run();

private:
	std::vector<BaseTest> tests;

};

