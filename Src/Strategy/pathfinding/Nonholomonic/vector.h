#ifndef VECTOR_H
#define VECTOR_H

#include <cmath>

/**
* @class   Vector
* @author  Wibren Wiersma
* @date    Juni, 2015
* @brief   This is an class to hold vector data
*/
template<typename T> class Vector
{
public:
   /**
    * Create a vector with x and y on 0
    */
   Vector() : x(0), y(0) {}

   /**
    * Create a vector with the given x and y
    */
   Vector(T x, T y) : x(x), y(y) {}

   /**
    * Public x attribute
    */
   T x;
   /**
    * Public y attribute
    */
   T y;

   /**
    * length of the vector with pytagoras
    */
   double length() const {
      return std::sqrt(x * x + y * y);
   }

   /**
    * length of the vector with pytagoras without doing the squart root of it
    */
   T length2() const {
      return x * x + y * y;
   }

   /**
    * get the distance between to vectors with pytagoras
    */
   double distance(const Vector<T> target) const{
      return (*this - target).length();
   }

   /**
    * get the distance between to vectors with pytagoras without doing the squart root of it
    */
   T distance2(const Vector<T> target) const{
      return (*this - target).length2();
   }

   /**
    * Multiply both the x and the y by the given length
    * @param length var to multiplay by the x and the y
    */
   Vector<T> operator*(const T length) const{
      return Vector<T>(x * length, y * length);
   }

   /**
    * Add two vectors together x's and y's together
    */
   Vector<T> operator+(const Vector<T> v2) const{
      return Vector<T>(x + v2.x, y + v2.y);
   }

   /**
    * Minus two vectors together x's and y's together
    */
   Vector<T> operator-(const Vector<T> v2) const{
      return Vector<T>(x - v2.x, y - v2.y);
   }

   /**
    * Devide a vectors's x and y by the given length
    */
   Vector<T> operator/(const T length) const{
      return Vector<T>(x / length, y / length);
   }

   /**
    * Check if to vectors are equal
    */
   bool operator==(const Vector<T> v2) const{
      return this->x == v2.x && this->y == v2.y;
   }

   /**
    * Get the base vector of a vector. This is the vector devide by its length
    */
   Vector<T> base() const{
      return (*this) / (T)this->length();
   }

   /**
   * Project a vector on a vector. But will only work good if this is a BASE VECTOR
   */
   T projectOn(const Vector<T> target) const{
      return this->x * target.x + this->y * target.y;
   }
};

#endif // VECTOR_H
