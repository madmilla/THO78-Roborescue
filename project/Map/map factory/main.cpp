#include <iostream>
#include <map.hpp>
#include <mapFactory.h>

int main(){
	mapFactory mF = mapFactory();
	std::vector<line> test = mF.loadMapFromFile("map.map");

	std::cout << "Lines from the objects:\n";
	for (const line & l : test){
		std::cout << l << std::endl;
	}

	(void)getchar();
	return 0;
}