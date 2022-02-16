#include "ft_printf.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	write_padding(char c, int size)
{
	while (size-- > 0)
		write(1, &c, 1);
}

static int	is_space(char c)
{
	if (c == ' ' || c == '\t' || c == '\n'
		|| c == '\v' || c == '\f' || c == '\r')
		return (1);
	return (0);
}

int	ft_atoi(const char **str)
{
	int	polarity;
	int	nbr;

	polarity = 1;
	nbr = 0;
	while (is_space(**str))
		*str += 1;
	if (**str == '-')
		polarity *= -1;
	if (**str == '+' || **str == '-')
		*str += 1;
	while (**str >= '0' && **str <= '9')
	{
		nbr *= 10;
		nbr += **str - '0';
		*str += 1;
	}
	nbr *= polarity;
	return (nbr);
}
