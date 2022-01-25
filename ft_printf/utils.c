/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mweitenb <mweitenb@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/16 19:41:00 by mweitenb      #+#    #+#                 */
/*   Updated: 2022/01/24 12:12:39 by mweitenb      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	write_padding(char c, int size)
{
	int		i;

	i = 0;
	while (i < size)
	{
		write(1, &c, 1);
		i += 1;
	}
	return (i);
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
