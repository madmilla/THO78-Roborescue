#pragma once
#include <string>
class BaseTest
{
public:
	BaseTest();
	~BaseTest();
	virtual void run();
	virtual void output();
protected:
	std::string name;
private:
	
};

