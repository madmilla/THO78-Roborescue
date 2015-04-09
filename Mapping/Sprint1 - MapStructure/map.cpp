#include "map.hpp"

map::map(){}

map::map(line & l){
    mapData.push_back(l);
}

map::map(std::vector<line> & l){
    mapData.insert(mapData.begin(), l.begin(), l.end());
}

std::ostream & operator<<(std::ostream & os, const map & m){
    for (const line & l : m.mapData)
    {
        os << l << "\n";
    }
    return os;
}

map::~map(){}

bool map::hasLine(line & l){
    for (const line & lCmp : mapData)
    {
        if (l.equals(lCmp)){
            return true;
        }
    }
    return false;
}

bool map::hasLine(std::vector<line> & l){
    for (line & lCmp : l)
    {
        if (!hasLine(lCmp))
            return false;
    }
    return true;
}

std::vector<line> map::getPointLines(point & p){
    std::vector<line> rtn;
    for (line & lCmp : mapData)
    {
        point a = lCmp.getPoint(0);
        point b = lCmp.getPoint(1);
        point c = p;

        int crossproduct = (c.getY() - a.getY()) * (b.getX() - a.getX()) - (c.getX() - a.getX()) * (b.getY() - a.getY());
        if (abs(crossproduct) != 0)
            continue;

        int dotproduct = (c.getX() - a.getX()) * (b.getX() - a.getX()) + (c.getY() - a.getY())*(b.getY() - a.getY());
        if (dotproduct < 0)
            continue;

        int squaredlengthba = (b.getX() - a.getX())*(b.getX() - a.getX()) + (b.getY() - a.getY())*(b.getY() - a.getY());
        if (dotproduct > squaredlengthba)
            continue;

        rtn.push_back(lCmp);
    }
    return rtn;
}

void map::appendLine(line & l){
    mapData.push_back(l);
}

void map::appendLine(std::vector<line> & l){
    mapData.insert(mapData.begin(), l.begin(), l.end());
}

bool map::removeLine(line & l){
    if (mapData.size() <= 0) return true;
    std::vector<line>::iterator track = mapData.begin();
    while (track != mapData.end()){
        if (track->equals(l)){
            mapData.erase(track);
            break;
        }
        ++track;
    }
    return !hasLine(l);
}

bool map::removeLine(std::vector<line> & l){
    for (line & lCmp : l)
    {
        removeLine(lCmp);
    }
    return hasLine(l);
}

bool map::equals(const map & m){
    if (mapData.size() != m.mapData.size())
        return false;

    map a = m;
    for (line & lCmp : mapData)
    {
        if (a.hasLine(lCmp)){
            a.removeLine(lCmp);
        }
        else{
            return false;
        }
    }

    if (a.mapData.size() == 0){
        return true;
    }
    return false;
}

map map::getRegion(int x, int y, unsigned int width, unsigned int height){
    map rtnMap{};
    int xEnd = x + width;
    int yEnd = y + height;
    for (line & lCmp : mapData)
    {
        // Begin point = 0, End point is 1
        // If begin is in region append line and skip end point check
        for (int i = 0; i < 2; i++){
            if (
                (lCmp.getPoint(i).getX() >= x && lCmp.getPoint(i).getX() <= xEnd)
                && lCmp.getPoint(i).getY() >= y && lCmp.getPoint(i).getY() <= yEnd
                ){
                rtnMap.appendLine(lCmp);
                break;
            }
        }
    }
    return rtnMap;
}

map map::getRegion(point & p, unsigned int width, unsigned int height){
    return getRegion(p.getX(), p.getY(), width, height);
}
