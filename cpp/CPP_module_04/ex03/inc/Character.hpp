#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "../inc/AMateria.hpp"
# include "../inc/ICharacter.hpp"
# include <iostream>
# include <iomanip>

# define INVENTORY_SIZE 4

typedef struct s_discarded_materia t_discarded_materia;

struct s_discarded_materia
{
	AMateria			*materia;
	t_discarded_materia	*next;
};

class AMateria;

class Character : public ICharacter
{
	public:
		Character(const std::string &name);
		Character(const Character &src);
		virtual ~Character();

		Character &operator=(const Character &src);

		const std::string &getName() const;
		void equip(AMateria *m);
		void unequip(int idx);
		void use(int idx, ICharacter &target);
	
	protected:
		void				deleteList(void);
		AMateria 			*_inventory[INVENTORY_SIZE];
		std::string			_name;
		t_discarded_materia	*_headMateria;
};

#endif