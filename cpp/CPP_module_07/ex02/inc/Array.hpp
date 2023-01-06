#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <cstddef>
# include <iostream>
# include <exception>

template<typename T>
class Array
{
	public:
		Array(void) : _array(NULL), _len(0) { }
		Array(const unsigned int n) : _array(new T[n]), _len(n) {}
		Array(const Array<T> &src) : _array(NULL), _len(0) { *this = src; }
		~Array() { delete [] _array; }

		// overload operators
		Array<T>	&operator=(const Array<T> &src) {
			if (this != &src) {
				if (_len > 0)
					delete [] _array;
				_len = src._len;
				_array = new T[src._len];
				for (unsigned int i = 0; i < _len; i++)
					_array[i] = src._array[i];
			}
			return (*this);
		}

		T &operator[] (const int index) const {
			if (index < 0 || static_cast<unsigned int>(index) >= this->_len)
				throw IndexOutOfBounds();
			return (this->_array[index]);
		}

		// getter
		size_t	size(void) const { return (this->_len); }

		// exceptions
		class IndexOutOfBounds: public std::exception {
			const char *what() const throw() { return ("Array::exception: index is out of bounds"); };
		};
	
	private:
		T*		_array;
		size_t	_len;
};

#endif
