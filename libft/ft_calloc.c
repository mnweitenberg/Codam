#include "libft.h"

void	*ft_calloc(int nmemb, size_t size)
{
	int	*ptr;

	ptr = (void *)malloc (nmemb * size);
	if (!ptr)
		return (0);
	ft_bzero (ptr, nmemb * size);
	return (ptr);
}
