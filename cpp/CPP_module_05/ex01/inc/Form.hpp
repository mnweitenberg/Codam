#ifndef FORM_HPP
# define FORM_HPP

# include "../inc/Bureaucrat.hpp"
# include <sstream> 

class Bureaucrat;

class Form
{
	public:
		Form(const std::string name, int gradeSign, int gradeExecution);
		Form(const Form &src);
		virtual ~Form(void);
		Form &operator = (const Form &src);

		const std::string	getName(void) const;
		bool 				getSigned(void) const;
		int 				getGradeSign(void) const;
		int 				getGradeExecution(void) const;
		void				beSigned(Bureaucrat &b);

		//exceptions
		class GradeTooHighException: public std::exception {
			public:
				virtual const char *what() const throw() {
					return ("Form::Exception: Grade is too damn high!");
				}
		};
		class GradeTooLowException : public std::exception {
			public:
				virtual const char *what() const throw() {
					return ("Form::Exception: Grade is too damn low!");
				}
		};

	private:
		const std::string	_name;
		bool				_signed;
		const int			_gradeSign;
		const int			_gradeExecution;
};

std::ostream &operator << (std::ostream &o, Form const &f);

#endif