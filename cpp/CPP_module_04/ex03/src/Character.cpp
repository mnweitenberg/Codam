#include "../inc/Character.hpp"
#include <iostream>
#include <cstdlib>
#include <cstdio>

// constructors/destructor
Character::Character(const std::string &name) : _name(name) {
	this->_headMateria = NULL;
	for (int i = 0; i < INVENTORY_SIZE; i++)
		_inventory[i] = NULL;
}

Character::Character(const Character &src) { *this = src; }

void	Character::deleteList(void) {
	t_discarded_materia *tmp;
	while (_headMateria != NULL) {
		tmp = _headMateria;
		_headMateria = _headMateria->next;
		delete tmp->materia;
		delete tmp;
	}
}

Character::~Character() {
	for (int i = 0; i < INVENTORY_SIZE; i++) {
		if (_inventory[i])
			delete _inventory[i];
	}
	Character::deleteList();
}

// overloaded operators
Character &Character::operator=(const Character &src)
{
	if(this != &src) {
		this->_name = src._name;
		for(int i = 0; i < INVENTORY_SIZE; i++) {
			if (_inventory[i])
				delete _inventory[i];
			if (src._inventory[i])
				_inventory[i] = src._inventory[i]->clone();
			else
				_inventory[i] = NULL;
		}
	}
	return *this;
}

// public functions
std::string const & Character::getName() const {
	return (this->_name);
}

void Character::equip(AMateria* m) {
	for (int i = 0; i < INVENTORY_SIZE; i++) {
		if (_inventory[i] == NULL) {
			_inventory[i] = m;
			return ;
		}
	}
	std::cout << "Can't equip: inventory of " << _name << " is full." << std::endl;
	delete m;
}

static t_discarded_materia	*ft_lstlast(t_discarded_materia *lst)
{
	if (!lst)
		return (0);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

static void	appendToList(t_discarded_materia **list, AMateria *discarded_materia) {
	t_discarded_materia *newNode = new t_discarded_materia;
	newNode->materia = discarded_materia;
	newNode->next = NULL;

	if (!list)
		return ;
	if (*list == 0)
		*list = newNode;
	else
	{
		t_discarded_materia *temp = ft_lstlast(*list);
		temp->next = newNode;
	}
}

void Character::unequip(int idx) {
	if (idx >=0 && idx < INVENTORY_SIZE && _inventory[idx] != NULL) {
		appendToList(&_headMateria, _inventory[idx]);
		_inventory[idx] = NULL;
	}
	else
		std::cout << "Can't unequip: "<< _name << " has no inventory" << std::endl;
}

void Character::use(int idx, ICharacter &target) {
	if(idx >= 0 && idx < INVENTORY_SIZE && _inventory[idx])
		_inventory[idx]->use(target);
}


