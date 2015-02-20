#include "map.h"

#include <iostream>
#include "mapreadfailure.h"

void printMap(Map & map){
    for(unsigned int r = 0; r < map.rowCount(); r++){
        for(unsigned int c = 0; c < map.collomCount(); c++){
            std::cout << (unsigned int)map.get(r, c) << ' ';
        }
        std::cout << '\n';
    }
}

int main(/*int argc, char *argv[]*/)
{
    std::string filename = "temp.dat";
    Map::createEmpty(filename, 20, 20);

    try{
        Map map{filename};

        printMap(map);
    }catch(MapReadFailure mrf){
        std::cout << "Error: " << mrf.what();
        exit(1);
    }

    return 0;
}
