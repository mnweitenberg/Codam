#ifndef ScavTrap_HPP
# define ScavTrap_HPP

# include "../inc/ClapTrap.hpp"
# include <sstream> 
# include <iostream> 

# define SKAVTRAP_DEFAULT_HIT_POINTS 100
# define SKAVTRAP_DEFAULT_ENERGY_POINTS 50
# define SKAVTRAP_DEFAULT_ATTACK_DAMAGE 20
# define SKAVTRAP_DEFAULT_GAURD_MODE false

class ScavTrap: virtual public ClapTrap
{
	public:
		ScavTrap(void);
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap &s);
		~ScavTrap(void);
		ScavTrap &operator = (const ScavTrap &s);

		void attack(const std::string& target);
		void guardGate(void);

	private:
		bool	_isGuardingGate;
};

#endif