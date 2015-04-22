#include "Tester.hpp"


Tester::Tester()
{
}

void Tester::run(){
	for each (auto test in tests)
	{
		test.run();
	}
}

Tester::~Tester()
{
}
