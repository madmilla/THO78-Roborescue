#ifndef MAP_H
#define MAP_H

#include <string>
#include <vector>

#include "mapobject.h"

class Map
{
private:
    std::string filename;
    MapObject** data;
    unsigned int rows;
    unsigned int colloms;

    static const int UISize = 4;
public:
    Map(std::string filename);
    ~Map();

    void save();

    MapObject get(unsigned int row, unsigned int collom);
    void set(MapObject value, unsigned int row, unsigned int collom);

    unsigned int rowCount() {return rows;}
    unsigned int collomCount() {return colloms;}

    static void createEmpty(std::string filename, unsigned int rows, unsigned int colloms);
};

#endif // MAP_H
