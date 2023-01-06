# include "../inc/ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap() {
	this->_name = "Random ScavTrap";
	this->_hitPoints = SKAVTRAP_DEFAULT_HIT_POINTS;
	this->_max_hitpoints = SKAVTRAP_DEFAULT_HIT_POINTS;
	this->_energyPoints = SKAVTRAP_DEFAULT_ENERGY_POINTS;
	this->_attackDamage = SKAVTRAP_DEFAULT_ATTACK_DAMAGE;
	this->_isGuardingGate = SKAVTRAP_DEFAULT_GAURD_MODE;
	std::cout << "ScavTrap " << _name << " has been born" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	this->_hitPoints = SKAVTRAP_DEFAULT_HIT_POINTS;
	this->_max_hitpoints = SKAVTRAP_DEFAULT_HIT_POINTS;
	this->_energyPoints = SKAVTRAP_DEFAULT_ENERGY_POINTS;
	this->_attackDamage = SKAVTRAP_DEFAULT_ATTACK_DAMAGE;
	this->_isGuardingGate = SKAVTRAP_DEFAULT_GAURD_MODE;
	std::cout << "ScavTrap " << _name << " has been born" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &s) : ClapTrap (s) {
	*this = s;
	std::cout << "ScavTrap " << _name << " has been copied" << std::endl;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap " << _name << " has been destroyed" << std::endl;
}

// Overload Operators
ScavTrap &ScavTrap::operator = (const ScavTrap &s) {
	if (this != &s) {
		this->_name = s._name + "Clone";
		this->_max_hitpoints = s._max_hitpoints;
		this->_hitPoints = s._hitPoints;
		this->_energyPoints = s._energyPoints;
		this->_attackDamage = s._attackDamage;
		this->_isGuardingGate = s._isGuardingGate;
	}
	std::cout << "ScavTrap " << _name << " has been assigned" << std::endl;
	return (*this);
}

void ScavTrap::attack(const std::string& target) {
	if (!checkEnergy() || _hitPoints <= 0)
		return ;
	std::cout << _name << " skavAttacks " 
		<< target << " causing " << _attackDamage 
		<< " points of damage!" << std::endl;
}

void ScavTrap::guardGate(void) {
	if (!checkEnergy() || _hitPoints <= 0)
		return ;
	if (!_isGuardingGate)
		std::cout << _name << " is now guarding the gate" << std::endl;
	else
		std::cout << _name << " is already guarding the gate" << std::endl;
	_isGuardingGate = true;
}
