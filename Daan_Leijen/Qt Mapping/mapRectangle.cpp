#include "mapRectangle.h"

mapRectangle::mapRectangle(QRectF rect, char rectType):
    rectangle(rect),
    type(rectType)
{

}

mapRectangle::mapRectangle() {

}

mapRectangle::~mapRectangle() {

}

char mapRectangle::getType() {
    return type;
}

QRectF mapRectangle::getRectangle(){
    return rectangle;
}
