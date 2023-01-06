#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <sstream> 
# include <iostream> 

# define DEFAULT_HIT_POINTS 10
# define DEFAULT_ENERGY_POINTS 10
# define DEFAULT_ATTACK_DAMAGE 0

class ClapTrap
{
	public:
		ClapTrap(void);
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap &c);
		~ClapTrap(void);
		ClapTrap &operator = (const ClapTrap &c);

		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

	protected:
		bool		checkEnergy(void);
		bool		checkAlive(void);
		int			_max_hitpoints;
		std::string	_name;
		int			_hitPoints;
		int			_energyPoints;
		int			_attackDamage;
};

#endif