#ifndef PATHFINDING_H
#define PATHFINDING_H

#include "vector.h"
#include "rotationoption.h"
#include "node.h"
#include "map.h"

/**
* @class   PathFinding
* @author  Wibren Wiersma
* @date    Juni, 2015
* @brief   This class contains the logic for the nonholomonic pathfinding algorithm
*/
class PathFinding
{
public:
   /**
    * Creates a pathfinding based on a map, roation radius of the vehicle and the size of it.
    */
   PathFinding(float rotationRadius, Vector<float> ATVSize, Map & map);
   /**
    * Deconstructor of the pathfinding
    */
   ~PathFinding();

   /**
    * The algorithm
    * @param startPosition position to start from
    * @param targetPosition position to end with
    */
   void find(Vector<float> startPosition, Vector<float> targetPosition);

   /**
    * Get the root node which will contain the path. If there is not path it will return a nullptr
    */
   Node * getPath();

   /**
    * Return the stored map
    */
   Map & getMap();

private:
   float rotationRadius;
   Vector<float> ATVSize;
   RotationOption * rotationMath;
   Map & map;
   Node * root;
   bool working;

   bool isColliding(const Node & node) const;

   float distance(Vector<float> point, Vector<float> targetPosition) const;

};

#endif // PATHFINDING_H
