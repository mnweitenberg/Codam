#include "../inc/main.hpp"
#include "../inc/AMateria.hpp"
#include "../inc/Ice.hpp"
#include "../inc/Cure.hpp"
#include "../inc/Character.hpp"
#include "../inc/MateriaSource.hpp"
#include <iostream>
#include <cstdlib>

#define GREEN "\e[32m"
#define NORMAL "\e[00m"

int main()
{
	ICharacter* me = new Character("me");
	ICharacter* bob = new Character("bob");

	std::cout << GREEN <<"Adding MaterialSource" << NORMAL << std::endl;
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	// adding more than 4 MateriaSource should say: "Error: inventory is full" 
	src->learnMateria(new Ice());

	std::cout << GREEN <<"\nCreating MaterialSource" << NORMAL << std::endl;
	AMateria* tmp;
	// creating unknown materia should say: "Error: unknown materia" 
	tmp = src->createMateria("fire");
	me->equip(tmp);

	std::cout << GREEN <<"\nTesting equip" << NORMAL << std::endl;
	// creating materia
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("ice");
	me->equip(tmp);
	
	// adding more than 4 materia should say: "Can't equip: inventory of <name> is full" 
	tmp = src->createMateria("cure");
	me->equip(tmp);

	std::cout << GREEN <<"\nTesting actions" << NORMAL << std::endl;
	// testing actions
	me->use(0, *bob);
	me->use(1, *bob);
	me->use(2, *bob);
	me->use(3, *bob);
	me->use(0, *me);

	// indexnumber > inventory: should do nothing
	me->use(4, *bob);
	me->use(5, *bob);
	me->use(-1, *bob);

	std::cout << GREEN <<"\nTesting unequip" << NORMAL << std::endl;
	// testing unequip
	me->unequip(1);
	me->unequip(2);
	me->unequip(3);

	// unequip non existing mater, should say: Can't unequip: <name> has no inventory
	me->unequip(1);
	me->unequip(4);
	me->unequip(5);
	bob->unequip(1);

	// equiping before deconstruction, to test for leaks
	tmp = src->createMateria("cure");
	me->equip(tmp);

	// delete 
	delete bob;
	delete me;
	delete src;
	return (0);
}
