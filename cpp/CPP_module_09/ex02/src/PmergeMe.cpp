# include "PmergeMe.hpp"
# include <iostream>
# include <fstream>
# include <sstream>

#define NORMAL	"\033[00m"
#define RED 	"\033[31m"
#define GREEN 	"\033[32m"
#define BLUE	"\033[0;34m"

// CONSTRUCTOR
PmergeMe::PmergeMe() { }

// DESTRUCTOR
PmergeMe::~PmergeMe() { }

// PUBLIC FUNTIONS
void PmergeMe::sortContainer(std::vector <int> &vector) {
	clock_t start_time = clock();
	mergeInsertionSort(vector);
	printPerformance(start_time, vector.size(), "std::vector");
}

void PmergeMe::sortContainer(std::list <int> &list) {
	clock_t start_time = clock();
	mergeInsertionSort(list);
	printPerformance(start_time, list.size(), "std::list ");
}

// PRIVATE FUNTIONS
void	PmergeMe::printPerformance(clock_t start_time, int size, std::string type) {
	clock_t end_time = clock();
	double elapsed_time = static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC;

	std::cout << "Time to procees a range of " << size << " elements with " 
				<< BLUE 	<< type << "\t: "
				<< GREEN 	<< elapsed_time * 1000 << " ms" << NORMAL << std::endl;
}

template <typename Container>
static void createChains(Container &container, Container &a, Container &b) {
	if (container.size() % 2 != 0) {
		b.push_back(container.back());
		container.pop_back();
	}
	while (container.size() >= 2) {
		int one = container.back();
		container.pop_back();
		int two = container.back();
		container.pop_back();
		if (one < two) {
			a.push_back(one);
			b.push_back(two);
		}
		else {
			a.push_back(two);
			b.push_back(one);
		}
	}
}

template <typename Container>
static void sortChains(Container &a, Container &b) {
	Container sorted_a;
	Container sorted_b;

	while (!a.empty()) {
		int a_val = a.back();
		a.pop_back();
		int b_val = b.back();
		b.pop_back();

		typename Container::iterator insertPosA = sorted_a.begin();
		typename Container::iterator insertPosB = sorted_b.begin();
		while (insertPosA != sorted_a.end() && *insertPosA < a_val) {
			++insertPosA;
			++insertPosB;
		}
		sorted_a.insert(insertPosA, a_val);
		sorted_b.insert(insertPosB, b_val);
	}
	if (!b.empty()) sorted_b.push_back(b.back());

	a.swap(sorted_a);
	b.swap(sorted_b);
}

template <typename Container>
static Container insertSortChainBintoA(Container &a, Container &b) {
	while (!b.empty()) {
		int b_val = b.back();
		b.pop_back();

		typename Container::iterator insertPos = a.begin();
		while (insertPos != a.end() && *insertPos < b_val) ++insertPos;
		a.insert(insertPos, b_val);
	}
	return a;
}

template <typename Container>
void PmergeMe::mergeInsertionSort(Container& container) {
	if (container.size() <= 1) return;
	Container a_chain;
	Container b_chain;

	createChains(container, a_chain, b_chain);
	sortChains(a_chain, b_chain);
	container = insertSortChainBintoA(a_chain, b_chain);
}
