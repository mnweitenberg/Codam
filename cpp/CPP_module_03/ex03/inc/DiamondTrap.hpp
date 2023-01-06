#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "../inc/ClapTrap.hpp"
# include "../inc/ScavTrap.hpp"
# include "../inc/FragTrap.hpp"
# include <sstream> 
# include <iostream> 

class DiamondTrap : public ScavTrap, public FragTrap
{
	public:
		DiamondTrap(void);
		DiamondTrap(std::string name);
		DiamondTrap(const DiamondTrap &d);
		~DiamondTrap(void);
		DiamondTrap &operator = (const DiamondTrap &d);

		void	attack(const std::string& target);
		void	whoAmI();

	private:
		std::string _name;
};

#endif