# include "../inc/Cat.hpp"
# include <iostream> 

// constructors/destructor
Cat::Cat(void) : Animal() {
	this->_type = "Cat";
	std::cout << "A cat has been created" << std::endl;
}

Cat::Cat(const Cat &src) : Animal (src) {
	*this = src;
	std::cout << "A cat has been copied" << std::endl;
}

Cat::~Cat() { std::cout << "A cat has been destructed" << std::endl; }

// overloaded operators
Cat &Cat::operator = (const Cat &src) {
	if (this != &src)
		this->_type = src._type;
	std::cout << "A cat has been assigned" << std::endl;
	return (*this);
}

// other attributes
void Cat::makeSound(void) const {
	std::cout << _type << ": Miauw..." << std::endl;
}
