#include "libft.h"

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

int	count_no_of_strings(char const *s, char c)
{
	int		count;

	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s != c && *s)
			count++;
		while (*s != c && *s)
			s++;
	}
	return (count);
}

char	*allocate_space_and_copy_s(char const *s, char c)
{
	int		i;
	char	*ptr;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	ptr = (char *)malloc(sizeof(char) * (i + 1));
	if (!ptr)
		return (0);
	ft_strlcpy(ptr, s, i + 1);
	return (ptr);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		total_no_of_strings;
	char	**ptr;

	if (!s)
		return (0);
	total_no_of_strings = count_no_of_strings(s, c);
	ptr = (char **)malloc(sizeof(char *) * (total_no_of_strings + 1));
	if (!ptr)
		return (0);
	i = 0;
	while (i < total_no_of_strings)
	{
		while (s[0] == c)
			s++;
		ptr[i] = allocate_space_and_copy_s(s, c);
		if (!(ptr[i]))
		{
			ft_free_malloc(ptr);
			return (0);
		}
		s = s + ft_strlen(ptr[i++]);
	}
	ptr[i] = 0;
	return (ptr);
}
