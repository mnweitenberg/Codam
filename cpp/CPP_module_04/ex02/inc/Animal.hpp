#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <sstream> 

class Animal
{
	public:
		Animal(void);
		Animal(const Animal &src);
		virtual ~Animal(void);
		Animal &operator = (const Animal &src);

		std::string getType(void) const;
		virtual void makeSound(void) const = 0;

	protected:
		std::string	_type;
};

#endif