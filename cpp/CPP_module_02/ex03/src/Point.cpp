#include "../inc/Point.hpp"
#include "../inc/Fixed.hpp"
#include <cmath>

// CONSTRUCTORS && DESTROYER
Point::Point(void ) : _x(0), _y(0) { }
Point::Point(const float x, const float y) : _x(Fixed(x)), _y(Fixed(y)) { }
Point::Point(const Point &p) : _x(p.getX()), _y(p.getY()) { }
Point::~Point( void ) { }

Point &Point::operator = (const Point &p) {
	const_cast<Fixed &>(this->_x) = p.getX();
	const_cast<Fixed &>(this->_y) = p.getX();
	return (*this);
}

// GETTERS
const Fixed	Point::getX(void) const { return (_x); }
const Fixed	Point::getY(void) const { return (_y); }

// OSTREAM OVERIDE
std::ostream &operator << (std::ostream &o, Point const &p) {
	o << "[" << p.getX().toFloat() << ", " << p.getY().toFloat() << "]";
	return o;
}