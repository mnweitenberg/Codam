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
	return (print_padding_and_str(f, &value, 1));
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
