#include "../inc/main.hpp"
#include "../inc/Animal.hpp"
#include "../inc/Cat.hpp"
#include "../inc/Dog.hpp"
#include "../inc/WrongAnimal.hpp"
#include "../inc/WrongCat.hpp"
#include <iostream>
#include <cstdlib>

int main(void) {
	std::cout << "Constructing" << std::endl;
	const Animal* meta = new Animal();
	const Animal* bamboo = new Dog();
	const Animal* teunie = new Cat();
	const WrongAnimal* wrong_meta = new WrongAnimal();
	const WrongAnimal* wrong_cat = new WrongCat();

	// Animal
	std::cout << "\nTest Animal" << std::endl;
	std::cout << meta->getType() << " " << std::endl;
	meta->makeSound();

	// Dog
	std::cout << "\nTest Dog" << std::endl;
	std::cout << bamboo->getType() << " " << std::endl;
	bamboo->makeSound();

	// Cat
	std::cout << "\nTest Cat" << std::endl;
	std::cout << teunie->getType() << " " << std::endl;
	teunie->makeSound();

	// Wrong Animal
	std::cout << "\nTest WrongAnimal" << std::endl;
	std::cout << wrong_meta->getType() << " " << std::endl;
	wrong_meta->makeSound();

	// Wrong Cat
	std::cout << "\nTest WrongCat" << std::endl;
	std::cout << wrong_cat->getType() << " " << std::endl;
	wrong_cat->makeSound();

	std::cout << "\nDeconstructing" << std::endl;
	delete meta;
	delete bamboo;
	delete teunie;
	delete wrong_meta;
	delete wrong_cat;

	return (0);
}
