#include "PmergeMe.hpp"
#include <iostream>
#include <string>
#include <sstream>
#include <climits>

#define NORMAL	"\033[00m"
#define RED 	"\033[31m"
#define GREEN 	"\033[32m"
#define BLUE	"\033[0;34m"

#define MAX_PRINT 5

long stringToLong(std::string str) {
	std::stringstream ss(str);
	long num;
	ss >> num;
	return num;
}

template<typename T>
void printContainer(const T& container) {
	typename T::const_iterator it = container.begin();
    for(int i = 0; i < MAX_PRINT; ++i) {
		if (it == container.end()) break;
        std::cout << *it++ << "\t";
    }
	if (container.size() > MAX_PRINT) std::cout << "[...]";
    std::cout << std::endl;
}

int main(int argc, char **argv) {

	if (argc < 2) {
		std::cout << RED << "Usage: ./PmergeMe <sequence of positive integers>" << NORMAL << std::endl;
		return 1;
	}

	// CREATE LIST AND VECTOR
	std::list<int> list;
	std::vector<int> vector;
	for (int i = 1; i < argc; i++) {
		long num = stringToLong(argv[i]);
		if (num < 0) {
			std::cout << RED << "Error: negative number" << NORMAL << std::endl;
			return 1;
		}
		if (num > INT_MAX) {
			std::cout << RED << "Error: integer overflow" << NORMAL << std::endl;
			return 1;
		}
		list.push_back(num);
		vector.push_back(num);
	}

	// PRINT BEFORE AND AFTER SORT
	std::cout << BLUE << "Before\t\t: " << NORMAL;
	printContainer(list);
	std::list<int> check = list;
	check.sort();
	std::cout << BLUE << "After\t\t: " << NORMAL;
	printContainer(check);

	// SORT WITH PmergeMe
	PmergeMe pmergeMe;
	pmergeMe.sortContainer(vector);
	pmergeMe.sortContainer(list);

	// PRINT SORTED CONTAINERS
	std::cout << BLUE << "std::vector\t: " << NORMAL;
	printContainer(vector);

	std::cout << BLUE << "std::list\t: " << NORMAL;
	printContainer(list);

	return 0;
}
