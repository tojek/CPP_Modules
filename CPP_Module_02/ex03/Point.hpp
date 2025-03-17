#ifndef POINT_HPP
# define POINT_HPP

#include <iostream>
#include "Fixed.hpp"

class Point
{
	public:
		Point();
		~Point();
		Point(const Point &copy);
		Point(const float x, const float y);
		Point(const Fixed x, const Fixed y);
		Point &operator = (const Point &point_operator);

		Fixed getX() const;
		Fixed getY() const;
		void setX(Fixed f);
		void setY(Fixed f);
	private:
		Fixed const x;
		Fixed const y;
};
bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif