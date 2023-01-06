#include "../inc/main.hpp"
#include "../inc/Harl.hpp"
#include <iostream>

int main (void) {
	Harl	Harl;

	Harl.complain("DEBUG");
	Harl.complain("INFO");
	Harl.complain("WARNING");
	Harl.complain("ERROR");
	Harl.complain("COMPLIMENT");
	Harl.complain("info");
	Harl.complain("");
	Harl.complain(" ");

	return (0);
}
