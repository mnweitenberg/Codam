#include "../inc/main.hpp"
#include "../inc/Fixed.hpp"
#include <iostream>

#define GREEN	"\e[32m"
#define BLUE	"\e[0;34m"
#define NORMAL	"\e[00m"

static std::string	boolToString(bool boolean)
{
	if (boolean)
		return ("true");
	return ("false");
}

void testComparison(Fixed a, Fixed b)
{
	std::cout << a << " >  " << b << " == "	<< boolToString (a > b)	 << std::endl;
	std::cout << a << " <  " << b << " == "	<< boolToString (a < b)	 << std::endl;
	std::cout << a << " >= " << b << " == "	<< boolToString (a >= b) << std::endl;
	std::cout << a << " <= " << b << " == "	<< boolToString (a <= b) << std::endl;
	std::cout << a << " == " << b << " == "	<< boolToString (a == b) << std::endl;
	std::cout << a << " != " << b << " == "	<< boolToString (a != b) << std::endl;
	std::cout << std::endl;
}

void testArithmetic(Fixed a, Fixed b)
{
	std::cout << a << " + " << b << " == " << a + b << std::endl;
	std::cout << a << " - " << b << " == " << a - b << std::endl;
	std::cout << a << " * " << b << " == " << a * b << std::endl;
	std::cout << a << " / " << b << " == " << a / b << std::endl;
	std::cout << std::endl;
}

void testIncrement(Fixed a)
{
	std::cout << "a   = " << a << std::endl;
	std::cout << "++a = " << ++a << std::endl;
	std::cout << "a   = " << a << std::endl;
	std::cout << "a++ = " << a++ << std::endl;
	std::cout << "a   = " << a << std::endl;
	std::cout << std::endl;
}

void testDencrement(Fixed a)
{
	std::cout << "a   = " << a << std::endl;
	std::cout << "--a = " << --a << std::endl;
	std::cout << "a   = " << a << std::endl;
	std::cout << "a-- = " << a-- << std::endl;
	std::cout << "a   = " << a << std::endl;
	std::cout << std::endl;
}

void testMinMax(Fixed a, Fixed b) {
	std::cout << "min(" << a << ", " << b << ") == " << Fixed::min(a, b) << std::endl;
	std::cout << "max(" << a << ", " << b << ") == " << Fixed::max(a, b) << std::endl;
	std::cout << std::endl;
}

int main( void ) {
	// COMPARISON OPERATORS
	std::cout << BLUE << "COMPARISON OPERATORS" << NORMAL << std::endl;
	testComparison(0.95f, 1);
	testComparison(1, 0.95f);
	testComparison(1, 1);
	testComparison(0, 0);

	// ARITHMETIC OPERATORS
	std::cout << BLUE << "\nARITHMETIC OPERATORS" << NORMAL << std::endl;
	testArithmetic(0.95f, 1);
	testArithmetic(1, 0.95f);
	testArithmetic(1, 1);
	testArithmetic(2, 2);

	// INCREMENT/DECREMENT OPERATORS
	std::cout << BLUE << "\nINCREMENT/DECREMENT OPERATORS" << NORMAL << std::endl;
	testIncrement(-1);
	testIncrement(0);
	testIncrement(1);
	testDencrement(-1);
	testDencrement(0);
	testDencrement(1);

	// MIN MAX
	std::cout << BLUE << "\nMIN MAX"<< NORMAL  << std::endl;
	Fixed	a(0.95f);
	Fixed	b(1);
	Fixed	const c(Fixed(5.05f));
	testMinMax(a, b);
	testMinMax(b, a);
	testMinMax(b, c);
	testMinMax(0, 0);
	return 0;
}

// // main subject:
// #include <iostream>
// int main( void ) {
// 	Fixed a;
// 	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
// 	std::cout << a << std::endl;
// 	std::cout << ++a << std::endl;
// 	std::cout << a << std::endl;
// 	std::cout << a++ << std::endl;
// 	std::cout << a << std::endl;
// 	std::cout << b << std::endl;
// 	std::cout << Fixed::max( a, b ) << std::endl;
// 	return 0;
// }
