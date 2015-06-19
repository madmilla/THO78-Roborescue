#ifndef WAYPOINT_H
#define WAYPOINT_H


class WayPoint
{
public:
	bool WayPoint::operator==(const WayPoint &other) const {
		if (other.x == this->x &&other.y == this->y){ return true; }
		else return false;
	}
    int x;
    int y;
    WayPoint(int x, int y);
    ~WayPoint();
};

#endif // WAYPOINT_H
