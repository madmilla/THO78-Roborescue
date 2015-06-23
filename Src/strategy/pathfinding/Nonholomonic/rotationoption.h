#ifndef ROTATIONOPTION
#define ROTATIONOPTION

#include "node.h"
#include "mapitem.h"

class RotationOption{
public:
   RotationOption(float rotationRadius, int rotationCount);

   virtual ~RotationOption(){}
   virtual Vector<float> newPosition(Vector<float> oldPosition, int oldRotation, Node::Direction direction) = 0;
   virtual MapItem getATVPosition(Vector<float> position, int rotation) = 0;

   int newRotation(int oldRotation, Node::Direction direction) const;

   float getStraightLength() const;

protected:
   float rotationRadius;
   float straightLength;
   int rotationCount;
};

#endif // ROTATIONOPTION

