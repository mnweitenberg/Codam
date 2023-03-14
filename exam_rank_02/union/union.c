#include <unistd.h>

int char_has_been_printed(char c, char *str, int i)
{
	while (i--) {
		if (str[i] == c)
			return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc != 3) {
		write(1, "\n", 1);
		return;
	}

	char *one	= argv[1];
	char *two	= argv[2];
	int 		i = 0;
	int 		j = 0;

	while (one[i]) {
		if (!char_has_been_printed(one[i], one, i))
			write(1, &one[i], 1);
		i++;
	}

	while (two[j]) {
		if (!char_has_been_printed(two[j], one, i)
			&& !char_has_been_printed(two[j], two, j))
			write(1, &two[j], 1);
		j++;
	}

	write(1, "\n", 1);
	return (0);
}
