#include <stdarg.h>
#include "../inc/ft_printf.h"
#include "../inc/utils.h"

static void	capture_flags(const char **input, t_flags *f)
{
	f->justification = 'R';
	f->padding_character = ' ';
	f->alt = false;
	f->space = 0;
	f->sign = 0;
	while (1)
	{
		if (**input == '-')
			f->justification = 'L';
		else if (**input == '+')
			f->sign = '+';
		else if (**input == ' ')
			f->space = ' ';
		else if (**input == '0')
			f->padding_character = '0';
		else if (**input == '#')
			f->alt = true;
		else
			return ;
		*input += 1;
	}
}

static void	capture_field_width(va_list args, const char **input, t_flags *f)
{
	f->width = 0;
	if (**input == '*')
	{
		*input += 1;
		f->width = va_arg(args, int);
		if (f->width < 0)
		{
			f->width *= -1;
			f->justification = 'L';
		}
	}
	else
		f->width = ft_atoi(input);
}

static void	capture_precision(va_list args, const char **input, t_flags *f)
{
	f->precision = -1;
	if (**input == '.')
	{
		*input += 1;
		if (**input == '*')
		{
			*input += 1;
			f->precision = va_arg(args, int);
		}
		else
			f->precision = ft_atoi(input);
	}
}

void	capture(t_flags *f, const char **input, va_list args)
{
	capture_flags(input, f);
	capture_field_width(args, input, f);
	capture_precision(args, input, f);
	f->specifier = **input;
	if (f->precision >= 0 && f->specifier != '%' && f->specifier != 'c'
		&& f->specifier != 's')
		f->padding_character = ' ';
	*input += 1;
}
