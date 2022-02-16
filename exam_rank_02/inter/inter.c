#include <unistd.h>

int	char_is_in_str_2(char c, char *str)
{
	while (*str)
	{
		if (*str++ == c)
			return (1);
	}
	return (0);
}

int	char_has_not_been_printed(char *str, int i)
{
	char	c = str[i];
	while(i--)
	{
		if(c == str[i])
			return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int	i = 0;
	if (argc == 3)
	{
		char *str_1 = argv[1];
		char *str_2 = argv[2];
		while(str_1[i])
		{
			if (char_is_in_str_2(str_1[i], str_2) && char_has_not_been_printed(&str_1[0], i))
				write(1, &str_1[i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
