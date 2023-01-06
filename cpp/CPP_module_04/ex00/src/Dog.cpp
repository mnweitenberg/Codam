# include "../inc/Dog.hpp"
# include <iostream> 

// constructors/destructor
Dog::Dog(void) : Animal() {
	this->_type = "Dog";
	std::cout << "A dog has been created" << std::endl;
}

Dog::Dog(const Dog &src) : Animal (src) {
	*this = src;
	std::cout << "A dog has been copied" << std::endl;
}

Dog::~Dog() { std::cout << "A dog has been destructed" << std::endl; }

// overloaded operators
Dog &Dog::operator = (const Dog &src) {
	if (this != &src)
		this->_type = src._type;
	std::cout << "A dog has been assigned" << std::endl;
	return (*this);
}

// other attributes
void Dog::makeSound(void) const {
	std::cout << _type << ": Whoof!!!" << std::endl;
}
