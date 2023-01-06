#ifndef ICE_HPP
# define ICE_HPP

# include "../inc/AMateria.hpp"

class Ice: public AMateria
{
	public:
		Ice(void);
		Ice(const Ice &src);
		virtual ~Ice(void);
		Ice &operator = (const Ice &src);

		Ice		*clone() const;
		void	use(ICharacter &target);
};

#endif