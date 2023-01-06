# include "../inc/DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) : ClapTrap("diamond_clap_name") {
	std::cout << "A ";
	this->_name = "diamond";
	this->_hitPoints = FragTrap::_hitPoints;
	this->_energyPoints = ScavTrap::_energyPoints;
	this->_attackDamage = FragTrap::_attackDamage;
	std::cout << "DiamondTrap " << _name << " has been born" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name") {
	this->_name = name;
	this->_hitPoints = FragTrap::_hitPoints;
	this->_energyPoints = ScavTrap::_energyPoints;
	this->_attackDamage = FragTrap::_attackDamage;
	std::cout << "DiamondTrap " << _name << " has been born" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &d) : ClapTrap(d), ScavTrap(d), FragTrap(d) {
	*this = d;
	std::cout << "DiamondTrap " << _name << " has been copied" << std::endl;
}

DiamondTrap::~DiamondTrap() {
	std::cout << "DiamondTrap " << _name << " has been destroyed" << std::endl;
}

// Overload Operators
DiamondTrap &DiamondTrap::operator = (const DiamondTrap &s) {
	if (this != &s) {
		this->_name = s._name + "_clap_name";
		this->_max_hitpoints = s._max_hitpoints;
		this->_hitPoints = s._hitPoints;
		this->_energyPoints = s._energyPoints;
		this->_attackDamage = s._attackDamage;
	}
	std::cout << "DiamondTrap " << _name << " has been assigned" << std::endl;
	return (*this);
}

void DiamondTrap::attack(const std::string& target) {
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI(void) {
	if (!checkEnergy() || !checkAlive())
		return ;
	std::cout << "I am "<< _name;
	std::cout << " and I'm created from " << ClapTrap::_name << std::endl;
}
