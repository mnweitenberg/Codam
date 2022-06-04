/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   export_unset.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mweitenb <mweitenb@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/11 13:07:06 by mweitenb      #+#    #+#                 */
/*   Updated: 2022/05/11 19:49:44 by mweitenb      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../../../inc/executor/export_unset_exit/exit.h"
#include "../../../inc/executor/export_unset_exit/unset.h"
#include "../../../inc/executor/export_unset_exit/export.h"
#include "../../../inc/utils/str_compare.h"

int	ft_export(t_env *env, t_cmd *commands)
{
	t_env_var	*print_table;

	if (commands->no_of_arguments == 1)
	{
		print_table = env->export;
		while (print_table)
		{
			if (print_table->value)
				printf("declare -x %s=\"%s\"\n",
					print_table->name, print_table->value);
			else
				printf("declare -x %s\n", print_table->name);
			print_table = print_table->next;
		}
	}
	else
		handle_export_argument(env, commands);
	return (1);
}

bool	export_unset_exit(t_env *env, t_cmd *commands)
{
	char	*command;

	if (!commands)
		return (false);
	command = commands->command[0];
	if ((ft_strncmp(command, "unset", 6) == 0) && \
			(commands->total_commands > 1))
		return (false);
	else if (ft_strncmp(command, "export", 7) == 0)
	{
		ft_export(env, commands);
		return (false);
	}
	else if (ft_strncmp(command, "unset", 6) == 0)
	{
		ft_unset(env, commands);
		return (false);
	}
	else if (ft_strncmp(command, "exit", 5) == 0)
	{
		ft_exit(env, commands);
		return (false);
	}
	return (true);
}
