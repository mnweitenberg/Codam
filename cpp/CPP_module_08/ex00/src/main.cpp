#include "../inc/easyfind.hpp"
#include <list>
#include <vector>
#include <iostream>
#include <iostream>
#include <deque>

#define GREEN "\e[32m"
#define NORMAL "\e[00m"
#define MAX_VALUE 20

template<typename T>
void test(T lst)
{
	for (int i = 0; i < 10; i++) {
		int entry = std::rand() % 10 + 40;
		lst.push_back(entry);
		std::cout << i << ": " << entry << std::endl;
	}
	int noToFind = 42;
	try	{
		std::cout << "No " << noToFind << " is at position: " <<std::distance(lst.begin(), easyfind(lst, noToFind)) << std::endl;
	}
	catch(const std::exception& e) {
		std::cerr << "value not found" << std::endl;
	}
	std::cout << std::endl;
}

int main(void)
{
	srand(time(NULL));

	std::cout << GREEN << "LIST" << NORMAL << std::endl;
	std::list<int> list;
	test(list);

	std::cout << GREEN << "DEQUE" << NORMAL << std::endl;
	std::deque<int> deque;
	test(deque);

	std::cout << GREEN << "VECTOR" << NORMAL << std::endl;
	std::vector<int> vector;
	test(vector);
	return 0;
	
}