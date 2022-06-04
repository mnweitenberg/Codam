/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: marvin <marvin@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/11 14:58:59 by mweitenb      #+#    #+#                 */
/*   Updated: 2022/05/11 16:35:41 by mweitenb      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

int		ft_strlen(const char *str);
int		ft_max(int a, int b);
void	ft_putstr_fd(char *s, int fd);
int		ft_atoi(const char *str);
int		position_of_char_within_str(char c, const char *str);

#endif
