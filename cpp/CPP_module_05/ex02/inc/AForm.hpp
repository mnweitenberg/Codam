#ifndef AFORM_HPP
# define AFORM_HPP

# include "../inc/Bureaucrat.hpp"
# include <sstream> 

class Bureaucrat;

class AForm
{
	public:
		AForm(const std::string name, int gradeSign, int gradeExecution);
		AForm(const AForm &src);
		virtual ~AForm(void);
		AForm &operator = (const AForm &src);

		const std::string	getName(void) const;
		bool 				getSigned(void) const;
		int 				getGradeSign(void) const;
		int 				getGradeExecution(void) const;
		void				beSigned(const Bureaucrat &bureaucrat);
		virtual void		execute(const Bureaucrat &excutor) const = 0;
		void				executeCheck(const Bureaucrat &bureaucrat) const;

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
		class ExecuteNotSigned : public std::exception {
			public:
				virtual const char *what() const throw() {
					return ("Form is not signed");
				}
		};

	private:
		const std::string	_name;
		bool				_signed;
		const int			_gradeSign;
		const int			_gradeExecution;
};

std::ostream &operator << (std::ostream &o, AForm const &f);

#endif