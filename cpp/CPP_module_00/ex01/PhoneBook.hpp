#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <sstream> 
# include "Contact.hpp"

# define COLUMN_SIZE 10
# define SIZE 8
# define EMPTY ""

class PhoneBook
{
	public:
		void	add();
		void	search() const;

	private:
		Contact _contacts[SIZE];
};

#endif