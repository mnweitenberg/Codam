#ifndef SED_HPP
# define SED_HPP

# include <iostream>
# include <fstream>
# include <sstream>

class Sed
{
	public:
		Sed(std::string file);
		~Sed(void);

		void replace(std::string s1, std::string s2);

	private:
		std::string _file;
		std::string replaceString(std::string line, std::string s1, std::string s2);
};

#endif