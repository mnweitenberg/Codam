#include "../inc/main.hpp"
#include "../inc/Bureaucrat.hpp"
#include "../inc/AForm.hpp"
#include "../inc/ShrubberyCreationForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/PresidentialPardonForm.hpp"
#include "../inc/Intern.hpp"
#include <iostream>
#include <cstdlib>

#define GREEN	"\e[32m"
#define BLUE	"\e[0;34m"
#define NORMAL	"\e[00m"

Intern g_globalIntern;

void testBureaucrats(void) {
	std::cout << BLUE <<"\nBUREACRATS" << NORMAL << std::endl;
	
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

void testShrubbery(void) {
	std::cout << BLUE <<"\nSHRUBBERY" << NORMAL << std::endl;

	// testing getters and overload operator
	std::cout << GREEN <<"Shrubbery Testing getters and overload operator" << NORMAL << std::endl;
	AForm *Shrubbery = g_globalIntern.makeForm("shrubbery creation", "Garden");
	std::cout << *Shrubbery << std::endl;

	// testing signing
	std::cout << GREEN <<"\nShrubbery Testing signing" << NORMAL << std::endl;
	Bureaucrat b0 = Bureaucrat("b0", 150);
	b0.signForm(*Shrubbery);
	Bureaucrat b1 = Bureaucrat("b1", 1);
	b1.signForm(*Shrubbery);
	std::cout << *Shrubbery << std::endl;
	b1.signForm(*Shrubbery);

	std::cout << GREEN <<"\nShrubbery signing error" << NORMAL << std::endl;
	try {
		Bureaucrat b2 = Bureaucrat("b1", 150);
		(*Shrubbery).beSigned(b2);
	}
	catch (const std::exception &error) {
		std::cerr << error.what() << std::endl;
	}

	// testing executing
	std::cout << GREEN <<"\nShrubbery Testing executing" << NORMAL << std::endl;
	b0.executeForm(*Shrubbery);
	b1.executeForm(*Shrubbery);

	std::cout << GREEN <<"\nShrubbery executing error" << NORMAL << std::endl;
	try {
		Bureaucrat b2 = Bureaucrat("b1", 140);
		(*Shrubbery).execute(b2);
	}
	catch (const std::exception &error) {
		std::cerr << error.what() << std::endl;
	}

	delete Shrubbery;
}

void testRobotomy(void) {
	std::cout << BLUE <<"\nROBOTOMY" << NORMAL << std::endl;

	// testing getters and overload operator
	std::cout << GREEN <<"Robotomy Testing getters and overload operator" << NORMAL << std::endl;
	AForm *Robotomy = g_globalIntern.makeForm("robotomy request", "Garden");

	std::cout << *Robotomy << std::endl;

	// testing signing
	std::cout << GREEN <<"\nRobotomy Testing signing" << NORMAL << std::endl;
	Bureaucrat b0 = Bureaucrat("b0", 150);
	b0.signForm(*Robotomy);
	Bureaucrat b1 = Bureaucrat("b1", 45);
	b1.signForm(*Robotomy);
	std::cout << *Robotomy << std::endl;
	b1.signForm(*Robotomy);

	std::cout << GREEN <<"\nRobotomy signing error" << NORMAL << std::endl;
	try {
		Bureaucrat b2 = Bureaucrat("b1", 73);
		(*Robotomy).beSigned(b2);
	}
	catch (const std::exception &error) {
		std::cerr << error.what() << std::endl;
	}

	// testing executing
	std::cout << GREEN <<"\nRobotomy Testing executing" << NORMAL << std::endl;
	b0.executeForm(*Robotomy);
	b1.executeForm(*Robotomy);
	b1.executeForm(*Robotomy);
	b1.executeForm(*Robotomy);

	std::cout << GREEN <<"\nRobotomy executing error" << NORMAL << std::endl;
	try {
		Bureaucrat b2 = Bureaucrat("b1", 46);
		(*Robotomy).execute(b2);
	}
	catch (const std::exception &error) {
		std::cerr << error.what() << std::endl;
	}

	delete Robotomy;
}

void testPresidentialPardon(void) {
	std::cout << BLUE <<"\nPRESIDENTIAL" << NORMAL << std::endl;

	// testing getters and overload operator
	std::cout << GREEN <<"PresidentialPardon Testing getters and overload operator" << NORMAL << std::endl;
	AForm *RobotMarvin = g_globalIntern.makeForm("presidential pardon", "Marvin the Robot");

	std::cout << *RobotMarvin << std::endl;

	// testing signing
	std::cout << GREEN <<"\nPresidentialPardon Testing signing" << NORMAL << std::endl;
	Bureaucrat b0 = Bureaucrat("Arthur Dent", 150);
	b0.signForm(*RobotMarvin);
	Bureaucrat ZaphodBeeblebrox = Bureaucrat("Zaphod Beeblebrox", 1);
	ZaphodBeeblebrox.signForm(*RobotMarvin);
	std::cout << *RobotMarvin << std::endl;
	ZaphodBeeblebrox.signForm(*RobotMarvin);

	std::cout << GREEN <<"\nPresidentialPardon signing error" << NORMAL << std::endl;
	try {
		Bureaucrat b2 = Bureaucrat("b1", 73);
		(*RobotMarvin).beSigned(b2);
	}
	catch (const std::exception &error) {
		std::cerr << error.what() << std::endl;
	}

	// testing executing
	std::cout << GREEN <<"\nPresidentialPardon Testing executing" << NORMAL << std::endl;
	b0.executeForm(*RobotMarvin);
	ZaphodBeeblebrox.executeForm(*RobotMarvin);
	AForm *BadGuys = g_globalIntern.makeForm("presidential pardon", "Some super duper bad guys");
	ZaphodBeeblebrox.executeForm(*BadGuys);

	std::cout << GREEN <<"\nPresidentialPardon executing error" << NORMAL << std::endl;
	try {
		Bureaucrat b2 = Bureaucrat("b1", 46);
		(*BadGuys).execute(b0);
	}
	catch (const std::exception &error) {
		std::cerr << error.what() << std::endl;
	}

	delete RobotMarvin;
	delete BadGuys;
}

void testIntern() {
	std::cout << BLUE <<"\nINTERN" << NORMAL << std::endl;
	std::cout << GREEN <<"Intern creation " << NORMAL << std::endl;
	Intern someRandomIntern;
	AForm* rrf;
	rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	std::cout << *rrf << std::endl;

	std::cout << GREEN <<"\nIntern creation error" << NORMAL << std::endl;
	try {
		Intern someRandomIntern2;
		AForm* non_existing_form;
		non_existing_form = someRandomIntern2.makeForm("non_existing form request", "Bender");
		std::cout << *non_existing_form << std::endl;
	}
	catch (const std::exception &error) {
		std::cerr << error.what() << std::endl;
	}

	delete rrf;
}

int main(void) {
	srand(time(NULL));
	testBureaucrats();
	testShrubbery();
	testRobotomy();
	testPresidentialPardon();
	testIntern();

	return (0);
}
