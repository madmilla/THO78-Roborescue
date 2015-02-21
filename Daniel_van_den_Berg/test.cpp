#include <iostream>
#include "MapSystem/mapeditor.h"

int main(int argc, char *argv[])
{
    MapEditor *mapEditor = new MapEditor();
	std::cout << mapEditor->getAvailableMaps();
	delete mapEditor;
	return 0;
}