/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   export.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mweitenb <mweitenb@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/05 14:07:55 by mweitenb      #+#    #+#                 */
/*   Updated: 2022/05/11 14:59:47 by mweitenb      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../../../inc/env/env.h"
#include "../../../inc/env/sort_alphabetically.h"
#include "../../../inc/utils/allocation.h"
#include "../../../inc/utils/str_compare.h"
#include "../../../inc/utils/utils.h"
#include "../../../inc/env/env_utils.h"
#include "../../../inc/executor/export_unset_exit/unset_export_utils.h"

static void	create_env_var_from_export_argument(char *export_argument, \
												t_env_var *var_entry)
{
	int		pos_of_equal;
	char	*new_value;
	char	*new_name;

	pos_of_equal = position_of_char_within_str('=', export_argument);
	if (pos_of_equal < 0)
		var_entry->name = ft_strdup(export_argument);
	else
	{
		new_name = ft_strndup(export_argument, pos_of_equal);
		new_value = ft_strdup(export_argument + (pos_of_equal + 1));
		var_entry->name = ft_strdup(new_name);
		var_entry->value = ft_strdup(new_value);
		free(new_name);
		free(new_value);
	}
}

t_env_var	*export_do_lookup(char *name, t_env_var *export_var)
{
	t_env_var	*var;

	if (!export_var)
		return (NULL);
	var = export_var;
	while (var)
	{
		if (ft_strncmp(var->name, name,
				ft_max(ft_strlen(var->name), ft_strlen(name))) == 0)
			return (var);
		var = var->next;
	}
	return (NULL);
}

static void	check_add_to_export(t_env *env, t_env_var *exp_entry)
{
	t_env_var	*check_export;

	check_export = export_do_lookup(exp_entry->name, env->export);
	if (!check_export)
	{
		add_to_back_of_list(env->export, exp_entry);
		sort_alphabetically(env);
		return ;
	}
	else if (!check_export->value && exp_entry->value)
		check_export->value = ft_strdup(exp_entry->value);
	else if (ft_strcmp(check_export->value, exp_entry->value))
	{
		free(check_export->value);
		check_export->value = ft_strdup(exp_entry->value);
	}
	sort_alphabetically(env);
}

static void	check_add_to_env(t_env *env, t_env_var *exp_entry)
{
	t_env_var	*check_env;

	if (!exp_entry->value)
		return ;
	check_env = do_lookup(exp_entry->name, env);
	if (!check_env)
	{
		add_var_to_env(env, exp_entry->name, exp_entry->value);
		return ;
	}
	if (ft_strcmp(check_env->value, exp_entry->value))
	{
		free(check_env->value);
		check_env->value = ft_strdup(exp_entry->value);
	}
}

void	handle_export_argument(t_env *env, t_cmd *commands)
{
	size_t		i;
	t_env_var	*exp_entry;

	if (commands->total_commands > 1)
		return ;
	i = 1;
	while (commands->command[i])
	{
		if (!is_valid_variable_name(commands->command[i]))
		{
			printf("export: %s: not a valid identifier\n", \
				commands->command[i]);
			i++;
			continue ;
		}
		exp_entry = ft_calloc (sizeof(t_env_var), 1);
		create_env_var_from_export_argument(commands->command[i], \
		exp_entry);
		check_add_to_export(env, exp_entry);
		check_add_to_env(env, exp_entry);
		i++;
	}
}
