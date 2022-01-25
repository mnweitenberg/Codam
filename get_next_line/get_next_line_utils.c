#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strcpy(char *dst, const char *src)
{
	int	i;

	if (dst == src)
		return (dst);
	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
	return (dst);
}

char	*merge_strings(char *s1, char *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	size_t	tot_len;
	char	*output;

	if (!s1 && !s2)
		return (0);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	tot_len = s1_len + s2_len;
	output = (char *)malloc(sizeof(char) * (tot_len + 1));
	if (!output)
		return (0);
	if (!s1)
	{		
		ft_strcpy(output, s2);
		return (output);
	}
	ft_strcpy(output, s1);
	ft_strcpy(&output[s1_len], s2);
	free(s1);
	return (output);
}

int	str_contains_no_linebreak(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (1);
	while (str[i])
	{
		if (str[i] == '\n')
			return (0);
		i++;
	}
	return (1);
}

int	there_is_a_newline_within_backupstring(char *str)
{
	if (!str)
		return (0);
	while (*str)
	{
		if (*str++ == '\n')
			return (1);
	}
	return (0);
}
