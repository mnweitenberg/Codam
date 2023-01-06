#include "../inc/main.hpp"
#include "../inc/Animal.hpp"
#include "../inc/Cat.hpp"
#include "../inc/Dog.hpp"
#include "../inc/WrongAnimal.hpp"
#include "../inc/WrongCat.hpp"
#include <iostream>
#include <cstdlib>

#define GREEN "\e[32m"
#define NORMAL "\e[00m"

int main(void) {
	// Does not work anymore:
	// const Animal *animal = new Animal();
	// animal->makeSound();

	// TEST CREATION OF CATS/DOGS
	std::cout << GREEN << "Constructing" << NORMAL << std::endl;
	const Animal	*meta[10];
	for (int i=0; i<10; i++)
	{
		if (i < 5)
			meta[i] = new Cat();
		else
			meta[i] = new Dog();
		if (meta[i] == NULL)
			exit(EXIT_FAILURE);
	}

	std::cout << GREEN << "\nTesting" << NORMAL << std::endl;
	for (int i = 0; i < 10; i++) {
		std::cout << meta[i]->getType() << ": ";
		meta[i]->makeSound();
	}

	std::cout << GREEN << "\nDeconstructing" << NORMAL << std::endl;
	for (int i = 0; i < 10; i++)
		delete(meta[i]);

	// TEST DEEP COPY
	std::cout << GREEN << "\nConstructing" << NORMAL << std::endl;
	Dog *bamboo = new Dog();
	Dog *oekje = new Dog();

	std::cout << GREEN << "\nTesting" << NORMAL << std::endl;
	bamboo->setIdea("Happy happy!!!");
	bamboo->setIdea("Cuddle time!!!");
	bamboo->setIdea("Can I lick it?");
	for (int i = 0; i < 10; i++) {
		oekje->setIdea("Zzz time for sleep");
		oekje->setIdea("Zzz time for sleep");
		oekje->setIdea("Zzz time for sleep");
		oekje->setIdea("Zzz time for sleep");
		oekje->setIdea("Zzz time for sleep");
		oekje->setIdea("Zzz time for sleep");
		oekje->setIdea("Zzz time for sleep");
		oekje->setIdea("Do I smell food?");
		oekje->setIdea("Mmmm delicious!!!");
		oekje->setIdea("Afterdinner dip...");
	}
	oekje->setIdea("Is there room for 1 more idea?");

	std::cout << "Bamboo :\n";
	bamboo->getIdeas();
	std::cout << "\nOekje :\n";
	oekje->getIdeas();

	std::cout << GREEN << "\nDeconstructing" << NORMAL << std::endl;
	delete(bamboo);
	delete(oekje);

	return (0);
}
