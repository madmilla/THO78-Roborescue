/// @file Map.cpp
/// @author Nathan Schaaphuisen
/// @version 1.0

#include "Map.hpp"
#include <vector>
#include <algorithm>

Map::Map():
//Default amount of tiles.
tileCount{0}
{
}

void Map::resize(unsigned int mapSize){
    //Make sure the new map size does not exceed the maxium map size.
    mapSize = ( (mapSize > maxMapSize) ? maxMapSize : mapSize);
    //Resize map column (x-axis).
    tiles.resize(mapSize);
    //For each colum:
    for(int i=0;i<tiles.size();++i){
       //Resize map row (y-axix) and fill it.
       //Unknown is the default tile type.
       tiles[i].resize(mapSize,static_cast<unsigned char>(TileType::Unknown));
    }
    //Update tile count
    tileCount = mapSize;
}


void Map::addTile(unsigned int x, unsigned int y, const TileType &tileType){
    //Get the maxium of the axis.
    int maxSize = std::max(x,y);
    //Check if position is outside bounds.
    if(maxSize >= tileCount){
        //Resize the map to fit the new position.
        //Make map 1 larger than position, because we start from 0.
        resize(maxSize+1);
    }
    //Set tile to new type.
    tiles[x][y] = static_cast<unsigned char>(tileType);
}



Map::Serializable* Map::serialise() const{
    //Create new serializable on the heap, because we're going to use it outside this function.
    Serializable* s = new Serializable;
    //Get the size of the map, if the map is bigger than the maximum size get the maximum size instead.
    //This is because we can not fill the struct beyond its capacity.
    int minSize = std::min(tileCount,maxMapSize);
    //Position in the tiles array of the struct.
    int p = 0;  //We start at the beginning.
    //For each tile:
    for(int x=0;x<minSize;++x){
        for(int y=0;y<minSize;++y){
           //Copy tile to struct.
           //Than go to nex position in struct.
           s->tiles[p++] = tiles[x][y];
        }
    }
    //Set the size of the struct.
    //This is the actual  amount of bytes copied in the above loop.
    s->size = minSize;
    //Return a pointer to the above new created struct.
    return s;
}



void Map::clear(){
    //For each tile:
    for(int x=0;x<tileCount;++x){
        for(int y=0;y<tileCount;++y){
            //Set tile type to Unknown
            tiles[x][y] = static_cast<unsigned char>(TileType::Unknown);
        }
    }
}


 int Map::getDiameter() const{
     //Return the map diameter.
     return tileCount;
 }

 Tiles Map::getTiles() const{
     //Return a copy of the map tiles.
     return tiles;
 }

 void Map::merge(const Map &other){
    //Find the maxium size between the two maps.
    int maxSize = std::max(tileCount, other.getDiameter());
    //Resize to the new maxium size.
    resize(maxSize);
    //Fetch the tiles from the other map.
    //These we're going to insert in this map.
    Tiles otherTiles = other.getTiles();
    //For each tile from the other map:
    for(int x=0;x<other.getDiameter();++x){
        for(int y=0;y<other.getDiameter();++y){
            //Check if the other tile has a higher value than this tile on the same position.
            //If so the other tile has a higher priority it needs to be copied over this one.
            if(otherTiles[x][y] > tiles[x][y] ){
                //Copy the other tile over this one.
                tiles[x][y] = otherTiles[x][y];
            }
        }
    }
 }


