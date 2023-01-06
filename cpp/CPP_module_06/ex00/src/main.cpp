#include "../inc/main.hpp"
#include "../inc/identify.hpp"
#include "../inc/Convert.hpp"
#include <iostream>
#include <sstream> 
#include <cstdlib>
#include <string>

int main(int argc, char **argv) {
	if (argc != 2) {
		std::cout << "Provide a char, int, float or double as input" << std::endl;
		return (EXIT_SUCCESS);
	}
	std::string input = static_cast<std::string>(argv[1]);
	if (isInfOrNan(input))
		Convert convert(input);
	else if (isInt(input))
		Convert convert(std::stoi(input));
	else if (isChar(input))
		Convert convert(input[0]);
	else if (isFloat(input))
		Convert convert(std::stof(input));
	else if (isDouble(input))
		Convert convert(std::stod(input));
	else
		std::cout << "Error: unvalid input" << std::endl;
	return (EXIT_SUCCESS);
}
