# include "../inc/WrongCat.hpp"
# include <iostream> 

// constructors/destructor
WrongCat::WrongCat(void) : WrongAnimal() {
	this->_type = "WrongCat";
	std::cout << "A WrongCat has been created" << std::endl;
}

WrongCat::WrongCat(const WrongCat &src) : WrongAnimal (src) {
	*this = src;
	std::cout << "A WrongCat has been copied" << std::endl;
}

WrongCat::~WrongCat() { std::cout << "A WrongCat has been destructed" << std::endl; }

// overloaded operators
WrongCat &WrongCat::operator = (const WrongCat &src) {
	if (this != &src)
		this->_type = src._type;
	std::cout << "A WrongCat has been assigned" << std::endl;
	return (*this);
}

// other attributes
void WrongCat::makeSound(void) const { std::cout << _type << ": Miauw..." << std::endl; }
