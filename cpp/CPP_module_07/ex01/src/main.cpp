#include "../inc/iter.hpp"
#include <iostream>
#include <string>

#define GREEN "\e[32m"
#define NORMAL "\e[00m"

template<typename T>
void	printItems(T item) { std::cout << item << std::endl; }

int main(void) {
	std::cout << GREEN << "\nINTS " << NORMAL << std::endl;
	int ints[] = {4, 2, 42, -42, -420};
	iter(ints, 5, printItems);

	std::cout << GREEN << "\nCHARS " << NORMAL << std::endl;
	const char chars[] = {'t', 'e', 's', 't'};
	iter(chars, 4, printItems);

	std::cout << GREEN << "\nSTRINGS " << NORMAL << std::endl;
	const std::string strings[] = {"what", "a", "beautiful", "test"};
	iter(strings, 4, printItems);

	std::cout << GREEN << "\nDOUBLES " << NORMAL << std::endl;
	const double doubles[] = {0.42, 4.20, 42.42, -42, 420.42};
	iter(doubles, 5, printItems);

	return (0);
}
