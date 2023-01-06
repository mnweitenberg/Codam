# include "../inc/Brain.hpp"
# include <iostream> 

// constructors/destructor
Brain::Brain(void) { std::cout << "A brain has been created" << std::endl; }
Brain::Brain(const Brain &src) { *this = src; std::cout << "A brain has been copied" << std::endl;}
Brain::~Brain() { std::cout << "A brain has been destructed" << std::endl; }

// overloaded operators
Brain &Brain::operator = (const Brain &src) {
	if (this != &src) {
		for (int i = 0; i < 100; i++) {
			this->_ideas[i] = src._ideas[i];
		}
	}
	std::cout << "A brain has been assigned" << std::endl;
	return (*this);
}

// getters/setters
void				Brain::setIdea(size_t i, std::string idea) {
	if (i < 100)
		this->_ideas[i] = idea;
}

const std::string	Brain::getIdea(size_t i) const {
	if (i < 100)
		return (this->_ideas[i]);
	else
		return (NULL);
}

const std::string*	Brain::getIdeaAddress(size_t i) const {
	if (i < 100) {
		return (&this->_ideas[i]);
	}
	return (NULL);
}
