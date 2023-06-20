# include "RPN.hpp"
# include <iostream>
# include <fstream>
# include <string>
# include <sstream>

#define NORMAL	"\033[00m"
#define RED 	"\033[31m"
#define GREEN 	"\033[32m"
#define BLUE	"\033[0;34m"

// CONSTRUCTOR
RPN::RPN() { }

// DESTRUCTOR
RPN::~RPN() { }

// STATIC FUNTIONS
static bool isValidInput(const std::string& line) {
	return line.find_first_not_of("0123456789 +-*/") == std::string::npos;
}

static float stringToFloat(std::string str) {
	std::stringstream ss(str);
	float num;
	ss >> num;
	return num;
}

static bool isNumber(const std::string& token) {
	return (token >= "0" && token <= "9");
}

// PUBLIC FUNTIONS
void RPN::calculate(std::string line) {
	if (!isValidInput(line)) {
		std::cout << RED << "Error: invalid input" << NORMAL << std::endl;
		return;
	}

	std::istringstream iss(line);
	std::string token;
	while(iss >> token) {
		if (_rpn.size() >= 2 && token == "/" && _rpn.top() == 0) {
			std::cout << RED << "Error: division by zero" << NORMAL << std::endl;
			return;
		}

		if (isNumber(token)) _rpn.push(stringToFloat(token));
		else if (_rpn.size() >= 2) _rpn.push(calculateResult(token));
		else {
			std::cout << RED << "Error: incorrect operation" << NORMAL << std::endl;
			return;
		}
	}
	if (_rpn.size() != 1) {
		std::cout << RED << "Error: incorrect operation" << NORMAL << std::endl;
		return;
	}
	std::cout << _rpn.top() << std::endl;
}

// PRIVATE FUNCTIONS
int	RPN::calculateResult(std::string token) {
	float right = _rpn.top();
	_rpn.pop();
	float left = _rpn.top();
	_rpn.pop();

	if (token == "+")	return left + right;
	if (token == "-")	return left - right;
	if (token == "*")	return left * right;
	if (token == "/")	return left / right;

	return 0;
}
