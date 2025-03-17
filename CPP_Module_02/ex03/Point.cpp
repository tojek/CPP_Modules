#include "Point.hpp"

Point::Point() : x(0), y(0)
{
}

Point::~Point()
{
}

Point::Point(const Point &copy) : x(copy.getX()), y(copy.getY())
{
}

Point::Point(const float x, const float y) : x(x), y(y)
{
}

Point::Point(const Fixed x, const Fixed y) : x(x), y(y)
{
}

Point &Point::operator = (const Point &point_operator)
{
	return (*this);
}

Fixed Point::getX() const
{
	return (this->x);
}

Fixed Point::getY() const
{
	return (this->y);
}
