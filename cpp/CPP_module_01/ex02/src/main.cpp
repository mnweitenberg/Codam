#include "../inc/main.hpp"

int main (void) {
	std::string		string		= "HI THIS IS BRAIN";
	std::string*	stringPTR	= &string;
	std::string&	stringREF	= string;

	std::cout << "addres\t: string\t= "		<< &string 		<< std::endl;
	std::cout << "addres\t: stringPTR\t= "	<< stringPTR 	<< std::endl;
	std::cout << "addres\t: stringREF\t= "	<< &stringREF 	<< std::endl;
	std::cout << "value\t: string\t= "		<< string 		<< std::endl;
	std::cout << "value\t: stringPTR\t= "	<< *stringPTR 	<< std::endl;
	std::cout << "value\t: stringREF\t= "	<< stringREF 	<< std::endl;
	std::cout << std::endl;

	*stringPTR = "NOW WE ADJUSTED THE stringPTR";
	std::cout << "addres\t: string\t= "		<< &string 		<< std::endl;
	std::cout << "addres\t: stringPTR\t= "	<< stringPTR 	<< std::endl;
	std::cout << "addres\t: stringREF\t= "	<< &stringREF 	<< std::endl;
	std::cout << "value\t: string\t= "		<< string 		<< std::endl;
	std::cout << "value\t: stringPTR\t= "	<< *stringPTR 	<< std::endl;
	std::cout << "value\t: stringREF\t= "	<< stringREF 	<< std::endl;
	std::cout << std::endl;

	stringREF = "NOW WE ADJUSTED THE stringREF";
	std::cout << "addres\t: string\t= "		<< &string 		<< std::endl;
	std::cout << "addres\t: stringPTR\t= "	<< stringPTR 	<< std::endl;
	std::cout << "addres\t: stringREF\t= "	<< &stringREF 	<< std::endl;
	std::cout << "value\t: string\t= "		<< string 		<< std::endl;
	std::cout << "value\t: stringPTR\t= "	<< *stringPTR 	<< std::endl;
	std::cout << "value\t: stringREF\t= "	<< stringREF 	<< std::endl;
	std::cout << std::endl;
}
