# include "../inc/Form.hpp"
# include <iostream> 

// constructors/destructor
Form::Form(const std::string name, int gradeSign, int gradeExecution): _name(name), _signed(false), _gradeSign(gradeSign), _gradeExecution(gradeExecution) {
	if(_gradeSign < GRADE_HIGHEST || _gradeExecution < GRADE_HIGHEST)
		throw GradeTooHighException();
	if(_gradeSign > GRADE_LOWEST || _gradeExecution > GRADE_LOWEST)
		throw GradeTooLowException();
}

Form::Form(const Form &src): _name(src._name), _gradeSign(src._gradeSign), _gradeExecution(src._gradeExecution) { *this = src; }
Form::~Form() { }

// overloaded operators
Form &Form::operator = (const Form &src) {
	if (this != &src) {
		this->_signed = src._signed;
	}
	return (*this);
}

// getter/setter
const std::string	Form::getName(void) const { return (this->_name); }
bool 				Form::getSigned(void) const { return (this->_signed); }
int 				Form::getGradeSign(void) const { return (this->_gradeSign); }
int 				Form::getGradeExecution(void) const { return (this->_gradeExecution); }

// public functions
void	Form::beSigned(Bureaucrat &b) {
	if (b.getGrade() > this->_gradeSign)
		throw GradeTooLowException();
	this->_signed = true;
	std::cout << b.getName() << " signed " << _name << std::endl;
}

// ostream overload
std::ostream &operator << (std::ostream &o, Form const &b) {
	o 	<< "Form name: " << b.getName()
		<< ", Form signed " << b.getSigned()
		<< ", minimal grade needed to signing " << b.getGradeSign()
		<< ", minimal grade needed to execute " << b.getGradeExecution();
	return (o);
}