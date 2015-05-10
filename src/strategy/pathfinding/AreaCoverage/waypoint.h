#ifndef WAYPOINT_H
#define WAYPOINT_H

class WayPoint {
public:
  int x;
  bool operator==(WayPoint w) {
    if (this->x == w.x && this->y == w.y) {
      return true;
    } else {
      return false;
    }
  }
  int y;
  WayPoint(int x, int y);
  ~WayPoint();
};

#endif // WAYPOINT_H
