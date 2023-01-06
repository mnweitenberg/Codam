# include "../inc/PresidentialPardonForm.hpp"
# include <iostream>
# include <cstdlib>

// constructors/destructor
PresidentialPardonForm::PresidentialPardonForm(const std::string target)
	: AForm("PresidentialPardonForm", SIGN_PPM, EXEC_PPM), _target(target) { }
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src)
	: AForm("PresidentialPardonForm", SIGN_PPM, EXEC_PPM) { *this = src; }
PresidentialPardonForm::~PresidentialPardonForm() { }

// overloaded operators
PresidentialPardonForm &PresidentialPardonForm::operator = (const PresidentialPardonForm &src) { (void)src; return (*this); }

// public functions
void	PresidentialPardonForm::execute(const Bureaucrat &bureaucrat) const {
	this->executeCheck(bureaucrat);
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}