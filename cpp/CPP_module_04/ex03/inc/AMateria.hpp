#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include "../inc/ICharacter.hpp"
# include <sstream> 

class ICharacter;

class AMateria
{
	public:
		AMateria(void);
		AMateria(std::string const &type);
		AMateria(const AMateria &src);
		virtual ~AMateria(void);
		AMateria &operator = (const AMateria &src);

		std::string const &getType() const;
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);

	protected:
		std::string	_type;
};

#endif