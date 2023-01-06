#include "../inc/Intern.hpp"
#include "../inc/ShrubberyCreationForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/PresidentialPardonForm.hpp"
#include <iostream> 

// constructors/destructor
Intern::Intern(void) {  }
Intern::Intern(const Intern &src) { *this = src; }
Intern::~Intern() { }

// overloaded operators
Intern &Intern::operator = (const Intern &src) { (void)src; return (*this); }

// public functions
static AForm *shrubberyForm(const std::string target) {
	return (new ShrubberyCreationForm(target));
}

static AForm *robotomyForm(const std::string target) {
	return (new RobotomyRequestForm(target));
}

static AForm *presidentialForm(const std::string target) {
	return (new PresidentialPardonForm(target));
}

AForm	*Intern::makeForm(std::string formName, std::string formTarget) const {
	s_form definitions[3] = {
		{ "shrubbery creation", 	&shrubberyForm },
		{ "robotomy request", 		&robotomyForm },
		{ "presidential pardon",	&presidentialForm }
	};
	size_t i = 0;
	while (i < 3) {
		if (definitions[i].name == formName) {
			AForm* form = (definitions[i].type)(formTarget);
			std::cout << "Intern creates " << formName << std::endl;
			return (form);
		}
		i++;
	}
	if (i >= 3)
		throw FormDoesntExit();
	return (NULL);
}
