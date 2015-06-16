#ifndef NODE_H
#define NODE_H

#include <array>
#include "vector.h"

class Node
{
public:
   enum class Direction : char{Left = 0, Straigth = 1, Right = 2};

   Node(Vector<float> position);
   Node(Node & parent, Vector<float> position, int rotation);

   ~Node();

   Node * parent();

   Node * getChild(Direction dir);

   void setChilds(Node & c1, Node & c2, Node & c3);

   bool isDeath();
   void setDeath();

   float getOrder();

   void setOrder(float order);

   Vector<float> getPosition() const;
   int getRotation() const;

   bool isPath();

   static const float deathOrder;

private:
   Node * pparent;
   std::array<Node *, 3> childs;
   bool death;
   float order;

   Vector<float> position;
   int rotation;
};

#endif // NODE_H
