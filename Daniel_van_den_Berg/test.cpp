#include <iostream>
#include "MapSystem/mapeditor.h"

int main(int argc, char *argv[])
{
    MapEditor mapEditor();
	std::cout << mapEditor.getAvailableMaps();
	return 0;
}