#include "get_next_line.h"

size_t  ft_strlen(const char *str)
{
    int i;

	i = 0;
    if (!str)
		return (0);
	while (str[i])
        i++;
    return (i);
}

char    *ft_strcpy(char *dst, const char *src)
{
    while (*src)
        *dst++ = *src++;
    *dst = 0;
    return (dst);
}

int str_contains_char(char *str, char c)
{
    while (*str)
    {
        if (*str++ == c)
            return (1);
    }
    return (0);
}

int	count_chars_until_linebreak_or_end_of_str(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\n' && str[i])
        i++;
	return (i + 1);
}
