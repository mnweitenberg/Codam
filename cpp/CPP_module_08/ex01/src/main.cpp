#include "../inc/Span.hpp"
#include <ctime>
#include <stdlib.h>

#define GREEN "\e[32m"
#define NORMAL "\e[00m"

// https://en.cppreference.com/w/cpp/container
void	testRange(unsigned int value, bool printList) {
	std::cout << GREEN << "\nTEST RANGE " << value << NORMAL << std::endl;

	std::vector<int> vec;
	for (unsigned int i = 0; i < value; i++) {
		vec.push_back(rand() % value);
	}

	Span sp = Span(value);
	sp.addRange(vec.begin(), vec.end());

	if (printList)
		sp.printVector();
	std::cout << "shortest span = " << sp.shortestSpan()	<< std::endl;
	std::cout << "longest span  = " << sp.longestSpan()		<< std::endl;
}

void	testExeptions() {
	std::cout << GREEN << "\nTEST EXECPTIONS " << NORMAL << std::endl;
	// Storage is full
	try {
		Span sp = Span(0);
		sp.addNumber(1);
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	// No Span is found
	try {
		Span sp = Span(10);
		sp.shortestSpan();
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	// No Span is found
	try {
		Span sp = Span(10);
		sp.addNumber(1);
		sp.longestSpan();
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	// Range too big
	try {
		Span sp = Span(10);
		std::vector<int> vec;
		for (unsigned int i = 0; i < 100; i++) {
			vec.push_back(rand() % (100 * 10));
		}
		sp.addRange(vec.begin(), vec.end());
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}

int main(void)
{
	srand(time(NULL));

	testExeptions();
	testRange(10, true);
	testRange(25, true);
	testRange(100, false);
	testRange(10000, false);
	return 0;
}
