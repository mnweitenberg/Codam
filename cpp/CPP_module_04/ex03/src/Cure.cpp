#include "../inc/Cure.hpp"
#include <iostream>

// constructors/destructor
Cure::Cure(void) : AMateria("cure") { }
Cure::Cure(const Cure &src) : AMateria (src) { *this = src; }
Cure::~Cure() { }

// overloaded operators
Cure &Cure::operator = (const Cure &src) { (void)src; return (*this); }

// publCure functions
Cure *Cure::clone() const { return (new Cure(*this)); }
void Cure::use(ICharacter &target) { std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;}
