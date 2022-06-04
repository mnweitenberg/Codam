/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   unset_export_utils.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: mweitenb <mweitenb@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/31 19:10:34 by mweitenb      #+#    #+#                 */
/*   Updated: 2022/05/11 16:36:44 by mweitenb      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/executor/export_unset_exit/unset_export_utils.h"
#include "../../../inc/utils/utils.h"
#include "../../../inc/utils/allocation.h"
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

char	*ft_strndup(char *str, size_t n)
{
	char	*dup_str;
	int		i;

	dup_str = ft_calloc(sizeof(char), n + 1);
	i = 0;
	while (n--)
	{
		dup_str[i] = str[i];
		i++;
	}
	return (dup_str);
}

bool	is_valid_variable_name(char *name)
{
	int		i;
	int		pos_of_equal;
	char	*s;
	int		return_value;

	pos_of_equal = position_of_char_within_str('=', name);
	if (pos_of_equal == -1)
		return (true);
	return_value = true;
	s = ft_strndup(name, pos_of_equal);
	if (s[0] < 'A' || (s[0] > 'Z' && s[0] < 'a' && s[0] != '_') || s[0] > 'z')
		return_value = false;
	i = 1;
	while (s[i])
	{
		if (s[i] < '0' || (s[i] > '9' && s[i] < 'A' && s[i] != '=')
			|| (s[i] > 'Z' && s[i] < 'a' && s[i] != '_') || s[i] > 'z')
		{
			return_value = false;
			break ;
		}
		i++;
	}
	free(s);
	return (return_value);
}

void	unset_variable_name_check_print(t_cmd *commands)
{
	int	i;

	i = 1;
	while (commands->command[i])
	{
		if (!is_valid_variable_name(commands->command[i]))
		{
			printf("unset: %s: not a valid identifier\n", \
				commands->command[i]);
		}
		i++;
	}
}
