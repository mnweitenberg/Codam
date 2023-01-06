#ifndef WRONG_Cat_HPP
# define WRONG_Cat_HPP

# include "../inc/WrongAnimal.hpp"

class WrongCat: public WrongAnimal
{
	public:
		WrongCat(void);
		WrongCat(const WrongCat &src);
		~WrongCat(void);
		WrongCat &operator = (const WrongCat &src);

		void makeSound(void) const;
};

#endif