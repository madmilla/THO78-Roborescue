#ifndef ROTATION30_H
#define ROTATION30_H

#include "rotationoption.h"

/**
* @class   Rotation30
* @author  Wibren Wiersma
* @date    Juni, 2015
* @brief   This class is an implementation of the RotationOption class wich contains the functionality for 30 degree of the rotation circle
*/
class Rotation30 : public RotationOption
{
public:
   /**
    * Creates the rotation 30 degree math class by the rotation radius of the robot and its size
    */
   Rotation30(float rotationRadius, Vector<float> size);

   /**
    * Calculate a new posistion for a node based on the parent node position and rotation
    * @param oldPosition position of the parent node
    * @param oldRotation roation of the parent node
    * @param direction the direction of the new node based on the difference between the parent node
    */
   Vector<float> newPosition(Vector<float> oldPosition, int oldRotation, Node::Direction direction) override;

   /**
    * Get a rotated and translated mapitem of a atv. How the atv will stand on the node as a collision object.
    * @param position of the node
    * @param rotation of the node
    * @return an mapitem what can be used for collision checks.
    */
   MapItem getATVPosition(Vector<float> position, int rotation) override;

private:
   static const Vector<float> baseRotationPoints[12];
   Vector<float> rotationPoints[12];
   Vector<float> atvRotations[12][4];
};

#endif // ROTATION30_H
