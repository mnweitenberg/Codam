# include "../inc/Fixed.hpp"

/*
Orthodox canonical class form:
-	Default constructor
-	Copy constructor
-	Destructor
-	Copy assignment operator
*/
Fixed::Fixed() : _fixedPointNumber(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &f) {
	std::cout << "Copy constructor called" << std::endl;
	*this = f;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

// https://www.geeksforgeeks.org/copy-constructor-vs-assignment-operator-in-c/
Fixed &	Fixed::operator = (const Fixed &f) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &f)
		_fixedPointNumber = f.getRawBits();
	return (*this);
}

int		Fixed::getRawBits(void) const{
	std::cout << "getRawBits member function called" << std::endl;
	return (_fixedPointNumber);
}

void	Fixed::setRawBits(int const raw) {
	std::cout << "setRawBits member function called" << std::endl;
	_fixedPointNumber = raw;
}
