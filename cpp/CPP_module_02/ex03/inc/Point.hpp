#ifndef POINT_HPP
# define POINT_HPP

#include "../inc/Fixed.hpp"
# include <sstream> 
# include <iostream> 

class Point
{
	public:
		Point(void);							// default constructor
		Point(const float x, const float y);	// constructor
		Point(const Point &p);					// copy constructor
		~Point(void);							// destructor
		Point &operator = (const Point &p);		// copy assignment operator

		const Fixed	getX(void) const;
		const Fixed	getY(void) const;

	private:
		Fixed const	_x, _y;
};

std::ostream &operator << (std::ostream &o, Point const &p);

#endif
