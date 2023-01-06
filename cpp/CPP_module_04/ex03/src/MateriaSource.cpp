# include "../inc/MateriaSource.hpp"
# include <iostream> 

// constructors/destructor
MateriaSource::MateriaSource(void) {
	for (int i = 0; i < INVENTORY_SIZE; i++)
		_inventory[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &src) { *this = src; }

MateriaSource::~MateriaSource() {
	for (int i = 0; i < INVENTORY_SIZE; i++) {
		if (_inventory[i])
			delete _inventory[i];
	}
}

// overloaded operators
MateriaSource &MateriaSource::operator = (const MateriaSource &src) {
	if (this != &src) {
		for (int i = 0; i < INVENTORY_SIZE; i++) {
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
void MateriaSource::learnMateria(AMateria* m) {
	for(int i = 0; i < INVENTORY_SIZE; i++) {
		if(_inventory[i] == NULL) {
			_inventory[i] = m;
			return ;
		}
	}
	delete m;
	std::cout << "Error: inventory is full" << std::endl;
}

AMateria* MateriaSource::createMateria(std::string const &type) {
	for(int i = 0; i < INVENTORY_SIZE; i++) {
		if(_inventory[i] != NULL && _inventory[i]->getType() == type)
			return (_inventory[i]->clone());
	}
	std::cout << "Error: unknown materia" << std::endl;
	return (NULL);
}
