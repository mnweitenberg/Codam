#include "../inc/whatever.hpp"
#include <iostream>
#include <sstream> 
#include <string>

#define GREEN "\e[32m"
#define NORMAL "\e[00m"

template<typename T>
void	tests(T a, T b) {
	std::cout << "pre-swap  = " << a << " | " << b << std::endl;
	::swap( a, b );
	std::cout << "post-swap = " << a << " | " << b << std::endl;
	std::cout << "min(" << a << ", " << b << ") = " << ::min( a, b ) << std::endl;
	std::cout << "max(" << a << ", " << b << ") = " << ::max( a, b ) << std::endl;
	std::cout << std::endl;
}

int main(void) {
	std::cout << GREEN << "INTS " << NORMAL << std::endl;
	tests(1, 2);

	std::cout << GREEN << "CHARS " << NORMAL << std::endl;
	tests('a', 'z');

	std::cout << GREEN << "STRINGS " << NORMAL << std::endl;
	tests("string1", "string2");
	tests("haha", "blah");

	std::cout << GREEN << "DOUBLES " << NORMAL << std::endl;
	tests(4.200000000, 4.200000000);
	tests(4.19, 4.20);
	return (0);
}
