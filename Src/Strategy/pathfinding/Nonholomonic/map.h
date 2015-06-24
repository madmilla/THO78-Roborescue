#ifndef MAP_H
#define MAP_H

#include <vector>
#include "mapitem.h"

/**
* @class   Map
* @author  Wibren Wiersma
* @date    Juni, 2015
* @brief   This class is the map
*/
class Map {
public:

   /**
    * Constructs an empty map
    */
   Map();

   /**
    * Add a mapitem into the map
    * @param mi the new mapitem. A copy will be added not the reference
    */
   void addItem(const MapItem &mi);

   /**
    * Clear the map
    */
   void clear();

   /**
    * Check if a extern mapitem is colliding with some mapitem in the map
    * @param mi the extern mapitem to check the map with
    * @return true if some object collides with the give mapitem
    */
   bool isColliding(const MapItem & mi) const;

   /**
    * Gives the mapitem with the number given in the index. If index is to low or high an exception will be thrown
    * @param index
    * @return MapItem on the index
    */
   MapItem & operator[](int index);


   /**
    * Get the list of all mapitems, mapItems and list is editable
    */
   std::vector<MapItem> & getMapItems();

private:
   std::vector<MapItem> items;
};

#endif // MAP_H
