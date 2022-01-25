/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_integer.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: marvin <marvin@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/16 19:41:44 by mweitenb      #+#    #+#                 */
/*   Updated: 2022/01/24 20:00:45 by mweitenb      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	atoi_value_into_buffer(char **buffer, size_t value,
	char *characters, size_t base)
{
	**buffer = '\0';
	while (value > 0)
	{
		*buffer -= 1;
		**buffer = characters[value % base];
		value /= base;
	}
}

static int	calculate_size(int precision, int value_size, int pre_fix_char)
{
	if (precision > value_size)
		return (precision + pre_fix_char);
	return (value_size + pre_fix_char);
}

static int	print_padding_and_str(t_flags *f,
	const char *value, const char *pre_fix_sign)
{
	int	value_size;
	int	pre_fix_size;
	int	return_value;

	value_size = ft_strlen(value);
	pre_fix_size = ft_strlen(pre_fix_sign);
	if (f->precision < 0)
		f->precision = 1;
	return_value = calculate_size(f->precision, value_size, pre_fix_size);
	if (f->padding_character == '0')
		write(1, pre_fix_sign, pre_fix_size);
	if (f->justification == 'R')
		write_padding(f->padding_character, f->width - return_value);
	if (f->padding_character == ' ')
		write(1, pre_fix_sign, pre_fix_size);
	write_padding('0', f->precision - value_size);
	write(1, value, value_size);
	if (f->justification == 'L')
		write_padding(' ', f->width - return_value);
	if (f->width > return_value)
		return (f->width);
	return (return_value);
}

int	print_int(t_flags *f, int value)
{
	char	buffer[11];
	char	*value_str;
	int		return_value;

	value_str = buffer + 10;
	if (value < 0)
		atoi_value_into_buffer(&value_str,
			(unsigned int) -value, "0123456789", 10);
	else if (value >= 0)
		atoi_value_into_buffer(&value_str, value, "0123456789", 10);
	if (f->sign && value >= 0)
		return_value = print_padding_and_str(f, value_str, "+");
	else if (f->space && value >= 0)
		return_value = print_padding_and_str(f, value_str, " ");
	else if (value < 0)
		return_value = print_padding_and_str(f, value_str, "-");
	else
		return_value = print_padding_and_str(f, value_str, "");
	return (return_value);
}

int	print_hex(t_flags *f, size_t value)
{
	char	buffer[19];
	char	*value_str;
	int		return_value;

	value_str = buffer + 18;
	if (f->specifier == 'u')
		atoi_value_into_buffer(&value_str, value, "0123456789", 10);
	if (f->specifier == 'x' || f->specifier == 'p')
		atoi_value_into_buffer(&value_str, value, "0123456789abcdef", 16);
	if (f->specifier == 'X')
		atoi_value_into_buffer(&value_str, value, "0123456789ABCDEF", 16);
	if (f->specifier == 'x' && f->alt && value != 0)
		return_value = print_padding_and_str(f, value_str, "0x");
	else if (f->specifier == 'X' && f->alt && value != 0)
		return_value = print_padding_and_str(f, value_str, "0X");
	else if (f->specifier == 'p')
		return_value = print_padding_and_str(f, value_str, "0x");
	else
		return_value = print_padding_and_str(f, value_str, "");
	return (return_value);
}
