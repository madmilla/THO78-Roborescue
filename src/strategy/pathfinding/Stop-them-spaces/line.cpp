#include "line.hpp"

line::line(point mP1, point mP2)
{
    p1 = mP1;
    p2 = mP2;
}

line::~line(){}

std::ostream & operator<<(std::ostream & os, const line & l){
    return os << "[" << l.p1 << "," << l.p2 << "]";
}

/*bool operator==(const line & lhs, const line & rhs){
    return lhs.p1 == rhs.p1 && lhs.p2 == rhs.p2;
}*/

bool line::equals(const line & l){
    return p1.equals(l.p1) && p2.equals(l.p2);
}

point line::getPoint(int n){
    return (n == 1) ? p2 : p1;
}

std::pair<point, point> line::getPoints(){
    return std::pair<point, point>(p1, p2);
}
