# include "../inc/ClapTrap.hpp"

ClapTrap::ClapTrap(void) {
	this->_name = "default";
	this->_max_hitpoints = DEFAULT_HIT_POINTS;
	this->_hitPoints = DEFAULT_HIT_POINTS;
	this->_energyPoints = DEFAULT_ENERGY_POINTS;
	this->_attackDamage = DEFAULT_ATTACK_DAMAGE;
	std::cout << "ClapTrap " << _name << " has been born" << std::endl;
}

ClapTrap::ClapTrap(std::string name) {
	this->_name = name;
	this->_max_hitpoints = DEFAULT_HIT_POINTS;
	this->_hitPoints = DEFAULT_HIT_POINTS;
	this->_energyPoints = DEFAULT_ENERGY_POINTS;
	this->_attackDamage = DEFAULT_ATTACK_DAMAGE;
	std::cout << "ClapTrap " << _name << " has been born" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &c) {
	*this = c; 
	std::cout << _name << " has been copied" << std::endl;
}

ClapTrap::~ClapTrap() {
	std::cout << _name << " has been destroyed" << std::endl;
}

// Overload Operators
ClapTrap &ClapTrap::operator = (const ClapTrap &c) {
	if (this != &c)	{
		this->_name = c._name + "Clone";
		this->_max_hitpoints = c._max_hitpoints;
		this->_hitPoints = c._hitPoints;
		this->_energyPoints = c._energyPoints;
		this->_attackDamage = c._attackDamage;
	}
	std::cout << _name << " has been assigned" << std::endl;
	return (*this);
}

bool ClapTrap::checkEnergy(void) {
	if (_energyPoints < 1) {
		std::cout << _name << " has no energy left" << std::endl;
		return (false);
	}
	_energyPoints--;
	return (true);
}

bool ClapTrap::checkAlive(void) {
	if (_hitPoints <= 0) {
		std::cout << _name << " is dead" << std::endl;
		return (false);
	}
	return (true);
}

void ClapTrap::attack(const std::string& target) {
	if (!checkEnergy() || !checkAlive())
		return ;
	std::cout 	<< _name << " attacks " 
				<< target << " causing " << _attackDamage 
				<< " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (_hitPoints <= 0) {
		std::cout << "Please stop beating "	<< _name << "'s dead body " << std::endl;
		return ;
	}
	_hitPoints -= amount;
	if (_hitPoints <= 0) {
		std::cout 	<< _name << " has died an heroic dead" << std::endl;
		return ;
	}
	std::cout 	<< _name << " is attacked and now has " 
				<< _hitPoints << " hitpoints left" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (!checkEnergy() || _hitPoints <= 0)
		return ;
	_hitPoints += amount;
	if (_hitPoints > _max_hitpoints)
		_hitPoints = _max_hitpoints;
	std::cout 	<< _name << " heals itself and now has " 
				<< _hitPoints << " hitpoints " << std::endl;
}