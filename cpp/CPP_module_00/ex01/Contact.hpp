#ifndef CONTACT_H
# define CONTACT_H

# include <string>
# include <iostream>
# include <string>
# include "Contact.hpp"

class Contact
{
	public:
		void	setFirstName(std::string FirstName);
		void	setLastName(std::string LastName);
		void	setNickName(std::string NickName);
		void	setPhoneNumber(std::string PhoneNumber);
		void	setDarkestSecret(std::string DarkestSecret);

		std::string	getFirstName() const;
		std::string	getLastName() const;
		std::string	getNickName() const;

		void	printContact(void) const;

	private:
		std::string _FirstName;
		std::string _LastName;
		std::string _NickName;
		std::string _PhoneNumber;
		std::string _DarkestSecret;
};

#endif