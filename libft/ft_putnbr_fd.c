#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int		i;
	long	nbr;
	char	c[10];

	nbr = (long)n;
	if (fd < 0)
		return ;
	if (nbr == 0)
		ft_putchar_fd('0', fd);
	if (nbr < 0)
	{
		ft_putchar_fd('-', fd);
		nbr = -nbr;
	}
	i = 0;
	while (nbr > 0)
	{
		c[i] = nbr % 10 + '0';
		nbr = nbr / 10;
		i++;
	}
	i--;
	while (i >= 0)
		ft_putchar_fd(c[i--], fd);
}
