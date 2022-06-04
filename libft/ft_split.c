#include <stdlib.h>

static int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = ft_strlen(src);
	if (!size)
		return (i);
	while (*src && size--)
		*dst++ = *src++;
	*dst = 0;
	return (i);
}

static char	**ft_free_malloc(char **ptr)
{
	unsigned int	i;

	i = 0;
	while (ptr[i])
	{
		free(ptr[i]);
		i++;
	}
	free(ptr);
	return (NULL);
}

int	count_no_of_strings(char const *str, char delimiter)
{
	int	count;

	count = 0;
	while (*str)
	{
		while (*str && *str == delimiter)
			str++;
		if (*str && *str != delimiter)
			count++;
		while (*str && *str != delimiter)
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
		return (NULL);
	ft_strlcpy(dst, src, i);
	return (dst);
}

char	**ft_split(char const *str, char delimiter)
{
	int		i;
	int		total_no_of_strings;
	char	**str_array;

	if (!str)
		return (NULL);
	total_no_of_strings = count_no_of_strings(str, delimiter);
	str_array = (char **)malloc(sizeof(char *) * (total_no_of_strings + 1));
	if (!str_array)
		return (NULL);
	i = 0;
	while (i < total_no_of_strings)
	{
		while (*str == delimiter)
			str++;
		str_array[i] = allocate_space_and_copy_s(str, delimiter);
		if (!(str_array[i]))
		{
			ft_free_malloc(str_array);
			return (0);
		}
		str += ft_strlen(str_array[i++]);
	}
	str_array[i] = NULL;
	return (str_array);
}
