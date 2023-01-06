#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <sstream> 

class Animal
{
	public:
		Animal(void);							// constructor
		Animal(const Animal &src);				// copy constructor
		virtual ~Animal(void);					// destructor
		Animal &operator = (const Animal &src);	// copy assignment operator

		std::string getType(void) const;
		virtual void makeSound(void) const;

	protected:
		std::string	_type;
};

#endif