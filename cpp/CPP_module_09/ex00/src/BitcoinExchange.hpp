#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <string>
# include <map>

class BitcoinExchange
{
	public:
		BitcoinExchange(std::string filename);
		~BitcoinExchange();

		void getBitcoinPrice(std::string line);

	private:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& src);
		BitcoinExchange& operator=(const BitcoinExchange& src);

		std::map<std::string, float> _prices;

		float stringToFloat(std::string str);
		bool checkValidInput(std::string line, std::string date, float value);
};

#endif
