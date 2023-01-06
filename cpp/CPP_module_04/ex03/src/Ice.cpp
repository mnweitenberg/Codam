#include "../inc/Ice.hpp"
#include <iostream>

// constructors/destructor
Ice::Ice(void) : AMateria("ice") { }
Ice::Ice(const Ice &src) : AMateria (src) {	*this = src; }
Ice::~Ice() { }

// overloaded operators
Ice &Ice::operator = (const Ice &src) { (void)src; return (*this); }

// publice functions
Ice *Ice::clone() const { return (new Ice(*this)); }
void Ice::use(ICharacter &target) { std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl; }
