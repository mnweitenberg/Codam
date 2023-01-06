#include "../inc/main.hpp"
#include "../inc/Sed.hpp"
#include <iostream>

int main (int argc, char **argv) {
	if (argc != 4)
		std::cout	<< "Please provide 3 arguments, in the following order:\n"
					<< "<filename> <string to replace> <replacement string>" << std::endl;
	else {
		Sed	file(argv[1]);
		try {
			file.replace(argv[2], argv[3]);
		}
		catch(char const *e) {
			std::cerr << "error: " << e << std::endl;		
		}
	}
	return (0);
}
