#ifndef MAPITEM_H
#define MAPITEM_H

#include <vector>
#include "vector.h"

#include <QPolygonF>
#include <QGraphicsPolygonItem>

class MapItem
{
public:
   MapItem();
   MapItem(std::vector<Vector<float>> points);

   void addPoint(Vector<float> point);
   void removePoint(Vector<float> point);
   void removePoint(int index);

   Vector<float> operator[](int index) const;

   std::vector<Vector<float>>::const_iterator begin() const;
   std::vector<Vector<float>>::const_iterator end() const;

   bool isColliding(const MapItem & other) const;
   Vector<float> projectOn(const Vector<float> vector) const;

private:
   std::vector<Vector<float>> points;
};

#endif // MAPITEM_H
