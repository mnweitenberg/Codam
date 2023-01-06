#include "main.hpp"
#include "Contact.hpp"
#include "PhoneBook.hpp"

static void	promptMessage() {
	std::cout << "____________________________________________\n\n";
	std::cout << "What do you want to do?\n";
	std::cout << "- ADD\t\t	to add a contact\n";
	std::cout << "- SEARCH\t	to search for a contact\n";
	std::cout << "- EXIT\t\t	to exit the program\n\n";
	std::cout << "> ";
}

int main (void) {
	PhoneBook		phonebook;
	std::string		input;

	std::cout << "\e[1;1H\e[2J";
	promptMessage();
	while (getline(std::cin, input)) {
		if (input.compare(0, input.size(), "ADD") == 0)
			phonebook.add();
		else if (input.compare(0, input.size(), "SEARCH") == 0)
			phonebook.search();
		else if (input.compare(0, input.size(), "EXIT") == 0)
			break ;
		else
			std::cout << "\e[1;1H\e[2J";
		promptMessage();
	}
	std::cout << "\e[1;1H\e[2J";
	if (std::cin.eof())
		std::cout << "You've pressed ^D\n";
	std::cout << "All records have been erased\n";
	std::cout << "Goodbye" << std::endl;
	return (0);
}
