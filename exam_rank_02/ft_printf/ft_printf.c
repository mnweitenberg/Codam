# include <stdarg.h>
# include <unistd.h>

typedef struct s_flags
{
	int     min_width;
	int     precision;
	char    specifier;
}   t_flags;

int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	ft_strlen(const char *str)
{
	int i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_atoi(const char **str)
{
	int polarity = 1;
	int nbr= 0;
	while (**str == ' ')
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
	return (nbr * polarity;);
}

void	write_padding(char c, int size)
{
	int	i = 0;
	while (i < size)
	{
		write(1, &c, 1);
		i++;
	}
}

int	print_str(t_flags *f, const char *str)
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

void	convert_base(char **int_as_str, size_t value, char *characters, size_t base)
{
	**int_as_str = '\0';
	while (value > 0)
	{
		*int_as_str -= 1;
		**int_as_str = characters[value % base];
		value /= base;
	}
}

void	convert_int_to_string(char specifier, char **int_as_str, long value)
{
	if (specifier == 'x')
		convert_base(int_as_str, value, "0123456789abcdef", 16);
	else if (value < 0)
		convert_base(int_as_str, (unsigned int) -value, "0123456789", 10);
	else if (value >= 0)
		convert_base(int_as_str, value, "0123456789", 10);
}

int	print_int(t_flags *f, long value)
{
	char    buffer[11];
	char    *int_as_str;
	int     str_len;
	int     str_plus_precision_zeroes;

	int_as_str = buffer + 10;
	convert_int_to_string(f->specifier, &int_as_str, value);
	if (f->precision < 0)
		f->precision = 1;
	str_len = ft_strlen(int_as_str);
	str_plus_precision_zeroes = ft_max(f->precision, str_len);
	if (value < 0)
	{
		str_plus_precision_zeroes += 1;
		write_padding(' ', f->min_width - str_plus_precision_zeroes);
		write(1, "-", 1);
	}
	else
		write_padding(' ', f->min_width - str_plus_precision_zeroes);
	write_padding('0', f->precision - str_len);
	write(1, int_as_str, str_len);
	return (ft_max(f->min_width, str_plus_precision_zeroes));
}

void	capture_flags(t_flags *f, const char **input, va_list args)
{
	f->min_width = ft_atoi(input);
	f->precision = -1;
	if (**input == '.')
	{
		*input += 1;
		if (**input == '*')
		{
			*input += 1;
			f->precision = va_arg(ap, int);
		}
		else
			f->precision = ft_atoi(input);
	}
	f->specifier = **input;
	*input += 1;
}

int	print_until_conversion_sign(const char *input)
{
	int i = 0;
	while (input[i] && input[i] != '%')
		i++;
	write(1, input, i);
	return (i);
}

int	print_conversion(t_flags *f, va_list *args)
{
	if (f->specifier == 's')
		return (print_str(f, va_arg(*args, const char *)));
	if (f->specifier == 'd')
		return (print_int(f, va_arg(*args, int)));
	if (f->specifier == 'x')
		return (print_int(f, va_arg(*args, unsigned int)));
	return (0);
}

int	ft_printf(const char *input, ...)
{
	va_list args;
	t_flags f;
	int     size = 0;
	int     i;

	va_start(args, input);
	while (1)
	{
		i = print_until_conversion_sign(input);
		size += i;
		if (!input[i])
			break ;
		input += i + 1;
		capture_flags(&f, &input, args);
		size += print_conversion(&f, &args);
	}
	va_end(args);
	return (size);
}
