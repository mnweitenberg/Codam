#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdbool.h>

typedef struct s_flags	t_flags;

struct s_flags
{
	char	justification;
	char	padding_character;
	bool	alt;
	int		space;
	int		sign;
	int		width;
	int		precision;
	char	specifier;
};

//	ft_printf.c
int		ft_printf(const char *fmt, ...);

//	parse.c
void	parse(t_flags *flags, const char **fmt, va_list args);

//	print_string.c
int		print_char(t_flags *flags, int value);
int		print_str(t_flags *flags, const char *value);

//	print_integer.c
int		print_int(t_flags *flags, long value);

//	utils.c
int		ft_strlen(const char *str);
void	write_padding(char ch, int size);
int		ft_atoi(const char **str);

#endif
