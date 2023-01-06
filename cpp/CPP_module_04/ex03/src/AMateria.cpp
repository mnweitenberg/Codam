# include "../inc/AMateria.hpp"
# include <iostream> 

// constructors/destructor
AMateria::AMateria(void) : _type("none") { }
AMateria::AMateria(std::string const &type) : _type(type) { }
AMateria::AMateria(const AMateria &src) { *this = src; }
AMateria::~AMateria() { }

// overloaded operators
AMateria &AMateria::operator = (const AMateria &src) {
	if (this != &src)
		this->_type = src._type;
	return (*this);
}

// getter/setter
std::string const &AMateria::getType() const { return (this->_type);}

// public funcitons
void AMateria::use(ICharacter& target) {
	std::cout << "what to do to? " << target.getName() << std::endl;
}
