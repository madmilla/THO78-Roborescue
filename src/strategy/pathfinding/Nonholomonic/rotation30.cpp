#include "rotation30.h"

const Vector<float> Rotation30::baseRotationPoints[12] = {
   Vector<float>(1, 0),
   Vector<float>(std::cos(1.0f * 1.0f / 6.0f * M_PI), std::sin(1.0f * 1.0f / 6.0f * M_PI)),
   Vector<float>(std::cos(2.0f * 1.0f / 6.0f * M_PI), std::sin(2.0f * 1.0f / 6.0f * M_PI)),
   Vector<float>(0, 1),
   Vector<float>(std::cos(4.0f * 1.0f / 6.0f * M_PI), std::sin(4.0f * 1.0f / 6.0f * M_PI)),
   Vector<float>(std::cos(5.0f * 1.0f / 6.0f * M_PI), std::sin(5.0f * 1.0f / 6.0f * M_PI)),
   Vector<float>(-1, 0),
   Vector<float>(std::cos(7.0f * 1.0f / 6.0f * M_PI), std::sin(7.0f * 1.0f / 6.0f * M_PI)),
   Vector<float>(std::cos(8.0f * 1.0f / 6.0f * M_PI), std::sin(8.0f * 1.0f / 6.0f * M_PI)),
   Vector<float>(0, -1),
   Vector<float>(std::cos(10.0f * 1.0f / 6.0f * M_PI), std::sin(10.0f * 1.0f / 6.0f * M_PI)),
   Vector<float>(std::cos(11.0f * 1.0f / 6.0f * M_PI), std::sin(11.0f * 1.0f / 6.0f * M_PI)),
};

MapItem Rotation30::getATVPosition(Vector<float> position, int rotation){
   MapItem mi;
   for(int i = 0; i < 4; i++){
      mi.addPoint(position + atvRotations[rotation][i]);
   }
   return mi;
}

Rotation30::Rotation30(float rotationRadius, Vector<float> size) : RotationOption(rotationRadius, 12)
{
   Vector<float> atvPoints[4] = {
      Vector<float>(size.x, size.y),
      Vector<float>(-size.x, size.y),
      Vector<float>(-size.x, -size.y),
      Vector<float>(size.x, -size.y)
   };

   for(int i = 0; i < 12; i++) {
	   rotationPoints[i] = baseRotationPoints[i] * rotationRadius;
   }

   for(int i = 0; i < 12; i++){
      for(int j = 0; j < 4; j++){
         float s = baseRotationPoints[i].y;
         float c = baseRotationPoints[i].x;
         atvRotations[i][j] = Vector<float>(atvPoints[j].x * c - atvPoints[j].y * s, atvPoints[j].x * s + atvPoints[j].y * c);
      }
   }
}

Vector<float> Rotation30::newPosition(Vector<float> oldPosition, int oldRotation, Node::Direction direction){
   if(direction == Node::Direction::Straigth){
      return oldPosition + baseRotationPoints[oldRotation] * straightLength;
   }else {
      int oldRotationRelative;
      if(direction == Node::Direction::Left){
         oldRotationRelative = oldRotation - 3;
         if(oldRotationRelative < 0) oldRotationRelative += 12;
      }else{
         oldRotationRelative = oldRotation + 3;
         if(oldRotationRelative >= 12) oldRotationRelative -= 12;
      }

      int newRotationRelative = RotationOption::newRotation(oldRotationRelative, direction);
      Vector<float> rotationPoint = oldPosition - rotationPoints[oldRotationRelative];
      return rotationPoint + rotationPoints[newRotationRelative];
   }
}
