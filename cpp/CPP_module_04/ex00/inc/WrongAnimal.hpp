#ifndef WRONG_WrongAnimal_HPP
# define WRONG_WrongAnimal_HPP

# include <sstream> 

class WrongAnimal
{
	public:
		WrongAnimal(void);
		WrongAnimal(const WrongAnimal &src);
		~WrongAnimal(void);
		WrongAnimal &operator = (const WrongAnimal &src);

		std::string getType(void) const;
		void makeSound(void) const;

	protected:
		std::string	_type;
};

#endif