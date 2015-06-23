#ifndef VECTOR_H
#define VECTOR_H

#include <cmath>

template<typename T> class Vector
{
public:
   Vector() : x(0), y(0) {}
   Vector(T x, T y) : x(x), y(y) {}

   T x;
   T y;

   double length() const {
      return std::sqrt(x * x + y * y);
   }

   T length2() const {
      return x * x + y * y;
   }

   double distance(const Vector<T> target) const{
      return (*this - target).length();
   }

   T distance2(const Vector<T> target) const{
      return (*this - target).length2();
   }

   Vector<T> operator*(const T length) const{
      return Vector<T>(x * length, y * length);
   }

   Vector<T> operator+(const Vector<T> v2) const{
      return Vector<T>(x + v2.x, y + v2.y);
   }

   Vector<T> operator-(const Vector<T> v2) const{
      return Vector<T>(x - v2.x, y - v2.y);
   }

   Vector<T> operator/(const T length) const{
      return Vector<T>(x / length, y / length);
   }

   bool operator==(const Vector<T> v2) const{
      return this->x == v2.x && this->y == v2.y;
   }

   Vector<T> base() const{
      return (*this) / (T)this->length();
   }

   ///Warning this is a base vector!
   T projectOn(const Vector<T> target) const{
      return this->x * target.x + this->y * target.y;
   }
};

#endif // VECTOR_H
