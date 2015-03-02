#include "object.h"


Object::Object(ObjectType type, QPoint position)
    :
    type{type},
    position{position}
{
}


Object::~Object()
{
}
