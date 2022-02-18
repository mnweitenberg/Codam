#include "../inc/ft_printf.h"

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
		return (print_char(f, va_arg(*args, int)));
	if (f->specifier == 's')
		return (print_str(f, va_arg(*args, const char *)));
	if (f->specifier == '%')
		return (print_char(f, '%'));
	if (f->specifier == 'd' || f->specifier == 'i')
		return (print_int(f, va_arg(*args, int)));
	if (f->specifier == 'u' || f->specifier == 'x' || f->specifier == 'X')
		return (print_int(f, va_arg(*args, unsigned int)));
	if (f->specifier == 'p')
		return (print_int(f, (size_t) va_arg(*args, void *)));
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
		parse(&flags, &input, args);
		size += print_conversion(&flags, &args);
	}
	va_end(args);
	return (size);
}
