#ifndef ROTATIONOPTION
#define ROTATIONOPTION

#include "node.h"
#include "mapitem.h"

class RotationOption{
public:
   RotationOption(float rotationRadius, int rotationCount) : rotationRadius(rotationRadius), rotationCount(rotationCount) {}

   virtual ~RotationOption(){}
   virtual Vector<float> newPosition(Vector<float> oldPosition, int oldRotation, Node::Direction direction) = 0;
   virtual MapItem getATVPosition(Vector<float> position, int rotation) = 0;

   int newRotation(int oldRotation, Node::Direction direction){
      if(direction == Node::Direction::Straigth)
         return oldRotation;
      else if(direction == Node::Direction::Left)
         return oldRotation + 1 >= rotationCount ? 0 : oldRotation + 1;
      else
         return oldRotation - 1 < 0 ? rotationCount - 1 : oldRotation - 1;
   }
protected:
   float rotationRadius;
   int rotationCount;
};

#endif // ROTATIONOPTION

