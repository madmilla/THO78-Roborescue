#ifndef OBJECT_H
#define OBJECT_H
#include <QtGui>

class Object
{
public:
    Object(QColor color, QPoint location);
    ~Object();
    QColor color;
    QPoint location;
};

#endif
