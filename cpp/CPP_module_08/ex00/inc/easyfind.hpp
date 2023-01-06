#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>
# include <exception>

template<typename T> typename T::iterator easyfind(T &type, int value)
{
	typename T::iterator returnValue = std::find(type.begin(), type.end(), value);

	if (returnValue == type.end())
		throw (std::exception());
	return (returnValue);
}

#endif