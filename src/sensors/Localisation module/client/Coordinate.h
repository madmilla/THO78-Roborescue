#ifndef _COORDINATE_H
#define _COORDINATE_H

template<typename T>
class Coordinate
{
public:
	Coordinate();
	Coordinate(T x, T y);
	Coordinate(const Coordinate& coordinate);

	/**
	* \brief Get X position of the coordinate.
	*
	* This method will return the X position of the coordinate. 
	*
	* \return x the X poosition of coordinate.
	*/
	T getX() const;

	/**
	* \brief Get Y position of the coordinate.
	*
	* This method will return the Y position of the coordinate.
	*
	* \return y the Y poosition of coordinate.
	*/
	T getY() const;

	/**
	* \brief Set X position of the coordinate.
	*
	* This method will set the X position of the coordinate. Any old X value will be overwritten.
	*
	* \param x the new X position of the coordinate.
	*/
	void setX(T x);

	/**
	* \brief Set Y position of the coordinate.
	*
	* This method will set the Y position of the coordinate. Any old Y value will be overwritten.
	*
	* \param y the new Y position of the coordinate.
	*/
	void setY(T y);

	/**
	* \brief Set X and Y position of the coordinate.
	*
	* This method will set both the X and Y position of the coordinate. Any old X and Y value will be overwritten.
	*
	* \param x the new X position of the coordinate.
	* \param y the new Y position of the coordinate.
	*/
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