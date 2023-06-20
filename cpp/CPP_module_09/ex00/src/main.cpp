#include "BitcoinExchange.hpp"
#include <fstream>
#include <sstream>

#define NORMAL	"\033[00m"
#define RED 	"\033[31m"
#define GREEN 	"\033[32m"
#define BLUE	"\033[0;34m"

std::string printExchange(std::string filename) {
	BitcoinExchange BtcExchange("data.csv");
	std::ifstream file(filename.c_str());
	std::string line;
	std::string result;

	if (file.is_open()) {
		getline(file, line);
		while (getline(file, line)) BtcExchange.getBitcoinPrice(line);
		file.close();
	}
	else std::cout << RED << "Error: file not found" << NORMAL << std::endl;
	return result;
}

int main(int argc, char **argv) {

	if (argc != 2) {
		std::cout << RED << "Usage: ./btc <filename>" << NORMAL << std::endl;
		return 1;
	}
	if (argv[1] == NULL) {
		std::cout << RED << "Error: filename is NULL" << NORMAL << std::endl;
		return 1;
	}
	if (argv[1][0] == '\0') {
		std::cout << RED << "Error: filename is empty" << NORMAL << std::endl;
		return 1;
	}

	printExchange(argv[1]);

	return 0;
}
