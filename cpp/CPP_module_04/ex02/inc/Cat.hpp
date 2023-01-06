#ifndef CAT_HPP
# define CAT_HPP

# include "../inc/Animal.hpp"
# include "../inc/Brain.hpp"

class Cat: public Animal
{
	public:
		Cat(void);
		Cat(const Cat &src);
		virtual ~Cat(void);
		Cat &operator = (const Cat &src);

		void	getIdeas(void) const;
		void	setIdea(std::string idea);
		void	makeSound(void) const;
	
	private:
		Brain 	*_brain;
		int		_ideaCount;
};

#endif