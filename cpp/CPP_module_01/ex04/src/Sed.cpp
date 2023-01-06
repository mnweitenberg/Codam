#include <fstream>
#include "../inc/Sed.hpp"

Sed::Sed(std::string file) : _file(file) { }

Sed::~Sed() { }

std::string Sed::replaceString(std::string old_line, std::string s1, std::string s2) {

	int	s1_location = old_line.find(s1);
	std::string	line_until_s1 = old_line.substr(0, s1_location);
	std::string	line_after_s1 = old_line.substr(s1_location + s1.length(), old_line.length());
	if (line_after_s1.find(s1) != std::string::npos)
		line_after_s1 = replaceString(line_after_s1, s1, s2);

	std::string	new_line = line_until_s1;
	new_line += s2;
	new_line += line_after_s1;
	return (new_line);
}

void Sed::replace(std::string s1, std::string s2) {
	std::string		line;
	std::fstream	input;
	std::fstream	output;

	if (_file.length() == 0)
		throw "filename is empty.";
	else if (s1.length() == 0)
		throw "string to replace is empty.";
	else if (s2.length() == 0)
		throw "replacement string is empty.";
	input.open(_file, std::ios::in);
	output.open(_file + ".replace", std::ios::out);
   	if (input.is_open()){
		while(getline(input, line)) {
			if (line.find(s1) != std::string::npos)
				line = replaceString(line, s1, s2);
	   		output << line;
			if (!input.eof())
				output << "\n";
	  	}
	  	input.close();
	  	output.close();
   	}
	else
		throw "input file couldn't be opened.";
}
