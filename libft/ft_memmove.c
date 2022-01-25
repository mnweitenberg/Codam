#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char		*c_dst;
	unsigned const char	*c_src;

	if (!n || dst == src)
		return (dst);
	c_dst = (unsigned char *)dst;
	c_src = (unsigned char *)src;
	if (src < dst)
	{
		while (n--)
			c_dst[n] = c_src[n];
	}
	else
	{
		while (n--)
			*c_dst++ = *c_src++;
	}
	return (dst);
}
