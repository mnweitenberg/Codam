#include <unistd.h>

int char_is_in_str_2(char c, char *str)
{
	while(*str)
	{
		if (*str++ == c)
			return (1);
	}
	return (0);
}

int char_has_been_printed(char c, char *str, int len)
{
	while(len--)
	{
		if (str[len] == c)
			return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc == 3)
	{
		char *one	= argv[1];
		char *two	= argv[2];
		int			i = 0;
		while (one[i])
		{
			if (char_is_in_str_2(one[i], two)
				&& !char_has_been_printed(one[i], one, i))
				write(1, &one[i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
}
