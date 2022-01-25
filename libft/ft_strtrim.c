#include "libft.h"

static int	char_in_set(char c, char const *set)
{
	while (*set)
	{
		if (*set++ == c)
			return (1);
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*str;

	if (!s1 || !set)
		return (0);
	start = 0;
	while (s1[start] && char_in_set(s1[start], set))
		start++;
	end = ft_strlen(s1);
	while (end > start && char_in_set(s1[end - 1], set))
		end--;
	str = (char *)malloc(((end - start + 1) * sizeof(char)));
	if (!str)
		return (0);
	ft_strlcpy(str, &s1[start], end - start + 1);
	return (str);
}
