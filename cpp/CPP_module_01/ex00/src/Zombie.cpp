# include "../inc/Zombie.hpp"

Zombie::Zombie(std::string name) : _name(name) { }

Zombie::~Zombie() {
	std::cout << Zombie::_name << " has been destroyed." << std::endl;
}

void	Zombie::announce() const {
	std::cout << Zombie::_name << " : BraiiiiiiinnnzzzZ..." << std::endl;
}
