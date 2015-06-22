#ifndef PATHFINDING_H
#define PATHFINDING_H

#include "vector.h"
#include "rotationoption.h"
#include "node.h"
#include "map.h"

class PathFinding
{
public:
   PathFinding(float rotationRadius, Vector<float> ATVSize, Map & map);
   ~PathFinding();
   void find(Vector<float> startPosition, Vector<float> targetPosition);

   bool isColliding(const Node & node) const;

   float distance(Vector<float> point, Vector<float> targetPosition) const;

   Node * getPath();

   Map & getMap();

private:
   float rotationRadius;
   Vector<float> ATVSize;
   RotationOption * rotationMath;
   Map & map;
   Node * root;
   bool working;

};

#endif // PATHFINDING_H
