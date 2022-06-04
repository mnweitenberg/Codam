/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_alphabetically.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: mweitenb <mweitenb@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/11 13:25:20 by mweitenb      #+#    #+#                 */
/*   Updated: 2022/05/11 14:46:33 by mweitenb      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/env/env.h"
#include "../../inc/utils/str_compare.h"

static void	put_last_in_first_place_check(t_env *env)
{
	t_env_var	*old_last;
	t_env_var	*new_last;

	old_last = env->export;
	while (old_last->next)
	{
		new_last = old_last;
		old_last = old_last->next;
	}
	if (ft_strcmp(old_last->name, env->export->name) < 0)
	{
		old_last->next = env->export;
		env->export = old_last;
		new_last->next = NULL;
	}
}

static t_env_var	*add_to_front_of_list(t_env_var *old_first,
	t_env_var *new_first)
{
	if (!old_first)
		new_first->next = NULL;
	else
		new_first->next = old_first;
	return (new_first);
}

t_env_var	*sort_alphabetically(t_env *env)
{
	t_env_var	*temp;
	t_env_var	*first;
	t_env_var	*compare;

	put_last_in_first_place_check(env);
	first = env->export;
	temp = first;
	while (temp->next)
	{
		compare = temp->next;
		if (ft_strcmp(temp->name, compare->name) > 0)
		{
			temp->next = compare->next;
			first = add_to_front_of_list(first, compare);
			temp = first;
			continue ;
		}
		temp = temp->next;
	}
	return (first);
}
