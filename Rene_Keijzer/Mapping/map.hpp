#ifndef MAP_H
#define MAP_H
#include <vector>
#include <string.h>
#include <fstream>
#include <iostream>
#include <string>
#include <ostream>

#include "noncopyable.hpp"

class Map : public NonCopyable
{
public:
    Map(std::string loc);
    void save(std::string loc = "");
    int cellAt(int x, int y, bool next = false);
    int width(){return mapWidth;}
    int height(){return mapHeight;}
    ~Map();

private:
    std::vector<std::string> explode(char delimeter, std::string subject);
    void addLine(std::vector<std::string> items);

    std::string location;
    int mapWidth;
    int mapHeight;
    std::vector<int> mapping;


};


#endif // MAP_H
