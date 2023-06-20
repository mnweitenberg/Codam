#include "RPN.hpp"
#include <iostream>
#include <stack>
#include <string>

#define NORMAL	"\033[00m"
#define RED 	"\033[31m"
#define GREEN 	"\033[32m"
#define BLUE	"\033[0;34m"

int main(int argc, char **argv) {

	if (argc != 2) {
		std::cout << RED << "Usage: ./RPM \"<operations>\"" << NORMAL << std::endl;
		return 1;
	}

	if (argv[1][0] == '\0') {
		std::cout << RED << "Error: operations are empty" << NORMAL << std::endl;
		return 1;
	}

	RPN rpn;
	rpn.calculate(argv[1]);

	return 0;
}
