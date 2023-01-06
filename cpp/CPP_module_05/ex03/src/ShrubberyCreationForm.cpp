# include "../inc/ShrubberyCreationForm.hpp"
# include <iostream> 
# include <fstream>

// constructors/destructor
ShrubberyCreationForm::ShrubberyCreationForm(const std::string target)
	: AForm("ShrubberyCreationForm", SIGN_SCF, EXEC_SCF), _target(target) { }
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src)
	: AForm("ShrubberyCreationForm", SIGN_SCF, EXEC_SCF), _target(src.get_target()) { }
ShrubberyCreationForm::~ShrubberyCreationForm() { }

// overloaded operators
ShrubberyCreationForm &ShrubberyCreationForm::operator = (const ShrubberyCreationForm &src) {
	(void)src; 
	return (*this);
}

// public functions
std::string	ShrubberyCreationForm::get_target() const { return (_target); }

void	ShrubberyCreationForm::execute(const Bureaucrat &bureaucrat) const {
	std::ofstream file;

	this->executeCheck(bureaucrat);
	file.open((_target + "_shrubbery").c_str());
	file << "		            .o00o.				\n";
	file << "                   o000000oo			\n";
	file << "                  00000000000o			\n";
	file << "                 00000000000000		\n";
	file << "              oooooo  00000000  o88o	\n";
	file << "           ooOOOOOOOoo  ```''  888888	\n";
	file << "         OOOOOOOOOOOO'.qQQQQq. `8888'	\n";
	file << "        oOOOOOOOOOO'.QQQQQQQQQQ/.88'	\n";
	file << "        OOOOOOOOOO'.QQQQQQQQQQ/ /q		\n";
	file << "         OOOOOOOOO QQQQQQQQQQ/ /QQ		\n";
	file << "           OOOOOOOOO `QQQQQQ/ /QQ'		\n";
	file << "             OO:F_P:O `QQQ/  /Q'		\n";
	file << "                \\.   |  // |			\n";
	file << "                d  \\ |_////			\n";
	file << "                qP| \\ _' `|Ob			\n";
	file << "                   |       |Op			\n";
	file << "                   |       |			\n";
	file << "           _       /       |			\n";
	file << "            `---__/|_\\   //|  __		\n";
	file << "                  `-'  `-'`-'-'		\n";
	file.close();

	std::cout << "Shrubbery succesfully created" << std::endl;
}