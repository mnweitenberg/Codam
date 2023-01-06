# include "../inc/RobotomyRequestForm.hpp"
# include <iostream>
# include <cstdlib>

// constructors/destructor
RobotomyRequestForm::RobotomyRequestForm(const std::string target)
	: AForm("RobotomyRequestForm", SIGN_RRF, EXEC_RRF), _target(target) { }
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src)
	: AForm("RobotomyRequestForm", SIGN_RRF, EXEC_RRF) { *this = src; }
RobotomyRequestForm::~RobotomyRequestForm() { }

// overloaded operators
RobotomyRequestForm &RobotomyRequestForm::operator = (const RobotomyRequestForm &src) { (void)src; return (*this); }

// public functions
void	RobotomyRequestForm::execute(const Bureaucrat &bureaucrat) const {
	this->executeCheck(bureaucrat);
	std::cout << "* DRILLL DRILLLLL DRILLLLLLLL*" << std::endl;
	if (rand() % 2)
		std::cout << _target << " has been succesfully robotomized" << std::endl;
	else
		std::cout << _target << " robotomy failed..." << std::endl;
}