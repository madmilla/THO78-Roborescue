#include "composedpolygon.h"

composedPolygon::composedPolygon(point p)
{
    //polygon = std::vector<point>();
    polygon.push_back(p);
    //std::cout << "composedPolygon constructor\n";
}

composedPolygon::~composedPolygon(){
    //delete polygon;
}

void composedPolygon::nextPoint(point p){
    polygon.push_back(p);
    //std::cout << "composedPolygon nextPoint\n";
}

std::vector<point> composedPolygon::applyPolygon(){
    polygon.push_back(polygon.front());
    return polygon;
}
