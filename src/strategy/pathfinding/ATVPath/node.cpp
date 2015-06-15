#include "node.h"

const float Node::deathOrder = -1.0f;

Node::Node(Vector<float> position) :
   pparent(nullptr),
   childs({nullptr, nullptr, nullptr}),
   death(false),
   position(position),
   rotation(0)
{}

Node::Node(Node & parent, Vector<float> position, int rotation) :
   pparent(&parent),
   childs({nullptr, nullptr, nullptr}),
   death(false),
   position(position),
   rotation(rotation)
{}

Node::~Node(){
   setDeath();
}

Node * Node::parent() {
   return pparent;
}

Node * Node::getChild(Direction dir){
   return childs[static_cast<int>(dir)];
}

void Node::setChilds(Node & c1, Node & c2, Node & c3){
   childs[0] = &c1;
   childs[1] = &c2;
   childs[2] = &c3;
}

bool Node::isDeath(){
   return death;
}

void Node::setDeath(){
   death = true;
   delete childs[0];
   delete childs[1];
   delete childs[2];
   childs[0] = nullptr;
   childs[1] = nullptr;
   childs[2] = nullptr;
}

float Node::getOrder(){
   if(death) return deathOrder;
   return order;
}

void Node::setOrder(float order){
   this->order = order;
}

Vector<float> Node::getPosition(){
   return position;
}

int Node::getRotation(){
   return rotation;
}

bool Node::isPath(){
   if(death) return false;
   return childs[0] != nullptr;
}
