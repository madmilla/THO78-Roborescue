#include "point.hpp"

point::point(int mX, int mY)
{
    x = mX;
    y = mY;
}

point::~point(){}

std::ostream & operator<< (std::ostream &out, const point &p){
    return out << "(" << p.x << "," << p.y << ")";
}

/*bool operator==(const point & lhs, const point & rhs){
    return lhs.x == rhs.x && lhs.y == rhs.y;
}*/

bool point::equals(const point & p){
    return x == p.x && y == p.y;
}

int point::getX(){ return x; }
int point::getY(){ return y; }
