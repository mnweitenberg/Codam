#include <cmath>
#include "../inc/Fixed.hpp"

/*
Fixed point representation in case of 8 fractional bits:
SIIIIIIIFFFFFFFF
S = sign			1 is negative, 0 is positive
I = integral part	
F = fractional part	

Examples
-	4.5 is 100.1 in binary
	S IIIIIII FFFFFFFF
	0 0000100 10000000
-	6.25 is 110.01 in binary
	S IIIIIII FFFFFFFF
	0 0000110 01000000

Advantages of fixed point representation:
- flexibility in precision, range and data size
- some operations are faster
- it's easier to cast integers to fixed point

Disadventages
- precision and range are usually less than floating point
*/
Fixed::Fixed(void) : _fixedPointNumber(0) { 
	std::cout << "Default constructor called" << std::endl;
}

/*
For example: 
-	integer 42 == 101010 in binary
	left shift by 8 bits is: 
	0 0101010 00000000
	S IIIIIII FFFFFFFF
*/
Fixed::Fixed(const int integer) {
	std::cout << "Int constructor called" << std::endl;
	_fixedPointNumber = integer << _fractionalBits;
}

/*
To convert from float to fixed-point:
-	Calculate x = floating_input * 2^(fractional_bits)
	2^(fractional_bits) == 1 << fractional_bits
-	Round x to the nearest whole number
-	Store the rounded x in an integer container

For example: 
-	integer 42.42 is 101010.011011 in binary
	x = 42.42 * 2^8
	  = 42.42 * 256
	  = 10859.5
	round(10859.5) = 10860
	10860 to binary is 0010101001101100 
	S IIIIIII FFFFFFFF
	0 0101010 01101100
-	integer 6.25 is 110.01 in binary
	x = 6.25 * 2^8
	  = 6.25 * 256
	  = 1600
	round(1600) = 1600
	1600 to binary is 0000011001000000 
	S IIIIIII FFFFFFFF
	0 0000110 01000000
*/
Fixed::Fixed(const float floatingPoint) {
	std::cout << "Float constructor called" << std::endl;
	_fixedPointNumber = (int)roundf(floatingPoint * (1 << _fractionalBits));
}

Fixed::Fixed(const Fixed &f) {
	std::cout << "Copy constructor called" << std::endl;
	*this = f;
}

Fixed::~Fixed() { std::cout << "Destructor called" << std::endl; }

Fixed &	Fixed::operator = (const Fixed &f) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &f)
		_fixedPointNumber = f.getRawBits();
	return (*this);
}

int		Fixed::getRawBits(void) const { return (_fixedPointNumber); }

void	Fixed::setRawBits(int const raw) { _fixedPointNumber = raw; }

float	Fixed::toFloat( void ) const {
	return ((float)_fixedPointNumber / (1 << _fractionalBits));
}

int		Fixed::toInt( void ) const {
	return (_fixedPointNumber >> _fractionalBits);
}

std::ostream &operator << (std::ostream &o, Fixed const &f) {
	o << f.toFloat();
	return (o);
}
