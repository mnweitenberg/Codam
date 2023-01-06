#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <sstream> 

# define GRADE_HIGHEST 1
# define GRADE_LOWEST 150

class Bureaucrat
{
	public:
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat &src);
		virtual ~Bureaucrat(void);
		Bureaucrat &operator = (const Bureaucrat &src);

		std::string	getName(void) const;
		int 		getGrade(void) const;
		void		incrementGrade(void);
		void		decrementGrade(void);

		//exceptions
		class GradeTooHighException: public std::exception {
			public:
				virtual const char *what() const throw() {
					return ("Exception: Grade is too damn high!");
				}
		};
		class GradeTooLowException : public std::exception {
			public:
				virtual const char *what() const throw() {
					return ("Exception: Grade is too damn low!");
				}
		};

	private:
		void 				setGrade(int grade);
		const std::string	_name;
		int					_grade;
};

std::ostream &operator << (std::ostream &o, Bureaucrat const &b);

#endif