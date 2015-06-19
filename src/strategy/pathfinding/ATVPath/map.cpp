#include "map.h"

Map::Map(){

}

void Map::addItem(const MapItem & mi){
   items.push_back(mi);
}

void Map::clear(){
   items.clear();
}

bool Map::isColliding(const MapItem & mi) const{
   for(const MapItem & mi2 : items){
      if(mi.isColliding(mi2)) return true;
   }
   return false;
}

MapItem & Map::operator[](int index){
   return items.at(index);
}

std::vector<MapItem> & Map::getMapItems(){
   return items;
}
