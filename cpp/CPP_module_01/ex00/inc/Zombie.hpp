#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <sstream> 
# include <iostream> 

class Zombie
{
	public:
		Zombie(std::string name);
		~Zombie();
		void	announce(void) const;

	private:
		std::string _name;
};

#endif