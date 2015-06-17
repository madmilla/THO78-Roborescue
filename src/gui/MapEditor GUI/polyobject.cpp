#include "polyobject.h"

polyObject::polyObject(std::vector<point> p)
{
    shape = p;
}

std::vector<point> polyObject::getShape(){
    return shape;
}

bool polyObject::equals(polyObject & po){
    if(shape.size() != po.getShape().size()) return false;

    std::vector<point> tmp = po.getShape();
    for(unsigned int i = 0; i < shape.size(); i++){
        if(tmp[i].equals(shape[i])) return false;
    }

    return true;
}
