# include "../inc/FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap() {
	this->_name = "Random FragTrap";
	this->_hitPoints = FRAGTRAP_DEFAULT_HIT_POINTS;
	this->_max_hitpoints = FRAGTRAP_DEFAULT_HIT_POINTS;
	this->_energyPoints = FRAGTRAP_DEFAULT_ENERGY_POINTS;
	this->_attackDamage = FRAGTRAP_DEFAULT_ATTACK_DAMAGE;
	std::cout << "FragTrap " << _name << " has been born" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	this->_hitPoints = FRAGTRAP_DEFAULT_HIT_POINTS;
	this->_max_hitpoints = FRAGTRAP_DEFAULT_HIT_POINTS;
	this->_energyPoints = FRAGTRAP_DEFAULT_ENERGY_POINTS;
	this->_attackDamage = FRAGTRAP_DEFAULT_ATTACK_DAMAGE;
	std::cout << "FragTrap " << _name << " has been born" << std::endl;
}

FragTrap::FragTrap(const FragTrap &s) : ClapTrap (s) {
	*this = s;
	std::cout << "FragTrap " << _name << " has been copied" << std::endl;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap " << _name << " has been destroyed" << std::endl;
}

// Overloaded Operators
FragTrap &FragTrap::operator = (const FragTrap &s) {
	if (this != &s) {
		this->_name = s._name + "Clone";
		this->_max_hitpoints = s._max_hitpoints;
		this->_hitPoints = s._hitPoints;
		this->_energyPoints = s._energyPoints;
		this->_attackDamage = s._attackDamage;
	}
	std::cout << "FragTrap " << _name << " has been assigned" << std::endl;
	return (*this);
}

void FragTrap::highFivesGuys(void) {
	if (!checkEnergy() || !checkAlive())
		return ;
	std::cout << _name << ": 'Gimme a high five guys!'" << std::endl;
}
