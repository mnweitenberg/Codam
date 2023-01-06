#ifndef BASE_HPP
# define BASE_HPP

# include <sstream> 

class Base
{
	public:
		virtual ~Base(void);
};

class A : public Base{};

class B : public Base{};

class C : public Base{};

#endif