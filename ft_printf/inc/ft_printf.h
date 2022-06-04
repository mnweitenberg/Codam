#ifndef FT_PRINTF_H
# define FT_PRINTF_H

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

int		ft_printf(const char *fmt, ...);

#endif
