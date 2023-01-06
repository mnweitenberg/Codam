#include <fstream>
#include <stdlib.h>
#include "../inc/Harl.hpp"

Harl::Harl() { }

Harl::~Harl() { }

void Harl::complain(std::string level_name) const {
	s_level definitions[4] = {
		{ "DEBUG", 		&Harl::debug },
		{ "INFO", 		&Harl::info },
		{ "WARNING", 	&Harl::warning },
		{ "ERROR", 		&Harl::error }
	};
	size_t i;
	for (i = 0; i < 4; i++) {
		if (definitions[i].name == level_name)
			break ;
	}
	switch (i) {
		case 0:
			Harl::debug();
		case 1:
			Harl::info();
		case 2:
			Harl::warning();
		case 3:
		{
			Harl::error();
			break;
		}
		case 4:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
}

void Harl::debug(void) const {
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
	std::cout << std::endl;
}

void Harl::info(void) const {
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
	std::cout << std::endl;
}

void Harl::warning(void) const {
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month." << std::endl;
	std::cout << std::endl;
}

void Harl::error(void) const {
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
	std::cout << std::endl;
}
