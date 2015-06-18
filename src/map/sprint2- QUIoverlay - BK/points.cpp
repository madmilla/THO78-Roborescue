#include "points.h"

points::points(int mX, int mY)
{
    x = mX;
    y = mY;
}

points::~points(){}

std::ostream & operator<< (std::ostream &out, const points &p){
    return out << "(" << p.x << "," << p.y << ")";
}

/*bool operator==(const point & lhs, const point & rhs){
    return lhs.x == rhs.x && lhs.y == rhs.y;
}*/

bool points::equals(const points & p){
    return x == p.x && y == p.y;
}

int points::getX() const { return x; }
int points::getY() const { return y; }
