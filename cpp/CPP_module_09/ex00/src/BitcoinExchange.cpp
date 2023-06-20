# include "BitcoinExchange.hpp"
# include <iostream>
# include <fstream>
# include <string>
# include <sstream>

#define NORMAL	"\033[00m"
#define RED 	"\033[31m"
#define GREEN 	"\033[32m"
#define BLUE	"\033[0;34m"

// CONSTRUCTOR
BitcoinExchange::BitcoinExchange(std::string filename) {
	std::ifstream file(filename.c_str());
	std::string delimiter = ",";
	std::string line;

	if (file.is_open()) {
		getline(file, line);
		while (getline(file, line)) {
			size_t pos = 0;
			if ((pos = line.find(delimiter)) != std::string::npos) {
				std::string date = line.substr(0, line.find(delimiter));
				float value = stringToFloat(line.substr(line.find(delimiter) + 1, line.length()));
				_prices[date] = value;
			}
		}
		file.close();
	}
	else 
		std::cout << RED << "Error: file not found" << NORMAL << std::endl;
}

// DESTRUCTOR
BitcoinExchange::~BitcoinExchange() { }

// PUBLIC FUNTIONS
void BitcoinExchange::getBitcoinPrice(std::string line) {
	if (line.length() == 0) {
		std::cout << RED << "Error: empty line" << NORMAL << std::endl;
		return;
	}

	std::string delimiter = " | ";
	std::string date = line.substr(0, line.find(delimiter));
	float value = stringToFloat(line.substr(line.find(delimiter) + delimiter.length(), line.length()));

	if (!checkValidInput(line, date, value)) return;

	std::map<std::string, float>::const_iterator it = _prices.lower_bound(date);
	if (it == _prices.end()) {
		std::cout << RED << "Error: no price found" << NORMAL << std::endl;
		return;
	}
	if (it != _prices.begin() && it->first != date) --it;

	std::cout 	<< BLUE 	<< date		<< NORMAL 	<< " => " 
				<< value 	<<  " \t= " << value * it->second << std::endl;
}

// PRIVATE FUNCTIONS
float BitcoinExchange::stringToFloat(std::string str) {
	std::stringstream ss(str);
	float num;
	ss >> num;
	return num;
}

static bool isLeapYear(int year) {
	return ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0);
}

static bool isValidDate(int year, int month, int day) {
	if (year < 2009 || year > 2023) return false;
	if (month < 1 || month > 12) return false;
	int days_in_month = 31;
	if (month == 2) days_in_month = isLeapYear(year) ? 29 : 28;
	else if (month == 4 || month == 6 || month == 9 || month == 11) 
		days_in_month = 30;
	return day >= 1 && day <= days_in_month;
}

static bool checkIfValidDate(const std::string date_str) {
	bool result;
	int year, month, day;
	if (sscanf(date_str.c_str(), "%d-%d-%d", &year, &month, &day) != 3)
		result = false;
	else if (isValidDate(year, month, day)) result = true;
	else result = false;
	return result;
}

bool BitcoinExchange::checkValidInput(std::string line, std::string date, float value) {
	std::string delimiter = " | ";

	if (line.length() == 0) {
		std::cout << RED << "Error: empty line" << NORMAL << std::endl;
		return false;
	}
	if (line.find(delimiter) == std::string::npos) {
		std::cout << RED  << "Error: bad input => " << line << NORMAL << std::endl;
		return false;
	}
	if (!checkIfValidDate(date)) {
		std::cout << RED  << "Error: bad date => " << line << NORMAL << std::endl;
		return false;
	}
	if (value <= 0) {
		std::cout << RED  << "Error: not a positive number" << NORMAL << std::endl;
		return false;
	}
	if (value >= 1000) {
		std::cout << RED  << "Error: too large a number" << NORMAL << std::endl;
		return false;
	}
	return true;
}
