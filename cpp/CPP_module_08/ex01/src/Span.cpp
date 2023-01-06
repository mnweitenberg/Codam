#include "../inc/Span.hpp"
#include <numeric>
#include <algorithm>
#include <climits>
#include <cstddef>
#include <ctime>

Span::Span(unsigned int n) : _size(n) { }
Span::Span(const Span &src) { *this = src; }	
Span::~Span() { }

// overload operators
Span &Span::operator=(const Span &src) {
	if (this != &src) {
		this->_vector = src._vector;
	}
	return (*this);
}

// getter

// public methods
unsigned int	Span::shortestSpan() {
	if (this->_vector.size() <= 1)
		throw noSpan();
	std::vector<int> copy = this->_vector;
	std::sort(copy.begin(), copy.end());
	std::adjacent_difference(copy.begin(), copy.end(), copy.begin());
	return(*(std::min_element(copy.begin(), copy.end())));
}

unsigned int	Span::longestSpan() {
	if (this->_vector.size() <= 1)
		throw noSpan();
	int min = *(std::min_element(this->_vector.begin(), this->_vector.end()));
	int max = *(std::max_element(this->_vector.begin(), this->_vector.end()));
	return(max - min);
}

void	Span::addNumber(int n) {
	if(this->_vector.size() >= this->_size)
		throw fullStorage();
	else
		this->_vector.push_back(n);
}

void	Span::addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
	if (this->_size < std::distance(begin, end) + this->_vector.size())
		throw rangeTooBig();
	this->_vector.insert(this->_vector.end(), begin, end);
}

void	Span::printVector() {
	if (this->_vector.size() <= 0)
		return ;
	for (unsigned int i = 0; i < _size; i++)
		std::cout << i << "\t: " << _vector[i] << std::endl;
}
