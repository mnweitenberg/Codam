#include "../inc/main.hpp"
#include "../inc/ClapTrap.hpp"
#include "../inc/ScavTrap.hpp"
#include "../inc/FragTrap.hpp"
#include "../inc/DiamondTrap.hpp"
#include <iostream>

int main(void) {
	ClapTrap	Thor("The Mighty Thor");
	ClapTrap	NoName;
	ClapTrap	Clone(NoName);
	ScavTrap	Skav("Skavalicious");
	ScavTrap	SkavClone(Skav);
	FragTrap	Frag("FragBro");
	FragTrap	FragClone(Frag);
	DiamondTrap	ShineLikeA;
	DiamondTrap	Diamonds("Girlsbestfriend");
	DiamondTrap	DiamondClone(Diamonds);

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
	Thor.beRepaired(3);
	Thor.takeDamage(1);
	Thor.takeDamage(1);
	Thor.takeDamage(1);
	Thor.takeDamage(9);
	Thor.takeDamage(9);

	std::cout << std::endl;
	Clone.attack("no one");
	Clone.takeDamage(20);

	std::cout << std::endl;
	SkavClone.attack("some other skav");
	SkavClone.takeDamage(10);
	SkavClone.takeDamage(10);
	SkavClone.beRepaired(5);
	SkavClone.guardGate();
	SkavClone.attack("his own allies");
	SkavClone.takeDamage(10);
	SkavClone.guardGate();

	std::cout << std::endl;
	Skav.beRepaired(3);
	for (int i = 0; i < 52; i++)
		Skav.attack("all the bad guys");
	Skav.beRepaired(3);
	Skav.takeDamage(1);
	Skav.guardGate();
	Skav.guardGate();
	Skav.takeDamage(10);
	Skav.takeDamage(10);
	Skav.beRepaired(30);
	Skav.takeDamage(10);
	Skav.takeDamage(10);
	Skav.takeDamage(10);
	Skav.takeDamage(90);
	Skav.takeDamage(90);

	std::cout << std::endl;
	FragClone.attack("some skav");
	FragClone.takeDamage(100);
	FragClone.takeDamage(100);
	FragClone.beRepaired(5);
	FragClone.highFivesGuys();
	FragClone.attack("his own allies");
	FragClone.takeDamage(10);
	FragClone.highFivesGuys();

	std::cout << std::endl;
	Frag.beRepaired(3);
	Frag.highFivesGuys();
	for (int i = 0; i < 52; i++)
		Frag.attack("all the bad guys");
	Frag.beRepaired(3);
	Frag.takeDamage(1);
	Frag.highFivesGuys();
	Frag.highFivesGuys();
	Frag.takeDamage(10);
	Frag.takeDamage(10);
	Frag.beRepaired(30);
	Frag.takeDamage(10);
	Frag.takeDamage(10);
	Frag.takeDamage(10);
	Frag.takeDamage(90);
	Frag.takeDamage(90);

	std::cout << std::endl;
	ShineLikeA.attack("some skav");
	ShineLikeA.whoAmI();

	std::cout << std::endl;
	DiamondClone.attack("some skav");
	DiamondClone.takeDamage(100);
	DiamondClone.takeDamage(100);
	DiamondClone.beRepaired(5);
	DiamondClone.whoAmI();
	DiamondClone.attack("his own allies");
	DiamondClone.takeDamage(10);
	DiamondClone.whoAmI();

	std::cout << std::endl;
	Diamonds.beRepaired(3);
	Diamonds.whoAmI();
	for (int i = 0; i < 52; i++)
		Diamonds.attack("all the bad guys");
	Diamonds.beRepaired(3);
	Diamonds.takeDamage(1);
	Diamonds.whoAmI();
	Diamonds.whoAmI();
	Diamonds.takeDamage(10);
	Diamonds.takeDamage(10);
	Diamonds.beRepaired(30);
	Diamonds.takeDamage(10);
	Diamonds.takeDamage(10);
	Diamonds.takeDamage(10);
	Diamonds.takeDamage(90);
	Diamonds.takeDamage(90);
	std::cout << std::endl;
	return (0);
}
