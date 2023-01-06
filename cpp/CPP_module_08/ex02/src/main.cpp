#include "../inc/MutantStack.hpp"
#include <iostream>
#include <vector>
#include <iomanip>
#include <list>
#include <algorithm>

#define NORMAL	"\e[00m"
#define RED 	"\e[31m"
#define GREEN 	"\e[32m"
#define BLUE	"\e[0;34m"

template <class M, class L, class V>
void printIt(M it, 			M ite,
			 L it_list, 	L ite_list,
			 V it_vector, 	V ite_vector) {

	while (it 		 != ite 
		&& it_list 	 != ite_list 
		&& it_vector != ite_vector) {

		std::cout << *it << "\t" << *it_list << "\t" << *it_vector << "\t";
		if (*it == *it_list && *it == *it_vector)
			std::cout << GREEN << "OK!" << NORMAL << std::endl;
		else
			std::cout << RED << "ERROR!" << NORMAL << std::endl;

		++it;
		++it_list;
		++it_vector;
	}
}

void test_iterator(MutantStack<int> mstack, std::list<int> list, std::vector<int> vector) {
	MutantStack<int>::iterator 	it = mstack.begin();
	MutantStack<int>::iterator 	ite = mstack.end();
	std::list<int>::iterator 	it_list = list.begin();
	std::list<int>::iterator 	ite_list = list.end();
	std::vector<int>::iterator 	it_vector = vector.begin();
	std::vector<int>::iterator 	ite_vector = vector.end();
	++it;
	--it;
	++it_list;
	--it_list;
	++it_vector;
	--it_vector;
	std::cout << BLUE << "Test iterator" << NORMAL << std::endl;
	printIt(it, ite, it_list, ite_list, it_vector, ite_vector);
}

void test_const_iterator(MutantStack<int> mstack, std::list<int> list, std::vector<int> vector) {
	MutantStack<int>::const_iterator 	it = mstack.begin();
	MutantStack<int>::const_iterator 	ite = mstack.end();
	std::list<int>::const_iterator 		it_list = list.begin();
	std::list<int>::const_iterator 		ite_list = list.end();
	std::vector<int>::const_iterator 	it_vector = vector.begin();
	std::vector<int>::const_iterator 	ite_vector = vector.end();
	++it;
	--it;
	++it_list;
	--it_list;
	++it_vector;
	--it_vector;
	std::cout << BLUE << "Test const_iterator" << NORMAL << std::endl;
	printIt(it, ite, it_list, ite_list, it_vector, ite_vector);
}

void test_reverse_iterator(MutantStack<int> mstack, std::list<int> list, std::vector<int> vector) {
	MutantStack<int>::reverse_iterator 	it = mstack.rbegin();
	MutantStack<int>::reverse_iterator 	ite = mstack.rend();
	std::list<int>::reverse_iterator 	it_list = list.rbegin();
	std::list<int>::reverse_iterator 	ite_list = list.rend();
	std::vector<int>::reverse_iterator 	it_vector = vector.rbegin();
	std::vector<int>::reverse_iterator 	ite_vector = vector.rend();
	++it;
	--it;
	++it_list;
	--it_list;
	++it_vector;
	--it_vector;
	std::cout << BLUE << "Test reverse_iterator" << NORMAL << std::endl;
	printIt(it, ite, it_list, ite_list, it_vector, ite_vector);
}

void test_const_reverse_iterator(MutantStack<int> mstack, std::list<int> list, std::vector<int> vector) {
	MutantStack<int>::const_reverse_iterator 	it = mstack.rbegin();
	MutantStack<int>::const_reverse_iterator 	ite = mstack.rend();
	std::list<int>::const_reverse_iterator 		it_list = list.rbegin();
	std::list<int>::const_reverse_iterator 		ite_list = list.rend();
	std::vector<int>::const_reverse_iterator 	it_vector = vector.rbegin();
	std::vector<int>::const_reverse_iterator 	ite_vector = vector.rend();
	++it;
	--it;
	++it_list;
	--it_list;
	++it_vector;
	--it_vector;
	std::cout << BLUE << "Test const_reverse_iterator" << NORMAL << std::endl;
	printIt(it, ite, it_list, ite_list, it_vector, ite_vector);
}

int main(void) {
	std::cout << GREEN << "MStack\tList\tVector" << NORMAL << std::endl;
	MutantStack<int> 	mstack;
	std::list<int> 		list;
	std::vector<int> 	vector;

	// add numbers
	mstack.push(5);
	list.push_back(5);
	vector.push_back(5);

	mstack.push(17);
	list.push_back(17);
	vector.push_back(17);

	// print top number
	std::cout << BLUE << ".top()" << NORMAL << std::endl;
	std::cout << mstack.top() << "\t" << list.back() << "\t" << *(vector.end() - 1) << std::endl;

	// remove last number
	mstack.pop();
	list.pop_back();
	vector.pop_back();

	// check size
	std::cout << BLUE << ".size()" << NORMAL << std::endl;
	std::cout << mstack.size() << "\t" << list.size() << "\t" << vector.size() << std::endl;

	// add some more numbers
	mstack.push(3);
	list.push_back(3);
	vector.push_back(3);

	mstack.push(5);
	list.push_back(5);
	vector.push_back(5);

	mstack.push(737);
	list.push_back(737);
	vector.push_back(737);

	mstack.push(0);
	list.push_back(0);
	vector.push_back(0);

	// test iteratros
	test_iterator(mstack, list, vector);
	test_const_iterator(mstack, list, vector);
	test_reverse_iterator(mstack, list, vector);
	test_const_reverse_iterator(mstack, list, vector);

	std::stack<int> s(mstack);
	return 0;
}
