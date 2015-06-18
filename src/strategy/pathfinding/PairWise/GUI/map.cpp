#include "map.h"
#include <iostream>
#include <fstream>

Map::Map()
{
    for(int x = 0; x < MAP_WIDTH; x++){
        for (int y = 0; y < MAP_HEIGHT; y++){
            objectMatrix[x][y] = static_cast<int>(object::empty);
        }
    }
    Route atvRoute;
    atvRoute.randomRoute(MAP_WIDTH, MAP_HEIGHT);

    PairWiseMove pairwise;

    ATV atv;
   quadCopter quadcopter;

    Route pairwiseRoute = pairwise.quadCopterPairRoute(atvRoute, atv, quadcopter);

    for(int i = 0; i < pairwiseRoute.getRouteSize(); i++){
        //add waypoints to objectgrid
    }
}

Map::~Map()
{

}

Map::object Map::get(int x, int y)
{
    return static_cast<Map::object>(objectMatrix[x][y]);
}

void Map::set(int x, int y, int value)
{
    objectMatrix[x][y] = value;
}

Map * Map::loadFromFile(const char * filename)
{

    Map * map = new Map();
    std::ifstream is(filename);
    char c;
    int x = 0, y = 0;
    while(is.get(c)){
        map->set(x, y, 0);


        x+=1;
        if(x >= MAP_WIDTH -1){
            y += 1;
            x = 0;
        }
        if(y >= MAP_HEIGHT){
            break;
        }
    }
    is.close();
    //map->setFinish();
    return map;
}

typedef int (*pointer_to_arrays)[20];

pointer_to_arrays Map::getObjectMatrix(){
    return objectMatrix;
}

void Map::saveToFile(const char * filename)
{
    std::ofstream os(filename, std::ofstream::out);
    for(int y = 0; y < MAP_HEIGHT; y++){
        for(int x = 0; x < MAP_WIDTH; x++){
               os << static_cast<int>(get(x, y));
        }
        os << '\n';
    }
    os.close();
}

//void Map::setFinish(){
//    srand (time(NULL));
//    int randomMatrixPointX = rand() % MAP_WIDTH;
//    int randomMatrixPointY = rand() % MAP_HEIGHT;

//    while(objectMatrix[randomMatrixPointX][randomMatrixPointY]!=FREE){
//        randomMatrixPointX = rand() % MAP_WIDTH;
//        randomMatrixPointY = rand() % MAP_HEIGHT;
//    }
//    objectMatrix[randomMatrixPointX][randomMatrixPointY] = FINISH;
//    set(randomMatrixPointX, randomMatrixPointY, FINISH);
//    /**/
//    //set(6,14,FINISH);
//}
