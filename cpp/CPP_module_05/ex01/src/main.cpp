#include "../inc/main.hpp"
#include "../inc/Bureaucrat.hpp"
#include <iostream>
#include <cstdlib>

#define GREEN "\e[32m"
#define NORMAL "\e[00m"

static void testBureaucrats(void) {
	// testing getters and overload operator
	std::cout << GREEN <<"BUREACRATS Testing getters and overload operator" << NORMAL << std::endl;
	Bureaucrat b1 = Bureaucrat("b1", 1);
	std::cout << b1.getName() << ": bureaucrat grade " << b1.getGrade() << "." << std::endl;
	std::cout << b1 << std::endl;

	// testing increase decrease
	std::cout << GREEN <<"\nBUREACRATS Testing incrementGrade() decrementGrade()" << NORMAL << std::endl;
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
	std::cout << GREEN <<"\nBUREACRATS Testing constructing error" << NORMAL << std::endl;
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
}

int main(void) {
	testBureaucrats();
	// testing getters and overload operator
	std::cout << GREEN <<"FORM Testing getters and overload operator" << NORMAL << std::endl;
	Form f1 = Form("f1", 10, 100);
	std::cout << f1 << std::endl;

	// testing signing
	std::cout << GREEN <<"\nFORM Testing signing" << NORMAL << std::endl;
	Bureaucrat b0 = Bureaucrat("b0", 150);
	b0.signForm(f1);
	Bureaucrat b1 = Bureaucrat("b1", 1);
	b1.signForm(f1);
	std::cout << f1 << std::endl;
	b1.signForm(f1);

	std::cout << GREEN <<"\nFORM signing error" << NORMAL << std::endl;
	try {
		Bureaucrat b2 = Bureaucrat("b1", 150);
		f1.beSigned(b2);
	}
	catch (const std::exception &error) {
		std::cerr << error.what() << std::endl;
	}

	return (0);
}
