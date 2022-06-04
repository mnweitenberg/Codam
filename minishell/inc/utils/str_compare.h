/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   str_compare.h                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: marvin <marvin@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/11 14:58:59 by mweitenb      #+#    #+#                 */
/*   Updated: 2022/05/11 16:35:36 by mweitenb      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef STR_COMPARE_H
# define STR_COMPARE_H

# include <stdlib.h>

int		ft_strcmp(const char *s1, const char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strchr(const char *s, int c);
int		is_space(char c);
int		is_operator(char c);

#endif
