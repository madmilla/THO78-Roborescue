#ifndef ROTATION30_H
#define ROTATION30_H

#include "rotationoption.h"

class Rotation30 : public RotationOption
{
public:
   Rotation30(float rotationRadius, Vector<float> size);

   Vector<float> newPosition(Vector<float> oldPosition, int oldRotation, Node::Direction direction) override;
   MapItem getATVPosition(Vector<float> position, int rotation) override;

private:
   static const Vector<float> baseRotationPoints[12];
   Vector<float> rotationPoints[12];
   Vector<float> atvRotations[12][4];
};

#endif // ROTATION30_H
