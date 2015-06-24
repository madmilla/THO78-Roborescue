#ifndef MAPITEM_H
#define MAPITEM_H

#include <vector>
#include "vector.h"

/**
* @class   MapItem
* @author  Wibren Wiersma
* @date    Juni, 2015
* @brief   This class is the MapItem, an MapItem is a item existing out a number of points.
*/
class MapItem
{
public:
   /**
    * Create an empty map item
    */
   MapItem();
   /**
    * Copy the points in a new mapItem
    */
   MapItem(std::vector<Vector<float>> points);

   /**
    * Add a point
    */
   void addPoint(Vector<float> point);
   /**
    * Remove a point by value
    */
   void removePoint(Vector<float> point);
   /**
    * Remove a point by index
    */
   void removePoint(int index);

   /**
    * Get a point by its index. If index < 0 or higher then the count an exception is thrown.
    */
   Vector<float> operator[](int index) const;

   /**
    * Get the total number of points added in this MapItem
    */
   int pointCount() const;

   /**
    * Iterator for points
    */
   std::vector<Vector<float>>::const_iterator begin() const;
   /**
    * Iterator for points
    */
   std::vector<Vector<float>>::const_iterator end() const;

   /**
    * Check if the other mapitem is colliding with this.
    * @param other the mapitem to check with
    * @return true if the other mapItem is colliding with this one
    */
   bool isColliding(const MapItem & other) const;

private:
   std::vector<Vector<float>> points;

   Vector<float> projectOn(const Vector<float> vector) const;
};

#endif // MAPITEM_H
