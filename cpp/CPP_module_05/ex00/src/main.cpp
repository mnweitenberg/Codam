#include "../inc/main.hpp"
#include "../inc/Bureaucrat.hpp"
#include <iostream>
#include <cstdlib>

#define GREEN "\e[32m"
#define NORMAL "\e[00m"

int main(void) {
	// testing getters and overload operator
	std::cout << GREEN <<"Testing getters and overload operator" << NORMAL << std::endl;
	Bureaucrat b1 = Bureaucrat("b1", 1);
	std::cout << b1.getName() << ": bureaucrat grade " << b1.getGrade() << "." << std::endl;
	std::cout << b1 << std::endl;

	// testing increase decrease
	std::cout << GREEN <<"\nTesting incrementGrade() decrementGrade()" << NORMAL << std::endl;
	Bureaucrat b2 = Bureaucrat("b2", 1);
	std::cout << "Expected =  1 | Result = " << b2.getGrade() << std::endl;
	b2.decrementGrade();
	std::cout << "Expected =  2 | Result = " << b2.getGrade() << std::endl;
	b2.decrementGrade();
	std::cout << "Expected =  3 | Result = " << b2.getGrade() << std::endl;
	b2.incrementGrade();
	std::cout << "Expected =  2 | Result = " << b2.getGrade() << std::endl;
	b2.incrementGrade();
	std::cout << "Expected =  1 | Result = " << b2.getGrade() << std::endl;
	try {
		b2.incrementGrade();
	}
	catch (const std::exception &error) {
		std::cerr << error.what() << std::endl;
	}

	Bureaucrat b3 = Bureaucrat("b3", 148);
	std::cout << "Expected = 148 | Result = " << b3.getGrade() << std::endl;
	b3.decrementGrade();
	std::cout << "Expected = 149 | Result = " << b3.getGrade() << std::endl;
	b3.decrementGrade();
	std::cout << "Expected = 150 | Result = " << b3.getGrade() << std::endl;
	try {
		b3.decrementGrade();
	}
	catch (const std::exception &error) {
		std::cerr << error.what() << std::endl;
	}

	// testing constructing error
	std::cout << GREEN <<"\nTesting constructing error" << NORMAL << std::endl;
	try {
		Bureaucrat b4 = Bureaucrat("b4", -1);
	}
	catch (const std::exception &error) {
		std::cerr << error.what() << std::endl;
	}

	try {
		Bureaucrat b4 = Bureaucrat("b4", 0);
	}
	catch (const std::exception &error) {
		std::cerr << error.what() << std::endl;
	}

	try {
		Bureaucrat b4 = Bureaucrat("b4", 151);
	}
	catch (const std::exception &error) {
		std::cerr << error.what() << std::endl;
	}
	return (0);
}
