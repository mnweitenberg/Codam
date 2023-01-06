#ifndef DOG_HPP
# define DOG_HPP

# include "../inc/Animal.hpp"
# include "../inc/Brain.hpp"

class Dog: public Animal
{
	public:
		Dog(void);
		Dog(const Dog &src);
		virtual ~Dog(void);
		Dog &operator = (const Dog &src);

		void	getIdeas(void) const;
		void	setIdea(std::string idea);
		void	makeSound(void) const;
	
	private:
		Brain 	*_brain;
		int		_ideaCount;
};

#endif