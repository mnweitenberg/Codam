#ifndef DOG_HPP
# define DOG_HPP

# include "../inc/Animal.hpp"

class Dog: public Animal
{
	public:
		Dog(void);							// constructor
		Dog(const Dog &src);				// copy constructor
		virtual ~Dog(void);					// destructor
		Dog &operator = (const Dog &src); 	// copy assignment operator

		void makeSound(void) const;
};

#endif