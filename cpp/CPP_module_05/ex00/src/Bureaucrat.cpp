# include "../inc/Bureaucrat.hpp"
# include <iostream> 

// constructors/destructor
Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name) { setGrade(grade); }
Bureaucrat::Bureaucrat(const Bureaucrat &src) { *this = src; }
Bureaucrat::~Bureaucrat() { }

// overloaded operators
Bureaucrat &Bureaucrat::operator = (const Bureaucrat &src) {
	if (this != &src) {
		this->_grade = src._grade;
	}
	return (*this);
}

// getter/setter
std::string	Bureaucrat::getName(void) const { return (this->_name); }
int 		Bureaucrat::getGrade(void) const { return (this->_grade); }

// public functions
void		Bureaucrat::incrementGrade(void) { setGrade(this->_grade - 1); }
void		Bureaucrat::decrementGrade(void) { setGrade(this->_grade + 1); }

// private functions
void	Bureaucrat::setGrade(int grade) {
	if (grade < GRADE_HIGHEST)
		throw GradeTooHighException();
	if (grade > GRADE_LOWEST)
		throw GradeTooLowException();
	this->_grade = grade;
}

// ostream overload
std::ostream &operator << (std::ostream &o, Bureaucrat const &b) {
	o << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
	return (o);
}