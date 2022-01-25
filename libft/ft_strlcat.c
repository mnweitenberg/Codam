#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	j;
	size_t	dst_len;
	size_t	src_len;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	j = size - dst_len;
	if (!size || dst_len >= size)
		return (size + src_len);
	while (*dst)
		dst++;
	while (*src && j-- > 1)
		*dst++ = *src++;
	*dst = '\0';
	if (size > dst_len)
		return (dst_len + src_len);
	return (size + src_len);
}
