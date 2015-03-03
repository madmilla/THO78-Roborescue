#include <iostream>
#include <assert.h>
#include "MappingSystem/Mapping.h"

int main(int argc, char *argv[])
{
	success = true;
	Mapping mapping;
	
	int activeObj = mapping.setActiveObject(1);
	assert(activeObj >= 0 && activeObj == 1);
	
	bool placeObj = mapping.setObject(3,5);
	assert(placeObj);
	
	bool save = saveMap(QString("testmap");
	QFile f = ("testmap");
    assert(save && f.exists() && "File is saved and exists");
	
	return success;
    //void loadMap(QString fileName);
    //void setObject(int posX, int posY);
    //void setActiveObject(int obj);
    //QVector< QVector<int> > getMap();
}