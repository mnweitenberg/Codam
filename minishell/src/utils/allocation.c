/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   allocation.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: marvin <marvin@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/11 14:54:01 by mweitenb      #+#    #+#                 */
/*   Updated: 2022/05/11 16:34:34 by mweitenb      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/utils/utils.h"
#include <stdlib.h>
#include <stdio.h>

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ptr;

	ptr = s;
	while (n-- > 0)
		ptr[n] = c;
	return (s);
}

void	*ft_calloc(size_t size, size_t count)
{
	void	*ret;

	ret = malloc(count * size);
	if (!ret)
	{
		perror("Error: malloc failure");
		exit(EXIT_FAILURE);
	}
	return (ft_memset(ret, 0, count * size));
}

char	*ft_strdup(const char *s)
{
	char	*ptr;
	int		i;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i])
		i++;
	ptr = (char *)ft_calloc((i + 1), sizeof(char));
	i = 0;
	while (s[i])
	{
		ptr[i] = s[i];
		i++;
	}
	ptr[i] = 0;
	return (ptr);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	if (!src)
		return (0);
	i = ft_strlen(src);
	if (!size)
		return (i);
	while (*src && --size)
		*dst++ = *src++;
	*dst = 0;
	return (i);
}

char	*ft_itoa(int num)
{
	char	buf[256];
	size_t	i;
	int		j;

	i = 255;
	buf[255] = '\0';
	while (1)
	{
		j = num % 10;
		i -= 1;
		buf[i] = '0' + j * (1 - (j < 0) * 2);
		num /= 10;
		if (num == 0)
			break ;
	}
	if (j < 0)
	{
		i -= 1;
		buf[i] = '-';
	}
	return (ft_strdup(buf + i));
}
