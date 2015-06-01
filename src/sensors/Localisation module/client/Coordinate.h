#ifndef _COORDINATE_H
#define _COORDINATE_H

template<typename T>
class Coordinate
{
public:
	Coordinate();
	Coordinate(T x, T y);
	Coordinate(const Coordinate& coordinate);

	T getX() const;
	T getY() const;

	void setX(T x);
	void setY(T y);
	void setXY(T x, T y);

	//TODO: create additional operators to make this an actual ADT
private:
	T x, y;
};

template <typename T>
Coordinate<T>::Coordinate() :
x{ 0 },
y{ 0 }
{
}

template <typename T>
Coordinate<T>::Coordinate(T newX, T newY) :
x{ newX },
y{ newY }
{
}

template <typename T>
Coordinate<T>::Coordinate(const Coordinate& coordinate) :
x{ coordinate.getX() },
y{ coordinate.getY() }
{
}

template <typename T>
T Coordinate<T>::getX() const
{
	return x;
}

template <typename T>
T Coordinate<T>::getY() const
{
	return y;
}

template <typename T>
void Coordinate<T>::setX(T newX)
{
	x = newX;
}

template <typename T>
void Coordinate<T>::setY(T newY)
{
	y = newY;
}

template <typename T>
void Coordinate<T>::setXY(T newX, T newY)
{
	x = newX;
	y = newY;
}
#endif