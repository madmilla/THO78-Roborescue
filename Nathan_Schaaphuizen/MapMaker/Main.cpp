/// @file Main.cpp
/// @author Nathan Schaaphuisen
/// @version 1.0

#include "Window.hpp"
#include <QApplication>

///Testing only, will be removed.
void test();
///Testing only, will be removed.
void printMap(const Map &map);

///Entry point for application.
int main(int argc, char *argv[]){
    //Testing only, will be removed.
    if (argc > 1){
        //Run test
        test();
        //Exit program
        return 0;
    }

    //New application.
    QApplication a(argc, argv);
    //New window.
    Window w;
    //Show window.
    w.show();
    //Run forever:
    return a.exec();
}


//*************************************************//
//                     Test                        //
//*************************************************//
#include "Map.hpp"
#include <iostream>
void test(){
    //Make empty map.
    Map map;
    //Test if map is empty:
    if (map.getTiles().size() == 0){
        std::cout << "Test empty map: OK" << std::endl;
    }
    else{
        std::cout << "Test empty map: Fail" << std::endl;
    }

    //Add one free tile to map.
    map.addTile(0,0,Map::TileType::Free);
    //Test if map size grew to 1:
    if (map.getDiameter() == 1){
        std::cout << "Test add to map: OK" << std::endl;
    }
    else{
        std::cout << "Test add map: Fail" << std::endl;
    }

    //Test if tile is added on correct position with correct value:
    if (map.getTiles()[0][0] == static_cast<unsigned char>(Map::TileType::Free) ){
        std::cout << "Test tile positon on map: OK" << std::endl;
    }
    else{
        std::cout << "Test tile positon on map: Fail" << std::endl;
    }

    //Add a tile on a negative position.
    //Expectation: nothing will happan.
    map.addTile(-1,0,Map::TileType::Free);
    //Test negative position assignment:
    if (map.getDiameter() == 1 ){
        std::cout << "Test negative assignment: OK" << std::endl;
    }
    else{
        std::cout << "Test negative assignment: Fail" << std::endl;
    }


    //Add a tile on a way to large position.
    //Expectation: nothing will happan.
    map.addTile(100000,0,Map::TileType::Free);
    //Test big position assignment (outside max range).
    if (map.getDiameter() == 1 ){
        std::cout << "Test big assignment: OK" << std::endl;
    }
    else{
        std::cout << "Test big assignment: Fail" << std::endl;
    }

    //Rize the map from small to big.
    map.resize(100);
    //Test resizing the map from small to big.
    if (map.getDiameter() == 100 ){
        std::cout << "Test map upsize: OK" << std::endl;
    }
    else{
        std::cout << "Test map upsize: Fail" << std::endl;
    }

    //Rize the map from big to small.
    map.resize(0);
    //Test resizing the map from small to big.
    if (map.getDiameter() == 0 ){
        std::cout << "Test map downsize: OK" << std::endl;
    }
    else{
        std::cout << "Test map downsize: Fail" << std::endl;
    }

    //Add a ATV tile.
    map.addTile(1,1,Map::TileType::ATV);
    //Clear map.
    map.clear();
    //Test if map clears all tiles:
    if (map.getTiles()[1][1] == static_cast<unsigned char>(Map::TileType::Unknown) ){
        std::cout << "Test clear map: OK" << std::endl;
    }
    else{
        std::cout << "Test clear: Fail" << std::endl;
    }

    //Add 20 more unknown tiles to map:
    for(unsigned int x=0;x<20;++x){
        for(unsigned int y=0;y<20;++y){
            map.addTile(x,y,Map::TileType::Unknown);
        }
    }

    std::cout << "Print 20x20 empty map:" << std::endl;
    //Print map
    printMap(map);

}

void printMap(const Map &map){
    //Fetch the tiles.
    Tiles tiles = map.getTiles();
    //For each tile:
    for(unsigned int x=0;x<tiles.size();++x){
        for(unsigned int y=0;y<tiles[x].size();++y){
            //Print each tile as a integer.
            std::cout << static_cast<int>(tiles[y][x]) << " ";
        }
        //Print a enter.
        std::cout << std::endl;
    }
}
