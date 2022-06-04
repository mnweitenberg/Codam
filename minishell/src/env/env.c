/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   env.c                            				    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mweitenb <mweitenb@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/11 16:48:42 by mweitenb      #+#    #+#                 */
/*   Updated: 2022/03/11 16:48:42 by mweitenb      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../../inc/env/env_utils.h"
#include "../../inc/env/sort_alphabetically.h"
#include "../../inc/utils/allocation.h"
#include "../../inc/utils/str_compare.h"

extern char	**environ;

static t_env_var	*copy_env(t_env *env)
{
	t_env_var	*copy;
	t_env_var	*original;
	t_env_var	*first;

	first = NULL;
	original = env->first;
	while (original)
	{
		copy = ft_calloc(sizeof(t_env_var), 1);
		copy->name = ft_strdup(original->name);
		copy->value = ft_strdup(original->value);
		first = add_to_back_of_list(first, copy);
		original = original->next;
	}
	return (first);
}

void	init_export(t_env *env)
{
	env->export = copy_env(env);
	env->export = sort_alphabetically(env);
}

t_env	*init_env(void)
{
	t_env	*env;
	char	**env_var;
	char	*var_value;
	char	*var_name;

	env = (t_env *)ft_calloc(sizeof(t_env), 1);
	env->symbol_count = 0;
	env_var = environ;
	while (*env_var)
	{
		var_value = ft_strchr(*env_var, '=') + 1;
		env->symbol_count += 1;
		if (var_value)
		{
			var_name = ft_calloc(sizeof(char), var_value - (*env_var));
			ft_strlcpy(var_name, *env_var, var_value - (*env_var));
			add_var_to_env(env, var_name, var_value);
			free(var_name);
		}
		else
			add_var_to_env(env, var_name, NULL);
		env_var++;
	}
	return (env);
}

void	add_status_var_to_env(t_env *env, char *w_status)
{
	t_env_var	*add;
	t_env_var	*temp;

	add = do_lookup("?", env);
	if (add)
	{
		free(add->value);
		add->value = ft_strdup(w_status);
	}
	else
	{
		add = ft_calloc(1, sizeof(t_env_var));
		add->name = ft_strdup("?");
		add->value = ft_strdup(w_status);
		temp = env->first->next;
		env->first->next = add;
		add->next = temp;
	}
}

int	add_status_to_env(t_env *env, int status)
{
	char	*w_status;

	if (WIFEXITED(status))
		status = WEXITSTATUS(status);
	else if (WIFSIGNALED(status))
	{
		status = WTERMSIG(status);
		if (status == 2)
			status = 130;
		else if (status == 3)
			status = 131;
	}
	else if (WIFSTOPPED(status))
		status = WSTOPSIG(status);
	w_status = ft_itoa(status);
	add_status_var_to_env(env, w_status);
	free(w_status);
	return (status);
}
