#include "mapping.h"

int main (int argc, int argv[]) {
	Map mapTest = new Map;
	std::vector<int> temp = mapTest.getFile();
	if (temp.size() == 400) {
		return 0;
	}
	else {
		return 1;
	}
	delete mapTest, temp;
}