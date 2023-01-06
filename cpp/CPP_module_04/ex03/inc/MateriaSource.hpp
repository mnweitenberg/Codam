#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "../inc/IMateriaSource.hpp"
# include <sstream>

# define INVENTORY_SIZE 4

class MateriaSource : public IMateriaSource
{
	public:
		MateriaSource(void);
		MateriaSource(const MateriaSource &src);
		virtual ~MateriaSource(void);
		MateriaSource &operator = (const MateriaSource &src);

		void learnMateria(AMateria*);
		AMateria* createMateria(std::string const & type);

	private:
		AMateria *_inventory[INVENTORY_SIZE];
};

#endif