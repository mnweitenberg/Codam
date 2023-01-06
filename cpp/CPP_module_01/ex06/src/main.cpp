#include "../inc/main.hpp"
#include "../inc/Harl.hpp"
#include <iostream>

int main (int argc, char **argv) {
	if (argc < 2)
		return (0);

	Harl	Harl;

	Harl.complain(argv[1]);

	return (0);
}
