static int	is_space(char c)
{
	if (c == ' ' || c == '\f' || c == '\n'
		|| c == '\r' || c == '\t' || c == '\v')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int		polarity;
	long	nbr;

	polarity = 1;
	nbr = 0;
	while (is_space(*str))
		str++;
	if (*str == '-')
		polarity *= -1;
	if (*str == '+' || *str == '-')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		nbr *= 10;
		nbr += *str++ - '0';
	}
	nbr *= polarity;
	return ((int)nbr);
}
