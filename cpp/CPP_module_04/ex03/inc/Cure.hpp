#ifndef CURE_HPP
# define CURE_HPP

# include "../inc/AMateria.hpp"

class Cure: public AMateria
{
	public:
		Cure(void);
		Cure(const Cure &src);
		virtual ~Cure(void);
		Cure &operator = (const Cure &src);

		Cure	*clone() const;
		void	use(ICharacter &target);
};

#endif