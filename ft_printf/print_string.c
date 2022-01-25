/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_string.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mweitenb <mweitenb@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/16 19:41:40 by mweitenb      #+#    #+#                 */
/*   Updated: 2022/01/24 12:12:36 by mweitenb      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_padding_and_str(t_flags *f, const char *value, int size)
{
	if (f->justification == 'R')
		write_padding(f->padding_character, f->width - size);
	write(1, value, size);
	if (f->justification == 'L')
		write_padding(' ', f->width - size);
	if (f->width > size)
		return (f->width);
	return (size);
}

int	print_chr(t_flags *f, int value)
{
	char	c;

	c = value;
	return (print_padding_and_str(f, &c, 1));
}

int	print_str(t_flags *f, const char *value)
{
	int	size;

	if (value == NULL)
		value = "(null)";
	size = ft_strlen(value);
	if (f->precision >= 0 && f->precision < size)
		size = f->precision;
	return (print_padding_and_str(f, value, size));
}
