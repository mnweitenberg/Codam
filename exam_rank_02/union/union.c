#include <unistd.h>

int	char_is_in_str(char c, char *str, int i)
{
	while(i--)
	{
		if(c == str[i])
			return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int		i = 0;
	if (argc == 3)
	{
		char	*str_1 = argv[1];
		char	*str_2 = argv[2];
		while(str_1[i])
		{
			if (!char_is_in_str(str_1[i], str_1, i))
				write(1, &str_1[i], 1);
			i++;
		}
		int length_of_str_1 = i;
		i = 0;
		while(str_2[i])
		{
			if (!char_is_in_str(str_2[i], str_1, length_of_str_1)
				&& !char_is_in_str(str_2[i], str_2, i))
				write(1, &str_2[i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
