/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   unset.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: marvin <marvin@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/11 14:59:53 by mweitenb      #+#    #+#                 */
/*   Updated: 2022/05/11 13:34:50 by mweitenb      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "../../../inc/utils/str_compare.h"
#include "../../../inc/utils/utils.h"
#include "../../../inc/env/env_utils.h"
#include "../../../inc/parser/parser.h"
#include "../../../inc/executor/export_unset_exit/unset_export_utils.h"

static void	delete_entry(t_env_var *remove)
{
	if (remove->name)
		free(remove->name);
	if (remove->value)
		free(remove->value);
	free(remove);
}

static void	remove_env_entry(t_env_var *remove, t_env *env)
{
	t_env_var	*check;

	check = env->first;
	if (remove == check)
	{
		env->first = check->next;
		delete_entry(remove);
	}
	while (check->next)
	{
		if (remove == check->next)
		{
			if (env->last == check->next)
			{
				env->last = check;
				check->next = NULL;
			}
			else
				check->next = check->next->next;
			delete_entry(remove);
			return ;
		}
		check = check->next;
	}
}

static t_env_var	*do_lookup_export(char *name, t_env *env)
{
	t_env_var	*var;

	if (!name || !env || !env->export)
		return (NULL);
	var = env->export;
	while (var)
	{
		if (ft_strncmp(var->name, name,
				ft_max(ft_strlen(var->name), ft_strlen(name))) == 0)
			return (var);
		var = var->next;
	}
	return (NULL);
}

static void	remove_export_entry(t_env_var *remove, t_env *env)
{
	t_env_var	*check;

	if (remove == env->export)
	{
		env->export = env->export->next;
		delete_entry(remove);
		return ;
	}
	check = env->export;
	while (check->next)
	{
		if (remove == check->next)
		{
			check->next = check->next->next;
			delete_entry(remove);
			return ;
		}
		check = check->next;
	}
}

bool	ft_unset(t_env *env, t_cmd *commands)
{
	t_env_var	*check_entry;
	int			i;

	if (commands->no_of_arguments < 2)
		return (false);
	i = 1;
	unset_variable_name_check_print(commands);
	while (commands->command[i])
	{
		if (is_valid_variable_name(commands->command[i]))
		{
			check_entry = do_lookup(commands->command[i], env);
			if (check_entry)
				remove_env_entry(check_entry, env);
			check_entry = do_lookup_export(commands->command[i], env);
			if (check_entry)
				remove_export_entry(check_entry, env);
		}
		i++;
	}
	return (true);
}
