#include <unistd.h>
#include "../inc/ft_printf.h"
#include "../inc/utils.h"

static void	convert_base(char **value_str, size_t value,
	char *characters, size_t base)
{
	**value_str = '\0';
	while (value > 0)
	{
		*value_str -= 1;
		**value_str = characters[value % base];
		value /= base;
	}
}

static void	convert_int_to_string(char specifier, char **int_as_str, long value)
{
	if (specifier == 'u')
		convert_base(int_as_str, value, "0123456789", 10);
	else if (specifier == 'x' || specifier == 'p')
		convert_base(int_as_str, value, "0123456789abcdef", 16);
	else if (specifier == 'X')
		convert_base(int_as_str, value, "0123456789ABCDEF", 16);
	else if (value < 0)
		convert_base(int_as_str, -value, "0123456789", 10);
	else if (value >= 0)
		convert_base(int_as_str, value, "0123456789", 10);
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

int	print_int(t_flags *f, long value)
{
	char	buffer[19];
	char	*int_as_str;

	int_as_str = buffer + 18;
	convert_int_to_string(f->specifier, &int_as_str, value);
	if (f->specifier == 'x' && f->alt && value != 0)
		return (print_padding_and_str(f, int_as_str, "0x"));
	if (f->specifier == 'X' && f->alt && value != 0)
		return (print_padding_and_str(f, int_as_str, "0X"));
	if (f->specifier == 'p')
		return (print_padding_and_str(f, int_as_str, "0x"));
	if (f->sign && value >= 0)
		return (print_padding_and_str(f, int_as_str, "+"));
	if (f->space && value >= 0)
		return (print_padding_and_str(f, int_as_str, " "));
	if (value < 0)
		return (print_padding_and_str(f, int_as_str, "-"));
	return (print_padding_and_str(f, int_as_str, ""));
}
