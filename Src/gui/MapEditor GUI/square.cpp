#include "square.h"

square::square(point p, int w, int h, char t)
    : begin{p},
      width{w},
      height{h},
      type{t}
{}

bool square::equals(square & s){
    if(!begin.equals(s.getStart())) return false;
    if(!(width == s.getWidth())) return false;
    if(!(height == s.getHeight())) return false;
    if(!(type == s.getType())) return false;
    return true;
}

point square::getStart(){
    return begin;
}

int square::getWidth(){
    return width;
}

int square::getHeight(){
    return height;
}

char square::getType(){
    return type;
}
