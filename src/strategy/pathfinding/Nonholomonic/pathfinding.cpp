#include "pathfinding.h"

#include "rotation30.h"
#include <cfloat>

PathFinding::PathFinding(float rotationRadius, Vector<float> ATVSize, Map &map) :
   rotationRadius(rotationRadius),
   rotationMath(new Rotation30(rotationRadius, ATVSize)),
   root(nullptr),
   ATVSize(ATVSize),
   map(map),
   working(false)
{}

PathFinding::~PathFinding(){
   delete rotationMath;
}

float PathFinding::distance(Vector<float> point, Vector<float> targetPosition) const{
   return point.distance(targetPosition);
}

bool PathFinding::isColliding(const Node & node) const{
   MapItem atv = rotationMath->getATVPosition(node.getPosition(), node.getRotation());
   return map.isColliding(atv);
}

void PathFinding::find(Vector<float> startPosition, Vector<float> targetPosition){
   const float near = rotationMath->getStraightLength() * rotationMath->getStraightLength() * 1.1f;
   if(working) return;
   working = true;

   delete root;
   root = new Node(startPosition);

   Node * currentNode = root;
   while(currentNode->getPosition().distance2(targetPosition) > near){ //EXPLORE LUS
      //qDebug() << currentNode->getPosition().distance2(targetPosition) << "\n";
      //std::this_thread::sleep_for(std::chrono::seconds(1));

      //Create childs
      Node * childs[3];
      childs[0] = new Node(*currentNode,
                    rotationMath->newPosition(currentNode->getPosition(),
                                              currentNode->getRotation(),
                                              Node::Direction::Left),
                    rotationMath->newRotation(currentNode->getRotation(),
                                              Node::Direction::Left));
      childs[1] = new Node(*currentNode,
                    rotationMath->newPosition(currentNode->getPosition(),
                                              currentNode->getRotation(),
                                              Node::Direction::Straigth),
                    rotationMath->newRotation(currentNode->getRotation(),
                                              Node::Direction::Straigth));
      childs[2] = new Node(*currentNode,
                    rotationMath->newPosition(currentNode->getPosition(),
                                              currentNode->getRotation(),
                                              Node::Direction::Right),
                    rotationMath->newRotation(currentNode->getRotation(),
                                              Node::Direction::Right));
      currentNode->setChilds(*childs[0], *childs[1], *childs[2]);

      //check collision en set order of childs
      for(int i = 0; i < 3; i++){
         if(isColliding(*childs[i])){
            childs[i]->setDeath();
         }else{
            childs[i]->setOrder(distance(childs[i]->getPosition(), targetPosition));
         }
      }

      while(currentNode != nullptr){ //SELECTION LUS

         bool isDeath = true;
         float min = FLT_MAX;
         int minI = 0;

         for(int i = 0; i < 3; i++){ //check if all childs are colliding and/or get child with fewest distance
            Node * child = currentNode->getChild(static_cast<Node::Direction>(i));
            if(!child->isDeath()){
               isDeath = false;
               if(child->getOrder() < min){
                  min = child->getOrder();
                  minI = i;
               }
            }
         }

         if(isDeath){ //all childs are colliding
            currentNode->setDeath(); //delete also its childs
            currentNode = currentNode->parent(); //go back one
         }else{
            currentNode = currentNode->getChild(static_cast<Node::Direction>(minI)); //new most promesing child founded
            break; //BREAK SELECTION LUS GOTO EXPLORE LUS
         }
      } //END SELECTION LUS

      if(currentNode == nullptr){
         working = false;
         //qDebug() << "No solution found!\n";
         return;
      }
   } //END EXPLORE LUS

   working = false;
   //qDebug() << "Solution found!\n";
   //FOUND A PATH
}

Node * PathFinding::getPath(){
   return root;
}

Map & PathFinding::getMap(){
   return map;
}
