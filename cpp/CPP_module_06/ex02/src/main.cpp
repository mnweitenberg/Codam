#include "../inc/main.hpp"
#include "../inc/Base.hpp"
#include <iostream>
#include <string>
#include <stdint.h>
#include <typeinfo>
#include <cstdlib>

#define GREEN "\e[32m"
#define NORMAL "\e[00m"

Base *generate(void) {
	unsigned int random = rand() % 3;
	std::cout << "created type\t\t= " << (char)(random + 'A') << std::endl;
	if (random == 0)
		return (new A);
	else if (random == 1)
		return (new B);
	else
		return (new C);
} 

void identify(Base* p) {
	if (dynamic_cast<A *>(p))
		std::cout << "type (from reference)\t= " << "A" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "type (from reference)\t= " << "B" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "type (from reference)\t= " << "C" << std::endl;
}

void identify(Base& p) {
	try {
		(void)dynamic_cast<A &>(p);
		std::cout << "type (from pointer)\t= " << "A" << std::endl;
	}
	catch(const std::exception& e) {}
	
	try {
		(void)dynamic_cast<B &>(p);
		std::cout << "type (from pointer)\t= " << "B" << std::endl;
	}
	catch(const std::exception& e) {}

	try	{
		(void)dynamic_cast<C &>(p);
		std::cout << "type (from pointer)\t= " << "C" << std::endl;
	}
	catch(const std::exception& e) {}
}

int main(void) {
	srand (time(NULL));
	for (int i = 1; i < 11; i++) {
		std::cout << GREEN << "\nTEST " << i << NORMAL << std::endl;
		Base *base = generate();
		identify(base);
		identify(*base);
		delete base;
	}
	return (0);
}
