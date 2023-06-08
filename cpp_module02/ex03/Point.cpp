#include "Point.hpp"

Point::Point()
{
}

Point::Point(float const x, float const y) : x(x), y(y)
{
}


Point::Point(const Point &p) : x(p.getX()), y(p.getY())
{
}

Point &Point::operator=(const Point &p)
{
	if (this != &p)
	{
		const_cast<Fixed &>(this->x) = p.getX();
		const_cast<Fixed &>(this->y) = p.getY();
	}
	return *this;
}

Fixed Point::getX() const
{
	return this->x;
}

Fixed Point::getY() const
{
	return this->y;
}

Point::~Point()
{
}
