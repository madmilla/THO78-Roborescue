#include "mapitem.h"

#include <algorithm>

MapItem::MapItem() {}
MapItem::MapItem(std::vector<Vector<float>> points) : points(points) {}

void MapItem::addPoint(Vector<float> point){
   points.push_back(point);
}

void MapItem::removePoint(Vector<float> point){
   points.erase(std::remove(points.begin(), points.end(), point), points.end());
}

void MapItem::removePoint(int index){
   points.erase(points.begin() + index);
}

Vector<float> MapItem::operator[](int index) const{
   return points.at(index);
}

int MapItem::pointCount() const{
   return points.size();
}

std::vector<Vector<float>>::const_iterator MapItem::begin() const{
   return points.begin();
}

std::vector<Vector<float>>::const_iterator MapItem::end() const{
   return points.end();
}

bool MapItem::isColliding(const MapItem & other) const{
   int pointCountThis = this->points.size();
   int pointCountOther = other.points.size();

   for (int i = 0; i < pointCountThis; i++) {
      Vector<float> vector = (points.at(i) - points.at((i + 1) % pointCountThis)).base();
      Vector<float> answerThis = projectOn(vector); //x == min, y == max
      Vector<float> answerOther = other.projectOn(vector); //x == min, y == max

      if (answerThis.x < answerOther.x && answerOther.x < answerThis.y) { //min this < min other && min other < max this
         continue; //collision check next
      } else if (answerThis.x < answerOther.y && answerOther.y < answerThis.y) { //min this < max other && max other < max this
         continue; //collision check next
      } else if (answerOther.x < answerThis.x && answerThis.x < answerOther.y) {
         continue; //collision check nest
      } else {
         return false; //nocollision exit
      }
   }

   for (int i = 0; i < pointCountOther; i++) {
      Vector<float> vector = (points.at(i), points.at((i + 1) % pointCountOther)).base();
      Vector<float> answerThis = projectOn(vector); //x == min, y == max
      Vector<float> answerOther = other.projectOn(vector); //x == min, y == max

      if (answerThis.x < answerOther.x && answerOther.x < answerThis.y) { //min this < min other && min other < max this
         continue; //collision check next
      } else if (answerThis.x < answerOther.y && answerOther.y < answerThis.y) { //min this < max other && max other < max this
         continue; //collision check next
      } else if (answerOther.x < answerThis.x && answerThis.x < answerOther.y) {
         continue; //collision check nest
      } else {
         return false; //nocollision exit
      }
   }

   return true;
}

Vector<float> MapItem::projectOn(const Vector<float> vector) const {
   float min, max;
   min = max = vector.projectOn(points.at(0));

   unsigned int pointCount = points.size();

   for (unsigned int i = 1; i < pointCount; i++) {
      float result = vector.projectOn(points.at(i));
      min = std::min(min, result);
      max = std::max(max, result);
   }

   return Vector<float>(min, max);
}
