#include "../inc/Cat.hpp"
#include "../inc/Brain.hpp"
#include <iostream>
#include <cstdlib>
#include <cstdio>

// constructors/destructor
Cat::Cat(void) : Animal() {
	this->_brain = new Brain();
	this->_ideaCount = 0;
	this->_type = "Cat";
	std::cout << "A cat has been created" << std::endl;
}

Cat::Cat(const Cat &src) : Animal (src) {
	*this = src;
	std::cout << "A cat has been copied" << std::endl;
}

Cat::~Cat() {
	delete (this->_brain);
	std::cout << "A cat has been destructed" << std::endl;
}

// overloaded operators
Cat &Cat::operator = (const Cat &src) {
	if (this == &src)
		return *this;
	this->_type = src._type;
	this->_brain = new Brain();
	if (this->_brain == NULL)
		exit(EXIT_FAILURE);
	*this->_brain = *src._brain;
	std::cout << "A cat has been assigned" << std::endl;
	return (*this);
}

// getter/setter
void	Cat::getIdeas(void) const {
	for (int i = 0; i < 100; i++) {
		if (this->_brain->getIdea(i).length())
			std::cout << "  idea " << i << " : " << this->_brain->getIdea(i) << " \t at  " << this->_brain->getIdeaAddress(i) << std::endl;
	}
}

void	Cat::setIdea(std::string idea) {
	if (_ideaCount < 100)
		this->_brain->setIdea(_ideaCount++, idea);
	else
		std::cout << "Brain is completely filled with ideas..." << std::endl;
}

// other attributes
void Cat::makeSound(void) const {
	std::cout << "Miauw..." << std::endl;
}
