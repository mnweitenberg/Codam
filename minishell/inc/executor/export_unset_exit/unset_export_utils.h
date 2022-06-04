/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   unset_export_utils.h                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: mweitenb <mweitenb@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/31 19:09:52 by mweitenb      #+#    #+#                 */
/*   Updated: 2022/05/11 14:48:44 by mweitenb      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef UNSET_EXPORT_UTILS_H
# define UNSET_EXPORT_UTILS_H

# include <stdlib.h>
# include <stdbool.h>
# include "../../../inc/parser/parser.h"

char	*ft_strndup(char *str, size_t n);
bool	is_valid_variable_name(char *s);
void	unset_variable_name_check_print(t_cmd *commands);

#endif