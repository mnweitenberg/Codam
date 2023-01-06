#include "PhoneBook.hpp"

// setters
void Contact::setFirstName(std::string FirstName) { _FirstName = FirstName; }
void Contact::setLastName(std::string LastName) { _LastName = LastName; }
void Contact::setNickName(std::string NickName) { _NickName = NickName; }
void Contact::setPhoneNumber(std::string PhoneNumber) { _PhoneNumber = PhoneNumber; }
void Contact::setDarkestSecret(std::string DarkestSecret) { _DarkestSecret = DarkestSecret; }

// getters
std::string	Contact::getFirstName(void)	const { return _FirstName; }
std::string	Contact::getLastName(void)	const { return _LastName; }
std::string	Contact::getNickName(void)	const { return _NickName; }

// public methods
void Contact::printContact(void) const {
	std::cout << "First Name\t: "		<< _FirstName 		<< std::endl;
	std::cout << "Last Name\t: "		<< _LastName 		<< std::endl;
	std::cout << "Nickname\t: "			<< _NickName 		<< std::endl;
	std::cout << "Phonenumber\t: " 		<< _PhoneNumber 	<< std::endl;
	std::cout << "Darkest Secret\t: "	<< _DarkestSecret 	<< std::endl;
}

