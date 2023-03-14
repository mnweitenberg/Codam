# include "PhoneBook.hpp"
# include "Contact.hpp"

/////////
// ADD //
/////////

std::string getInput(std::string field) {
	std::string	str;
	while (str == EMPTY) {
		std::cout << field << "\t: ";
		std::getline(std::cin, str);
		if (std::cin.eof()) {
			std::cout << "\n";
			return ("control D");
		}

		if (str == EMPTY)
			std::cout << field << " can't be blank" << std::endl;
	}
	return (str);
}

void PhoneBook::add() {
	static int	i = 0;

	std::cout << "\e[1;1H\e[2J";
	std::cout << "Please provide the following information" << std::endl;
	_contacts[i].setFirstName(getInput("First Name"));
	_contacts[i].setLastName(getInput("Last Name"));
	_contacts[i].setNickName(getInput("Nickname"));
	_contacts[i].setPhoneNumber(getInput("Phonenumber"));
	_contacts[i].setDarkestSecret(getInput("Darkest Secret"));
	std::cout << "\e[1;1H\e[2J";
	std::cout << "\nContact is succesfully stored" << std::endl;

	(i < SIZE - 1) ? i++ :	i = 0;
}

////////////
// SEARCH //
////////////

std::string trimName(std::string fullname) {
	int	size = (fullname.size() > COLUMN_SIZE) ? COLUMN_SIZE - 1 : COLUMN_SIZE;
	std::string name = fullname.substr(0, size);
	std::string white_space = std::string(size - name.size(), ' ');
	std::string ending = (size == COLUMN_SIZE - 1) ? "." : "";
	return std::string (white_space + name + ending);
}

void	printPhoneBook(const Contact C[SIZE]) {
	std::cout << "\e[1;1H\e[2J";
	std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
	for (int i = 0; i < SIZE; i++) {
		std::cout << "|         " << i + 1			<< "|" ;
		std::cout << trimName(C[i].getFirstName()) 	<< "|" ;
		std::cout << trimName(C[i].getLastName())	<< "|" ;
		std::cout << trimName(C[i].getNickName())	<< "|"  << std::endl;
	}
}

int strToInt(std::string str) {
	std::stringstream 	ss;
	int					num;
	if (str[1])
		return (100);
	ss << str;
	ss >> num;
	return (num);
}

void PhoneBook::search() const {
	printPhoneBook(_contacts);

 	std::string	input;
	std::cout 	<< "\nWhat contact do you want to display?\n";
	std::cout	<< "\nType the index number:\n> ";
	std::cin	>> input;
	if (std::cin.eof())
		return;
	while (strToInt(input) < 1 || strToInt(input) > SIZE) {
		std::cout << "\e[1;1H\e[2J";
		printPhoneBook(_contacts);
		std::cout << "\nPlease type an index number (1, 2, 3, 4, 5, 6, 7 or 8):\n> ";
		std::cin  >> input;
	}
	std::cout << "\e[1;1H\e[2J";
	std::cout << "You've selected contact number " << input << ":\n" << std::endl;
	_contacts[strToInt(input) - 1].printContact();
	std::cin.ignore();
}
