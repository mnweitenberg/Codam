#include "../inc/Convert.hpp"
#include <iostream> 
#include <string>
#include <sstream>
#include <cctype>
#include <climits>
#include <float.h>

static void	printChar(const long n) {
	if (n > 127)
		std::cout << "char\t: impossible" << std::endl;
	else if (std::isprint(n))
		std::cout << "char\t: " << (char)n << std::endl;
	else
		std::cout << "char\t: non displayable" << std::endl;
}

static void	printInt(const long n) {
	if (n != int(n))
		std::cout << "int\t: impossible" << std::endl;
	else
		std::cout << "int\t: " << n << std::endl;
}

static void	printFloat(double num) {
	if (num < -FLT_MAX || num > FLT_MAX)
		std::cout << "float\t: impossible" << std::endl;
	else
		std::cout << "float\t: " << (float)num << "f"  << std::endl;
}

// constructors
Convert::Convert(std::string str) {
	std::cout << "char\t: impossible"<< std::endl;
	std::cout << "int\t: impossible" << std::endl;
	if (str.find("nan") != std::string::npos) {
		std::cout << "float\t: nanf" 	 << std::endl;
		std::cout << "double\t: nan" 	 << std::endl;
	}
	else if (str.find("+inf") != std::string::npos) {
		std::cout << "float\t: +inff" 	 << std::endl;
		std::cout << "double\t: +inf" 	 << std::endl;
	}
	else if (str.find("-inf") != std::string::npos) {
		std::cout << "float\t: -inff" 	 << std::endl;
		std::cout << "double\t: -inf" 	 << std::endl;
	}
}
Convert::Convert(char c) {
	std::cout << "char\t: "		<< c << std::endl;
	std::cout << "int\t: "		<< static_cast<int>(c)    << std::endl;
	std::cout << "float\t: "	<< static_cast<float>(c)  << ".0f" << std::endl;
	std::cout << "double\t: "	<< static_cast<double>(c) << ".0" << std::endl;
}
Convert::Convert(int n) {
	printChar(n);
	std::cout << "int\t: "		<< n << std::endl;
	std::cout << "float\t: "	<< static_cast<float>(n)  << ".0f" << std::endl;
	std::cout << "double\t: "	<< static_cast<double>(n) << ".0" << std::endl;
}
Convert::Convert(float f) {
	printChar(f);
	printInt(f);
	std::cout << "float\t: "	<< f << "f" << std::endl;
	std::cout << "double\t: "	<< static_cast<double>(f) << std::endl;
}
Convert::Convert(double d) {
	printChar(d);
	printInt(d);
	printFloat(d);
	std::cout << "double\t: "	<< d << std::endl;
}
Convert::Convert(const Convert &src) { *this = src; }

// destructor
Convert::~Convert() { }

// overloaded operators
Convert &Convert::operator = (const Convert &src) { (void)src; return (*this); }
