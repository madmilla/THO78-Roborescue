#ifndef ROTATIONOPTION
#define ROTATIONOPTION

#include "node.h"
#include "mapitem.h"

/**
* @class   RotationOption
* @author  Wibren Wiersma
* @date    Juni, 2015
* @brief   This class is an implementation of the RotationOption class wich contains the functionality for 30 degree of the rotation circle
*/
class RotationOption{
public:
   /**
    * Creates the rotation math class by the rotation radius of the robot and the count of rotations to complete a 360 degree circle
    */
   RotationOption(float rotationRadius, int rotationCount);

   /**
    * Virutal deconstructor to avoid interface deletions with memory leaks
    */
   virtual ~RotationOption(){}

   /**
    * Calculate a new posistion for a node based on the parent node position and rotation
    * @param oldPosition position of the parent node
    * @param oldRotation roation of the parent node
    * @param direction the direction of the new node based on the difference between the parent node
    */
   virtual Vector<float> newPosition(Vector<float> oldPosition, int oldRotation, Node::Direction direction) = 0;

   /**
    * Get a rotated and translated mapitem of a atv. How the atv will stand on the node as a collision object.
    * @param position of the node
    * @param rotation of the node
    * @return an mapitem what can be used for collision checks.
    */
   virtual MapItem getATVPosition(Vector<float> position, int rotation) = 0;

   /**
    * get the new rotation for a node, based on its parent roation and its direction relative to its parent
    * @param oldRotation rotation of the parent
    * @param direction the direction of the rotaion relative to the parent
    */
   int newRotation(int oldRotation, Node::Direction direction) const;

   /**
    * Get the radian of the an roation angle based on the rotationRadius
    */
   float getStraightLength() const;

protected:
   float rotationRadius;
   float straightLength;
   int rotationCount;
};

#endif // ROTATIONOPTION

