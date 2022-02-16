#include "libft.h"

static int	count_len(long n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n = -n;
		i++;
	}
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static int	ft_pow(int base, int power)
{
	int	pow;
	int	i;

	if (power >= 0)
	{
		i = 0;
		pow = 1;
		while (i++ < power)
			pow *= base;
		return (pow);
	}
	else
		return (0);
}

static int	convert_int_to_char(long nbr, int len)
{
	long	magnitude_of_nbr;

	magnitude_of_nbr = ft_pow(10, len);
	if (len)
		nbr /= magnitude_of_nbr;
	nbr = nbr % 10 + '0';
	return (nbr);
}

char	*ft_itoa(int n)
{
	char	*output;
	int		len;
	int		i;
	long	nbr;

	nbr = (long)n;
	len = count_len(nbr);
	i = 0;
	output = (char *)malloc(sizeof(char) * (len + 1));
	if (!output)
		return (0);
	if (nbr < 0)
	{
		nbr *= -1;
		output[i++] = '-';
		len--;
	}
	while (len--)
		output[i++] = convert_int_to_char(nbr, len);
	output[i] = 0;
	return (output);
}
