#ifndef MAP_H
#define MAP_H

#include <string.h>

#include "noncopyable.hpp"

class Map : public NonCopyable
{
public:
    Map(std::string loc) : location(loc){}
    void load();
    void parse();

    ~Map();
private:
   std::string location;
};

#endif // MAP_H
