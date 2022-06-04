/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parameter_expansion_3.h                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: marvin <marvin@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/11 14:59:53 by mweitenb      #+#    #+#                 */
/*   Updated: 2022/05/12 14:42:15 by mweitenb      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARAMETER_EXPANSION_3_H
# define PARAMETER_EXPANSION_3_H

char	*get_parameter_name(t_env *env, char *src);
void	get_symbol(char symbol[3], char *src);
char	*get_word_value(char *src);
char	*duplicate_without_ending_curly_bracket(const char *s);
int		get_length_of_var(char *str);

#endif
