# include "../inc/WrongAnimal.hpp"
# include <iostream> 

// constructors/destructor
WrongAnimal::WrongAnimal(void) : _type("none") { std::cout << "An WrongAnimal has been created" << std::endl; }
WrongAnimal::WrongAnimal(const WrongAnimal &src) { *this = src; std::cout << "An WrongAnimal has been copied" << std::endl; }
WrongAnimal::~WrongAnimal() { std::cout << "An WrongAnimal has been destructed" << std::endl; }

// overloaded operators
WrongAnimal &WrongAnimal::operator = (const WrongAnimal &src) {
	if (this != &src)
		this->_type = src._type;
	std::cout << "An WrongAnimal has been assigned" << std::endl;
	return (*this);
}

// getter/setter
std::string WrongAnimal::getType(void) const { return (this->_type); }

// other attributes
void WrongAnimal::makeSound(void) const { std::cout << "[UNBEARABLE NOISE!!!]" << std::endl; }
