#include <iostream>

static void	print_in_uppercase(char c) {
	if (c >= 'a' && c <= 'z')
		c += 'A' - 'a';
	std::cout << c;
}

int main (int argc, char **argv) {
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	if (argc > 1) {
		int i = 0;
		while (i++ < argc - 1) {
			int j = 0;
			while (argv[i][j])
				print_in_uppercase(argv[i][j++]);
		}
	}
	std::cout << "\n";
	return (0);
}
