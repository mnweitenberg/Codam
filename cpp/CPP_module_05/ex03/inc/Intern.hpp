#ifndef INTERN_HPP
# define INTERN_HPP

# include "../inc/AForm.hpp"
# include <sstream> 

class AForm;

class Intern
{
	public:
		Intern(void);
		Intern(const Intern &src);
		virtual ~Intern(void);
		Intern &operator = (const Intern &src);

		AForm	*makeForm(std::string formName, std::string formTarget) const;

		//exceptions
		class FormDoesntExit: public std::exception {
			public:
				virtual const char *what() const throw() {
					return ("Intern::Exception: Form does not exist!");
				}
		};
};

struct s_form {
	std::string	name;
	AForm*		(*type)(std::string target);
};


#endif