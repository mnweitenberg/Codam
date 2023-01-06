#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <sstream> 
# include <iostream> 

class Zombie
{
	public:
		Zombie();
		~Zombie();
		void	announce(void) const;
		void	setName(std::string name);

	private:
		std::string _name;
};

#endif