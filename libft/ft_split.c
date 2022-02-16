#include "libft.h"

static char	**free_str_array(char **str_array)
{
	unsigned int	i;

	i = 0;
	while (str_array[i])
	{
		free(str_array[i]);
		i++;
	}
	free(str_array);
	return (NULL);
}

int	count_no_of_strings(char const *str, char delimiter)
{
	int		count;

	count = 0;
	while (*str)
	{
		while (*str == delimiter)
			str++;
		if (*str != delimiter && *str)
			count++;
		while (*str != delimiter && *str)
			str++;
	}
	return (count);
}

char	*allocate_space_and_copy_s(char const *src, char delimiter)
{
	int		i;
	char	*dst;

	i = 0;
	while (src[i] && src[i] != delimiter)
		i++;
	dst = (char *)malloc(sizeof(char) * (i + 1));
	if (!dst)
		return (0);
	ft_strlcpy(dst, src, i + 1);
	return (dst);
}

char	**ft_split(char const *str, char delimiter)
{
	int		i;
	int		total_no_of_strings;
	char	**str_array;

	if (!str)
		return (0);
	total_no_of_strings = count_no_of_strings(str, delimiter);
	str_array = (char **)malloc(sizeof(char *) * (total_no_of_strings + 1));
	if (!str_array)
		return (NULL);
	i = 0;
	while (i < total_no_of_strings)
	{
		while (str[0] == delimiter)
			str++;
		str_array[i] = allocate_space_and_copy_s(str, delimiter);
		if (!(str_array[i]))
		{
			free_str_array(str_array);
			return (0);
		}
		str += ft_strlen(str_array[i++]);
	}
	str_array[i] = 0;
	return (str_array);
}
