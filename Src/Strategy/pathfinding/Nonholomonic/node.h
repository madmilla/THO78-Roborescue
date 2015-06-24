#ifndef NODE_H
#define NODE_H

#include <array>
#include "vector.h"

/**
* @class   Node
* @author  Wibren Wiersma
* @date    Juni, 2015
* @brief   This class is the Node. A node is a part of the path
*/
class Node
{
public:
   /**
    * Direction of the node looked from the previeus node. Turned Left, Straight or Right.
    */
   enum class Direction : char{Left = 0, Straigth = 1, Right = 2};

   /**
    * Create a not from a position. ROOT ONLY
    */
   Node(Vector<float> position);
   /**
    * Add a new node to its parent, with a position and rotation
    */
   Node(Node & parent, Vector<float> position, int rotation);

   /**
     * Deconstructor of the node
     */
   ~Node();

   /**
    * Get the parent of the node. If its the root it will return a nullptr.
    */
   Node * parent();

   /**
    * Get one of the childs of the node. If it has not any childs it will return a nullptr
    */
   Node * getChild(Direction dir);

   /**
    * Set the childs of this node
    * @param c1 Left child node
    * @param c2 Straight child node
    * @param c3 Right child node
    */
   void setChilds(Node & c1, Node & c2, Node & c3);

   /**
    * Return true if all child nodes are death or it has set to death.
    * @return
    */
   bool isDeath();
   /**
    * Make current node death
    */
   void setDeath();

   /**
    * Get the stored order, if death it will return -1
    */
   float getOrder();

   /**
    * Set an order
    */
   void setOrder(float order);

   /**
    * get the position of the node
    */
   Vector<float> getPosition() const;
   /**
    * get the rotation of the node
    */
   int getRotation() const;

   /**
    * Returns true if node has childs and isn't death
    */
   bool isPath();

   /**
    * Order when child is death (-1)
    */
   static const float deathOrder;

   /**
    * Set or unset drawing state. If in drawing state the childs will not deleted until the drawing state is over.
    */
   void setDrawing(bool value);

private:
   Node * pparent;
   std::array<Node *, 3> childs;
   bool death;
   float order;
   bool drawing;

   Vector<float> position;
   int rotation;
};

#endif // NODE_H
