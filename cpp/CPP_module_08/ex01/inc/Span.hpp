#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
# include <iostream>
# include <exception>

class Span
{
	public:
		Span(unsigned int n);
		Span(const Span &src);
		~Span();
		Span &operator=(const Span &src);

		// public methods
		unsigned int	shortestSpan();
		unsigned int	longestSpan();
		void			addNumber(int n);
		void			addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end);
		void			printVector();

		// exceptions
		class noSpan: public std::exception {
			const char *what() const throw() { return ("Span::exception: no span is found"); };
		};
		class fullStorage: public std::exception {
			const char *what() const throw() { return ("Span::exception: storage is full"); };
		};
		class rangeTooBig: public std::exception {
			const char *what() const throw() { return ("Span::exception: range is too large to store"); };
		};
	
	private:
		std::vector<int> _vector;
		unsigned int	_size;
};

#endif
