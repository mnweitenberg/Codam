#ifndef MUTANTSTACK_CLASS_HPP
# define MUTANTSTACK_CLASS_HPP

#include <stack>
#include <deque>

template <class T, class Container = std::deque<T> >
class MutantStack : public std::stack <T, Container>
{
	public:
		MutantStack() {}
		MutantStack(const MutantStack& src) {*this = src; return ; }
		~MutantStack() {}
		MutantStack& operator=(const MutantStack& src) { this->c = src.c; return *this; }

		typedef typename		Container::iterator iterator;
		iterator				begin() { return (this->c.begin()); }
		iterator				end()   { return (this->c.end()); }

		typedef typename 		Container::const_iterator const_iterator;
		const_iterator			begin() const { return (this->c.begin()); }
		const_iterator			end()   const { return (this->c.end()); }

		typedef typename 		Container::reverse_iterator reverse_iterator;
		reverse_iterator 		rbegin() { return (this->c.rbegin()); }
		reverse_iterator 		rend()   { return (this->c.rend()); }

		typedef typename 		Container::const_reverse_iterator const_reverse_iterator;
		const_reverse_iterator	rbegin() const { return (this->c.rbegin());}
		const_reverse_iterator	rend()   const { return (this->c.rend()); }
};

#endif
