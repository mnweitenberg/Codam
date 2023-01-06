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

// void organize_str_for_print(std::string str){
// 	if (str.length() <= 10){
// 		std::cout << std::right << std::setw(10) << str << "|";
// 	}
// 	else{
// 		for (int it = 0; it < 9; it++){
// 			std::cout << str[it];
// 		}
// 		std::cout << "." << "|";
// 	}
// }

// void PhoneBook::printOptions(){
	
// 	int index = this->it;
// 	if (index >= 8)
// 		index = 8;

// 	std::cout << std::right << std::setw(10) << "Index" << "|";
// 	std::cout << std::right << std::setw(10) << "FirstName" << "|";
// 	std::cout << std::right << std::setw(10) << "LastName" << "|";
// 	std::cout << std::right << std::setw(10) << "NickName" << "|";
// 	std::cout << std::endl << std::endl;

// 	for (int i = 0; i < index; i++){
// 		std::cout << std::right << std::setw(10) << i << "|";
// 		organize_str_for_print(this->contacts[i].getContactLine(FIRST_NAME));
// 		organize_str_for_print(this->contacts[i].getContactLine(LAST_NAME));
// 		organize_str_for_print(this->contacts[i].getContactLine(NICKNAME));
// 		std::cout << std::endl;
// 	}
// }


// void print_found_contact(Contact current){

// 	std::cout << std::endl <<  "---------------------------------------------" << std::endl;
// 	std::cout << "CONTACT" << std::endl;
// 	std::cout << "first name:      " << current.getContactLine(FIRST_NAME) << std::endl;
// 	std::cout << "last name:       " << current.getContactLine(LAST_NAME) << std::endl;
// 	std::cout << "nickname:        " << current.getContactLine(NICKNAME) << std::endl;
// 	std::cout << "phone number:    " << current.getContactLine(PHONE_NUMBR) << std::endl;
// 	std::cout << "darkest secret..." << std::endl << "between us its creepy to collect such data but here we are: "<< std::endl;
// 	std::cout << "                 " << current.getContactLine(SECRET) << std::endl;
// 	std::cout << std::endl <<  "---------------------------------------------" << std::endl;
// }

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
