/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   builtin.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mweitenb <mweitenb@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/11 13:42:04 by mweitenb      #+#    #+#                 */
/*   Updated: 2022/03/25 13:13:35 by mo               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include "../../inc/executor/builtins.h"
#include "../../inc/utils/str_compare.h"

static int	ft_pwd(void)
{
	char	*path;

	path = getcwd(NULL, 0);
	printf("%s\n", path);
	free(path);
	return (1);
}

static int	ft_print_env(t_env *env)
{
	t_env_var	*var;

	var = env->first;
	while (var)
	{
		if (ft_strcmp("?", var->name) && ft_strcmp("prev?", var->name)
			&& ft_strcmp("_", var->name))
			printf("%s=%s\r\n", var->name, var->value);
		var = var->next;
	}
	return (1);
}

static int	ft_echo(t_cmd *commands)
{
	int		i;
	bool	do_newline;

	i = 1;
	do_newline = true;
	if (ft_strncmp (commands->command[1], "-n", 2) == 0)
	{
		do_newline = false;
		i++;
	}
	while (commands->command[i])
	{
		if ((i > 1 && do_newline == true) || i > 2)
			printf(" ");
		printf("%s", commands->command[i++]);
	}
	if (do_newline)
		printf("\n");
	return (1);
}

int	execute_builtins(t_env *env, t_cmd *commands)
{
	if (ft_strncmp(commands->command[0], "env", 4) == 0)
		return (ft_print_env(env));
	if (ft_strncmp(commands->command[0], "pwd", 4) == 0)
		return (ft_pwd());
	if (ft_strncmp(commands->command[0], "echo", 5) == 0)
		return (ft_echo(commands));
	return (0);
}
