#include "../inc/Array.hpp"
#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>

#define GREEN "\e[32m"
#define NORMAL "\e[00m"
#define MAX_VALUE 20

void	testNumbers(void) {
	// constructions without parameter
	Array<int>	empty;
	try {
		empty[0] = rand() % 1000;
	}
	catch (const std::exception &e) {
		std::cerr << e.what() << '\n';
	}

	// constructor with parameter
	Array<int>	ints(MAX_VALUE);
	for (int i = 0; i < MAX_VALUE; i++)
		ints[i] = rand() % 1000;

	// copy constructor
	std::cout << GREEN << "\ncopy constructor " << NORMAL << std::endl;
	Array<int>	copy(ints);
	for (int i = 0; i < MAX_VALUE; i++)
		std::cout << i << "\t| src: " << ints[i] << "\t| copy: " << copy[i] << std::endl;

	// modify after copy
	std::cout << GREEN << "\nmodify after copy " << NORMAL << std::endl;
	ints[0] = 42;
	copy[1] = 420;
	std::cout << "0\t| src: " << ints[0] << "\t| copy: " << copy[0] << std::endl;
	std::cout << "1\t| src: " << ints[1] << "\t| copy: " << copy[1] << std::endl;

	// modify after assignation
	std::cout << GREEN << "\nmodify after assignation " << NORMAL << std::endl;
	Array<int>	assign(MAX_VALUE);
	assign = ints;
	assign[0] = 4;
	ints[1] = 2;
	std::cout << "0\t| src: " << ints[0] << "\t| assign: " << assign[0] << std::endl;
	std::cout << "1\t| src: " << ints[1] << "\t| assign: " << assign[1] << std::endl;


	// Assignation with different size
	std::cout << GREEN << "\nAssignation with different size " << NORMAL << std::endl;
	Array<int>	intsSmall(MAX_VALUE / 2);
	for (int i = 0; i < (MAX_VALUE / 2); i++)
		intsSmall[i] = rand() % 1000;
	assign = intsSmall;
	for (int i = 0; i < (MAX_VALUE / 2); i++)
		std::cout << i << "\t| src: " << intsSmall[i] << "\t| copy: " << assign[i] << std::endl;

	// index out of range
	std::cout << GREEN << "\nindex out of range " << NORMAL << std::endl;
	try	{
		ints[-2] = 42;
	}
	catch (const std::exception &e) {
		std::cerr << e.what() << '\n';
	}

	// test for const array
	std::cout << GREEN << "\nconst array " << NORMAL << std::endl;
	const Array<int>  int_array1(5);
    for (int i = 0; i < 5; i++)
        std::cout << int_array1[i] << std::endl;

}

std::string	randomString(int size) {
	const std::string	alphaNum = "abcdefghijklmnopqrstuvwxyz";
	std::string			randomStr = "";

	for (int i = 0; i < size; i++)
		randomStr += alphaNum[std::rand() % alphaNum.size()];
	return (randomStr);
}

void	testStrings() {
	// constructions without parameter
	Array<std::string>	empty;
	try {
		empty[0] = rand() % 1000;
	}
	catch (const std::exception &e) {
		std::cerr << e.what() << '\n';
	}

	// construcition with parameter
	Array<std::string>	strings(MAX_VALUE);

	for (int i = 0; i < MAX_VALUE; i++)
		strings[i] = randomString(5);

	// copy constructor
	std::cout << GREEN << "\ncopy constructor " << NORMAL << std::endl;
	Array<std::string>	copy(strings);
	for (int i = 0; i < MAX_VALUE; i++)
		std::cout << i << "\t| src: " << strings[i] << "\t| copy: " << copy[i] << std::endl;

	// modify after copy
	std::cout << GREEN << "\nmodify after copy " << NORMAL << std::endl;
	strings[0] = "A    ";
	copy[1] = "B";
	std::cout << "0\t| src: " << strings[0] << "\t| copy: " << copy[0] << std::endl;
	std::cout << "1\t| src: " << strings[1] << "\t| copy: " << copy[1] << std::endl;

	// modify after assignation
	std::cout << GREEN << "\nmodify after assignation " << NORMAL << std::endl;
	Array<std::string>	assign(MAX_VALUE);
	assign = strings;
	assign[0] = "C";
	strings[1] = "D    ";
	std::cout << "0\t| src: " << strings[0] << "\t| assign: " << assign[0] << std::endl;
	std::cout << "1\t| src: " << strings[1] << "\t| assign: " << assign[1] << std::endl;
	
	// Assignation with different size
	std::cout << GREEN << "\nAssignation with different size " << NORMAL << std::endl;
	Array<std::string>	stringsSmall(MAX_VALUE / 2);
	for (int i = 0; i < (MAX_VALUE / 2); i++)
		stringsSmall[i] = randomString(5);
	assign = stringsSmall;
	for (int i = 0; i < (MAX_VALUE / 2); i++)
		std::cout << i << "\t| src: " << stringsSmall[i] << "\t| copy: " << assign[i] << std::endl;

	// index out of range
	std::cout << GREEN << "\nindex out of range " << NORMAL << std::endl;
	try	{
		strings[-2] = "0";
	}
	catch (const std::exception &e) {
		std::cerr << e.what() << '\n';
	}
}

int main(void) {
	srand(time(NULL));
	std::cout << GREEN << "\nINTS " << NORMAL << std::endl;
	testNumbers();

	std::cout << GREEN << "\nSTRINGS " << NORMAL << std::endl;
	testStrings();

	return (0);
}
