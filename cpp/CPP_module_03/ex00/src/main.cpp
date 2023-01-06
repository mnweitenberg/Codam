#include "../inc/main.hpp"
#include "../inc/ClapTrap.hpp"
#include <iostream>

int main(void) {
	ClapTrap	Thor("The Mighty Thor");
	ClapTrap	NoName;
	ClapTrap	Clone(NoName);
	ClapTrap	Impersonator("Spy");

	std::cout << std::endl;
	NoName.attack("some innocent fella");
	NoName.takeDamage(10);
	NoName.takeDamage(10);
	NoName.beRepaired(5);
	NoName.attack("his own allies");
	NoName.takeDamage(10);

	std::cout << std::endl;
	Thor.beRepaired(3);
	for (int i = 0; i < 12; i++)
		Thor.attack("all the bad guys");
	Thor.beRepaired(3);
	Thor.takeDamage(1);
	Thor.takeDamage(1);
	Thor.takeDamage(1);
	Thor.beRepaired(30);
	Thor.takeDamage(1);
	Thor.takeDamage(1);
	Thor.takeDamage(1);
	Thor.takeDamage(9);
	Thor.takeDamage(9);

	std::cout << std::endl;
	Clone.attack("no one");
	Clone.takeDamage(20);

	std::cout << std::endl;
	Impersonator = Thor;
	Impersonator.attack("no one");
	Impersonator.takeDamage(20);
	std::cout << std::endl;
	return (0);
}
