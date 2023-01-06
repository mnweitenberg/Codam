#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "../inc/AForm.hpp"
# include <sstream> 

# define SIGN_PPM 25
# define EXEC_PPM 5

class PresidentialPardonForm : public AForm
{
	public:
		PresidentialPardonForm(const std::string target);
		PresidentialPardonForm(const PresidentialPardonForm &src);
		virtual ~PresidentialPardonForm(void);
		PresidentialPardonForm &operator = (const PresidentialPardonForm &src);

		void	execute(const Bureaucrat &b) const;

	private:
		const std::string	_target;
};

#endif