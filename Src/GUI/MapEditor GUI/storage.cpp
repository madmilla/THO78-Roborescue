#include "storage.h"
#include <iostream>

storage::storage()
{
    //polyObjects = new std::vector<polyObject>;
    //objects = new std::vector<square>;
}

void storage::addPolyObject(polyObject obj){
    polyObjects.push_back(obj);
}

std::vector<polyObject> storage::getPolyObjects(){
    return polyObjects;
}

void storage::addObject(point p, int width, int height, char type){
    //square tmp = square(p, width, height, type);
    //square tm = square(p, width, height);
    objects.push_back(square(p, width, height, type));
}

std::vector<square> storage::getObjects(){
    return objects;
}

void storage::deletePolyObject(polyObject p){
    if(polyObjects.size()<= 0) return;
    std::vector<polyObject>::iterator track = polyObjects.begin();
    while(track != polyObjects.end()){
        if(track->equals(p)){
            polyObjects.erase(track);
            break;
        }
        ++track;
    }
}

void storage::deleteObject(point p, int width, int height, char type){
    std::cout << p << ", " << width << ", " << height << ", " << type << std::endl;
    if(objects.size()<=0) return;
    square tmp = square(p, width, height, type);
    std::vector<square>::iterator track = objects.begin();
    while (track != objects.end()){
        if(track->equals(tmp)){
            objects.erase(track);
            break;
        }
        ++track;
    }
}
