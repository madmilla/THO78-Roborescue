#include "LandCS.h"
#include "AirCS.h"
#include <iostream>


int main(int argc, const char* argv[])
{
	AirCS airRobot("airrobot", 12345678, 25.0, 40.0, 21.0, 22.0, 23.0, 100.0, 200.0, 200.0);
	LandCS landrobot("landrobot", 12345678, 15.0, 50.0, 11.0, 12.0, 13.0, 5.3);

	std::cout << "jsonstrings (TODO) ";
	printf("	%s" ,airRobot.getJSONstring());
	printf("	%s", landrobot.getJSONstring());



}