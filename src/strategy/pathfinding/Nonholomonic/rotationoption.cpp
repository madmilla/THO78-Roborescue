#include "rotationoption.h"

RotationOption::RotationOption(float rotationRadius, int rotationCount) :
   rotationRadius(rotationRadius),
   rotationCount(rotationCount),
   straightLength(((2.0f * M_PI) / rotationCount) * rotationRadius)
{}

int RotationOption::newRotation(int oldRotation, Node::Direction direction) const{
   if(direction == Node::Direction::Straigth)
      return oldRotation;
   else if(direction == Node::Direction::Left)
      return oldRotation + 1 >= rotationCount ? 0 : oldRotation + 1;
   else
      return oldRotation - 1 < 0 ? rotationCount - 1 : oldRotation - 1;
}

float RotationOption::getStraightLength() const{
   return straightLength;
}
