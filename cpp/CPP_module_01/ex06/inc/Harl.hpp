#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>
# include <sstream>

class Harl
{
	public:
		Harl(void);
		~Harl(void);

		void complain(std::string level) const ;

	private:
		void		debug(void) const ;
		void		info(void) const ;
		void		warning(void) const ;
		void		error(void) const ;
};

struct s_level {
	std::string	name;
	void		(Harl::*complaint)(void) const ;
};

#endif