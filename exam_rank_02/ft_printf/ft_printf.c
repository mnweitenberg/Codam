#include <unistd.h>
#include <stdarg.h>

typedef struct s_flags
{
	int	min_width;
	int	precision;
	int specifier;
}	t_flags;

int	ft_strlen(const char *str)
{
	int i = 0;
	while (str[i])
		i++;
	return (i);
}

int ft_max(int a, int b)
{
	if (a > b) 
		return a;
	return b;
}

int	ft_atoi(const char **str)
{
	int number = 0;
	int polarity = 1;

	while (**str == ' ')
		*str += 1;

	if (**str == '-')
		polarity = -1;
	if (**str == '-'|| **str== '+')
		*str += 1;

	while (**str >= '0' && **str <= '9') {
		number *= 10;
		number += **str - '0';
		*str += 1;
	}

	return (number * polarity);
}

void	write_padding(char c, int size)
{
	while (size-- > 0)
		write(1, &c, 1);
}

int print_str(t_flags *f, char *str)
{
	if (str == NULL)
		str = "(null)";

	int size = ft_strlen(str);
	if (f->precision >= 0 && f->precision < size)
		size = f->precision;

	write_padding(' ', f->min_width - size);
	write(1, str, size);

	return (ft_max(f->min_width, size));
}

void convert_base(char **int_as_str, long value, char *charachters, int base)
{
	**int_as_str = 0;
	while (value > 0) {
		*int_as_str -= 1;
		**int_as_str = charachters[value % base];
		value /= base;
	}
}

void convert_int_to_str(char specifier, char **int_as_str, long value)
{
	if (specifier == 'x')
		convert_base(int_as_str, value, "0123456789abcdef", 16);
	else if (value < 0)
		convert_base(int_as_str, -value, "0123456789", 10);
	else
		convert_base(int_as_str, value, "0123456789", 10);
}

int print_int(t_flags *f, long value)
{
	char buffer[20];
	char *int_as_str = buffer + 19;

	convert_int_to_str(f->specifier, &int_as_str, value);

	if (f->precision < 0)
		f->precision = 1;
	int size = ft_strlen(int_as_str);
	int size_plus_precision = ft_max(size, f->precision);

	if (value < 0) {
		size_plus_precision++;
		write_padding(' ', f->min_width - size_plus_precision);
		write(1, "-", 1);
	}
	else
		write_padding(' ', f->min_width - size_plus_precision);

	write_padding('0', f->precision - size);
	write(1, int_as_str, size);

	return (ft_max(f->min_width, size_plus_precision));
}

int	print_str_until_conversion(const char *str)
{
	int i = 0;
	while (str[i] && str[i] != '%')
		i++;
	write(1, str, i);
	return (i);
}

void	capture_flags(t_flags *f, const char **input, va_list args)
{
	f->min_width = ft_atoi(input);
	f->precision = -1;

	if (**input == '.') {
		*input += 1;
		if (**input == '*') {
			*input += 1;
			f->precision = va_arg(args, int);
		}
		else
			f->precision = ft_atoi(input);
	}

	f->specifier = **input;
	*input += 1;
}

int	print_conversion(t_flags *f, va_list args)
{
	if (f->specifier == 's') return(print_str(f, va_arg(args, char *)));
	if (f->specifier == 'd') return(print_int(f, va_arg(args, int)));
	if (f->specifier == 'x') return(print_int(f, va_arg(args, unsigned int)));
	return (0);
}

int ft_printf(const char *input, ... )
{
	t_flags	f;
	va_list	args;
	int		size= 0;
	int		i;
	va_start(args, input);

	while (1) {
		i = print_str_until_conversion(input);
		size += i;
		if (!input[i])
			break ;
		input += i + 1;
		capture_flags(&f, &input, args);
		size += print_conversion(&f, args);
	}

	va_end(args);
	return (size);
}
