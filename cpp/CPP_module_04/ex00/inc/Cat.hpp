#ifndef CAT_HPP
# define CAT_HPP

# include "../inc/Animal.hpp"

class Cat: public Animal
{
	public:
		Cat(void);							// constructor
		Cat(const Cat &src);				// copy constructor
		virtual ~Cat(void);					// destructor
		Cat &operator = (const Cat &src);	// copy assignment operator

		void makeSound(void) const;
};

#endif