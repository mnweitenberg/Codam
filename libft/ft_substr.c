#include "libft.h"

static int	ft_min(int x, int y)
{
	if (x < y)
		return (x);
	else
		return (y);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub_str;
	int		total_len;

	if (!s)
		return (0);
	if ((unsigned int)ft_strlen(s) < start)
		return (ft_strdup(""));
	total_len = ft_strlen(s + start);
	total_len = ft_min(total_len, len) + 1;
	sub_str = (char *)malloc(sizeof(char) * total_len);
	if (!sub_str)
		return (0);
	ft_strlcpy(sub_str, s + start, total_len);
	return (sub_str);
}
