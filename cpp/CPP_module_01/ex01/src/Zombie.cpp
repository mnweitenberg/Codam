# include "../inc/Zombie.hpp"

Zombie::Zombie() { }

Zombie::~Zombie() {
	std::cout << Zombie::_name << " has been destroyed." << std::endl;
}

void	Zombie::announce() const {
	std::cout << Zombie::_name << " : BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::setName(std::string name) { this->_name = name; }
