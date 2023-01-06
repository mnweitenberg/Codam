# include "../inc/AForm.hpp"
# include <iostream> 

// constructors/destructor
AForm::AForm(const std::string name, int gradeSign, int gradeExecution): _name(name), _signed(false), _gradeSign(gradeSign), _gradeExecution(gradeExecution) {
	if(_gradeSign < GRADE_HIGHEST || _gradeExecution < GRADE_HIGHEST)
		throw GradeTooHighException();
	if(_gradeSign > GRADE_LOWEST || _gradeExecution > GRADE_LOWEST)
		throw GradeTooLowException();
}

AForm::AForm(const AForm &src): _name(src._name), _gradeSign(src._gradeSign), _gradeExecution(src._gradeExecution) { *this = src; }
AForm::~AForm() { }

// overloaded operators
AForm &AForm::operator = (const AForm &src) {
	if (this != &src) {
		this->_signed = src._signed;
	}
	return (*this);
}

// getter/setter
const std::string	AForm::getName(void) const { return (this->_name); }
bool 				AForm::getSigned(void) const { return (this->_signed); }
int 				AForm::getGradeSign(void) const { return (this->_gradeSign); }
int 				AForm::getGradeExecution(void) const { return (this->_gradeExecution); }

// public functions
void	AForm::beSigned(const Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() > this->_gradeSign)
		throw GradeTooLowException();
	this->_signed = true;
	std::cout << bureaucrat.getName() << " signed " << _name << std::endl;
}

void AForm::executeCheck(const Bureaucrat &bureaucrat) const
{
	if (!this->getSigned())
		throw AForm::ExecuteNotSigned();
	if (this->getGradeExecution() < bureaucrat.getGrade())
		throw AForm::GradeTooLowException();
}
// ostream overload
std::ostream &operator << (std::ostream &o, AForm const &b) {
	o 	<< "Form name: " << b.getName()
		<< ", Form signed " << b.getSigned()
		<< ", minimal grade needed to signing " << b.getGradeSign()
		<< ", minimal grade needed to execute " << b.getGradeExecution();
	return (o);
}