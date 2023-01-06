#include "../inc/Dog.hpp"
#include "../inc/Brain.hpp"
#include <iostream> 
#include <cstdlib>
#include <cstdio>

// constructors/destructor
Dog::Dog(void) : Animal() {
	this->_brain = new Brain();
	this->_ideaCount = 0;
	this->_type = "Dog";
	std::cout << "A dog has been created" << std::endl;
}

Dog::Dog(const Dog &src) : Animal (src) {
	*this = src;
	std::cout << "A dog has been copied" << std::endl;
}

Dog::~Dog() {
	delete (this->_brain);
	std::cout << "A dog has been destructed" << std::endl;
}

// overloaded operators
Dog &Dog::operator = (const Dog &src) {
	if (this == &src)
		return *this;
	this->_type = src._type;
	this->_brain = new Brain();
	if (this->_brain == NULL)
		exit(EXIT_FAILURE);
	*this->_brain = *src._brain;
	std::cout << "A dog has been assigned" << std::endl;
	return *this;
}

// getter/setter
void	Dog::getIdeas(void) const {
	for (int i = 0; i < 100; i++) {
		if (this->_brain->getIdea(i).length())
			std::cout << "  idea " << i << " : " << this->_brain->getIdea(i) << " \t at  " << this->_brain->getIdeaAddress(i) << std::endl;
	}
}

void	Dog::setIdea(std::string idea) {
	if (_ideaCount < 100)
		this->_brain->setIdea(_ideaCount++, idea);
	else
		std::cout << "Brain is completely filled with ideas..." << std::endl;
}

// other attributes
void Dog::makeSound(void) const {
	std::cout << "Whoof!!!" << std::endl;
}
