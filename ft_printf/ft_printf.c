/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mweitenb <mweitenb@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/24 12:12:21 by mweitenb      #+#    #+#                 */
/*   Updated: 2022/01/24 15:10:38 by mweitenb      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_until_conversion_sign(const char *input)
{
	int	i;

	i = 0;
	while (input[i] && input[i] != '%')
		i += 1;
	write(1, input, i);
	return (i);
}

static int	print_conversion(t_flags *f, va_list *args)
{
	if (f->specifier == 'c')
		return (print_chr(f, va_arg(*args, int)));
	if (f->specifier == 's')
		return (print_str(f, va_arg(*args, const char *)));
	if (f->specifier == '%')
		return (print_chr(f, '%'));
	if (f->specifier == 'd' || f->specifier == 'i')
		return (print_int(f, va_arg(*args, int)));
	if (f->specifier == 'u' || f->specifier == 'x' || f->specifier == 'X')
		return (print_hex(f, va_arg(*args, unsigned int)));
	if (f->specifier == 'p')
		return (print_hex(f, (size_t) va_arg(*args, void *)));
	return (0);
}

int	ft_printf(const char *input, ...)
{
	va_list	args;
	t_flags	flags;
	int		size;
	int		len_printed_str;

	va_start(args, input);
	size = 0;
	while (1)
	{
		len_printed_str = print_until_conversion_sign(input);
		size += len_printed_str;
		if (!input[len_printed_str])
			break ;
		input += len_printed_str + 1;
		capture_flags_etc(&flags, &input, args);
		size += print_conversion(&flags, &args);
	}
	va_end(args);
	return (size);
}
