#include <stdlib.h>

int	ft_strlen(const char *str)
{
	int i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_strlcpy(char *dst, const char *src, int size)
{
	if (!src)
		return ;
	while (*src && size--)
		*dst++ = *src++;
	*dst = 0;
}

int	count_no_of_strings(char *str, char delimiter)
{
	int count = 0;
	while (*str) {
		while (*str && *str == delimiter)
			str += 1;
		if (*str && *str != delimiter)
			count += 1;
		while (*str && *str != delimiter)
			str += 1;
	}
	return (count);
}

char *copy_str(char *src, char delimiter)
{
	int len = 0;
	while (src[len] && src[len] != delimiter)
		len++;
	char *dst = (char *)malloc(len + 1);
	ft_strlcpy(dst, src, len);
	return (dst);
}

char **ft_split(char *str, char delimiter)
{
	if (!str)
		return (NULL);
	int i = 0;
	int no_of_strings = count_no_of_strings(str, delimiter);
	char **str_array = (char **)malloc(sizeof(char *) * (no_of_strings + 1));
	while (i < no_of_strings) {
		while (*str && *str == delimiter)
			str += 1;
		str_array[i] = copy_str(str, delimiter);
		str += ft_strlen(str_array[i]);
		i++;
	}
	str_array[i] = NULL;
	return (str_array);
}
