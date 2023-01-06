#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "../inc/ClapTrap.hpp"
# include <sstream> 
# include <iostream> 

# define FRAGTRAP_DEFAULT_HIT_POINTS 100
# define FRAGTRAP_DEFAULT_ENERGY_POINTS 100
# define FRAGTRAP_DEFAULT_ATTACK_DAMAGE 30

class FragTrap: virtual public ClapTrap
{
	public:
		FragTrap(void);
		FragTrap(std::string name);
		FragTrap(const FragTrap &f);
		~FragTrap(void);
		FragTrap &operator = (const FragTrap &s);

		void highFivesGuys(void);
};

#endif