/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   env.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mweitenb <mweitenb@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/11 13:49:14 by mweitenb      #+#    #+#                 */
/*   Updated: 2022/03/11 13:49:14 by mweitenb      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "../../inc/utils/allocation.h"
#include "../../inc/utils/utils.h"
#include "../../inc/utils/str_compare.h"

t_env_var	*do_lookup(char *name, t_env *env)
{
	t_env_var	*var;

	if (!name || !env || !env->first)
		return (NULL);
	var = env->first;
	while (var)
	{
		if (ft_strncmp(var->name, name,
				ft_max(ft_strlen(var->name), ft_strlen(name))) == 0)
			return (var);
		var = var->next;
	}
	return (NULL);
}

static void	set_value_of_env_var(t_env_var *var, char *value)
{
	if (!var)
		return ;
	if (var->value)
		free(var->value);
	if (!value)
		var->value = NULL;
	else
		var->value = ft_strdup(value);
}

void	add_var_to_env(t_env *env, char *name, char *value)
{
	t_env_var	*var;

	if (!env || !name || name[0] == '\0')
		return ;
	var = do_lookup(name, env);
	if (!var)
	{
		var = (t_env_var *)ft_calloc(sizeof(t_env_var), 1);
		var->name = ft_calloc(1, ft_strlen(name) + 1);
		ft_strlcpy(var->name, name, ft_strlen(name) + 1);
	}
	if (!env->first)
	{
		env->first = var;
		env->last = var;
	}
	else
	{
		env->last->next = var;
		env->last = var;
		env->last->next = NULL;
	}
	set_value_of_env_var(var, value);
}

char	*get_variable_from_env(t_env *env, char *name, int len)
{
	t_env_var	*var;

	var = env->first;
	while (var)
	{
		if (ft_strncmp(var->name, name,
				ft_max(ft_strlen(var->name), len)) == 0)
			break ;
		var = var->next;
	}
	if (var && var->value)
		return (var->value);
	else if (var && !var->value)
		return (ft_strdup(""));
	else
		return (NULL);
}

t_env_var	*add_to_back_of_list(t_env_var *first, t_env_var *add)
{
	t_env_var	*temp;

	temp = first;
	add->next = NULL;
	if (!first)
		return (add);
	while (temp)
	{
		if (!temp->next)
		{
			temp->next = add;
			return (first);
		}
		temp = temp->next;
	}
	return (NULL);
}
