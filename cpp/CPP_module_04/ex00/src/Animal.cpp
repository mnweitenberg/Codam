# include "../inc/Animal.hpp"
# include <iostream> 

// constructors/destructor
Animal::Animal(void) : _type("none") { std::cout << "An animal has been created" << std::endl; }
Animal::Animal(const Animal &src) { *this = src; std::cout << "An animal has been copied" << std::endl; }
Animal::~Animal() { std::cout << "An animal has been destructed" << std::endl; }

// overloaded operators
Animal &Animal::operator = (const Animal &src) {
	if (this != &src)
		this->_type = src._type;
	std::cout << "An animal has been assigned" << std::endl;
	return (*this);
}

// getter/setter
std::string Animal::getType(void) const { return (this->_type); }

// other attributes
void Animal::makeSound(void) const { std::cout << "[the sound of silence...]" << std::endl; }
