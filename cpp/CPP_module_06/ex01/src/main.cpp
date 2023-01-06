#include "../inc/main.hpp"
#include <iostream>
#include <string>
#include <stdint.h>

void	printUintptr(uintptr_t serialized, std::string name) {
	std::cout << "name\t\t= "		<< name << std::endl;
	std::cout << "address\t\t= "	<< &serialized << std::endl;
	std::cout << "address ptr\t= "	<< serialized << std::endl;
	std::cout << std::endl;
}

void	printData(Data *data, std::string name) {
	std::cout << "name\t\t= "		<< name << std::endl;
	std::cout << "address\t\t= "	<< &data << std::endl;
	std::cout << "address ptr\t= "	<< data << std::endl;
	std::cout << "integer\t\t= " 	<< data->integer << std::endl;
	std::cout << "name\t\t= " 	 	<< data->string << std::endl;
	std::cout << std::endl;
}

uintptr_t serialize(Data* ptr) {
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data* deserialize(uintptr_t raw) {
	return(reinterpret_cast<Data*>(raw));
}

int main(void) {
	// create and fill Data struct
	Data *original = new Data;
	original->integer = 42;
	original->string = "Codam";
	printData(original, "original");

	// serialize data
	uintptr_t serialized = serialize(original);
	printUintptr(serialized, "serialized");

	// deserialize data
	Data *deserialized = deserialize(serialized);
	printData(deserialized, "deserialized");

	// side by side comparison
	std::cout << "\t\t  original\t\t"<< "deserialized"	<< std::endl;
	std::cout << "address\t\t= "	 << &original			<< "\t" 	<< &deserialized			<< std::endl;
	std::cout << "address ptr\t= "	 << original			<< "\t" 	<< deserialized				<< std::endl;
	std::cout << "index\t\t= "		 << original->integer	<< "\t\t\t" << deserialized->integer	<< std::endl;
	std::cout << "name\t\t= "		 << original->string	<< "\t\t\t" << deserialized->string		<< std::endl;

	delete original;
	return (0);
}
