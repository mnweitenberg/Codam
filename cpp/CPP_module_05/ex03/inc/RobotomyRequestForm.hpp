#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "../inc/AForm.hpp"
# include <sstream> 

# define SIGN_RRF 72
# define EXEC_RRF 45

class RobotomyRequestForm : public AForm
{
	public:
		RobotomyRequestForm(const std::string target);
		RobotomyRequestForm(const RobotomyRequestForm &src);
		virtual ~RobotomyRequestForm(void);
		RobotomyRequestForm &operator = (const RobotomyRequestForm &src);

		void	execute(const Bureaucrat &b) const;

	private:
		const std::string	_target;
};

#endif