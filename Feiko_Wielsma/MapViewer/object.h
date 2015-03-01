#ifndef OBJECT_H
#define OBJECT_H
#include <QtGui>

enum class ObjectType {
    Empty,
    Wall,
    Tree,
    Quad,
    ATV
};

class Object
{
public:
    Object(ObjectType type, QPoint position);
    ~Object();
    ObjectType type;
    QPoint position;
};

#endif
