#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*c_dst;
	unsigned const char	*c_src;

	c_dst = (unsigned char *)dst;
	c_src = (unsigned char *)src;
	if (!n || dst == src)
		return (dst);
	while (n--)
		*c_dst++ = *c_src++;
	return (dst);
}
