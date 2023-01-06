#include <cmath>
#include "../inc/Fixed.hpp"

Fixed::Fixed(void) : _fixedPointNumber(0) { }
Fixed::Fixed(const int integer) : _fixedPointNumber(integer << _fractionalBits) { }
Fixed::Fixed(const float floatingPoint) : _fixedPointNumber((int)roundf(floatingPoint * (1 << _fractionalBits))) { }
Fixed::Fixed(const Fixed &f) { *this = f; }
Fixed::~Fixed() { }

Fixed &	Fixed::operator = (const Fixed &f) {
	if (this != &f)
		_fixedPointNumber = f.getRawBits();
	return (*this);
}

int		Fixed::getRawBits(void) const { return (_fixedPointNumber); }
void	Fixed::setRawBits(int   const raw) { _fixedPointNumber = raw; }

float	Fixed::toFloat( void )  const { return ((float)_fixedPointNumber / (1 << _fractionalBits)); }
int		Fixed::toInt( void )    const { return (_fixedPointNumber >> _fractionalBits); }

// COMPARISON OPERATORS
bool Fixed::operator <  (const Fixed &f) const { return (this->_fixedPointNumber < f._fixedPointNumber); }
bool Fixed::operator >  (const Fixed &f) const { return (this->_fixedPointNumber > f._fixedPointNumber); }
bool Fixed::operator <= (const Fixed &f) const { return (this->_fixedPointNumber <= f._fixedPointNumber); }
bool Fixed::operator >= (const Fixed &f) const { return (this->_fixedPointNumber >= f._fixedPointNumber); }
bool Fixed::operator == (const Fixed &f) const { return (this->_fixedPointNumber == f._fixedPointNumber); }
bool Fixed::operator != (const Fixed &f) const { return (this->_fixedPointNumber != f._fixedPointNumber); }

// ARITHMETIC OPERATORS
Fixed Fixed::operator +	(const Fixed &f) const { return (Fixed(this->toFloat() + f.toFloat())); }
Fixed Fixed::operator -	(const Fixed &f) const { return (Fixed(this->toFloat() - f.toFloat())); }
Fixed Fixed::operator *	(const Fixed &f) const { return (Fixed(this->toFloat() * f.toFloat())); }
Fixed Fixed::operator / (const Fixed &f) const { return (Fixed(this->toFloat() / f.toFloat())); }

Fixed &Fixed::operator ++ (void) {
	++(this->_fixedPointNumber);
	return (*this);
}

Fixed Fixed::operator ++ (int) {
	Fixed	temp(*this);
	++(*this);
	return (temp);
}

Fixed &Fixed::operator --(void) {
	--(this->_fixedPointNumber);
	return (*this);
}

Fixed Fixed::operator -- (int) {
	Fixed	temp(*this);
	--(*this);
	return (temp);
}

std::ostream &	operator << ( std::ostream &o, Fixed const &i) {
	o << i.toFloat();
	return (o);
}

Fixed &Fixed::min(Fixed &a, Fixed &b) { return (a > b ? b : a); }
Fixed &Fixed::min(Fixed const & a, Fixed const &b) { return (Fixed::min((Fixed &)a, (Fixed &)b)); }
Fixed &Fixed::max(Fixed &a, Fixed &b) { return (a < b ? b : a); }
Fixed &Fixed::max(Fixed const &a, Fixed const &b) { return (Fixed::max((Fixed &)a, (Fixed &)b)); }