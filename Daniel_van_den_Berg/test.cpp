#include <iostream>
#include "MapSystem/mapeditor.h"
#include <QStringList>
#include <QDebug>

int main(int argc, char *argv[])
{
    MapEditor *mapEditor = new MapEditor();
	qDebug() << mapEditor->getAvailableMaps().join("\n");
	delete mapEditor;
	return 0;
}