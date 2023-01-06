#ifndef ShrubberyCreationForm_HPP
# define ShrubberyCreationForm_HPP

# include "../inc/AForm.hpp"
# include <sstream> 

# define SIGN_SCF 145
# define EXEC_SCF 137

class ShrubberyCreationForm : public AForm
{
	public:
		ShrubberyCreationForm(const std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm &src);
		virtual ~ShrubberyCreationForm(void);
		ShrubberyCreationForm &operator = (const ShrubberyCreationForm &src);

		void	execute(const Bureaucrat &b) const;
		std::string	get_target() const;

	private:
		const std::string	_target;
};

#endif