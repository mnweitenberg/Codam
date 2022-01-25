/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mweitenb <mweitenb@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/16 19:41:47 by mweitenb      #+#    #+#                 */
/*   Updated: 2022/01/24 15:11:31 by mweitenb      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

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
void	capture_flags_etc(t_flags *flags, const char **fmt, va_list args);

//	print_string.c
int		print_chr(t_flags *flags, int value);
int		print_str(t_flags *flags, const char *value);

//	print_integer.c
int		print_int(t_flags *flags, int value);
int		print_hex(t_flags *flags, size_t value);

//	utils.c
int		ft_strlen(const char *str);
int		write_padding(char ch, int size);
int		ft_atoi(const char **str);

#endif
