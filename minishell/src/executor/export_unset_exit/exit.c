/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   builtins_cd.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mweitenb <mweitenb@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/31 19:19:44 by mweitenb      #+#    #+#                 */
/*   Updated: 2022/05/16 14:25:28 by mweitenb      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../../../inc/lexer/lexer.h"
#include "../../../inc/parser/parser.h"
#include "../../../inc/utils/utils.h"

static bool	is_not_valid_exit_argument(t_cmd *commands)
{
	int	i;

	i = 0;
	while (commands->command[1][i])
	{
		if (i == 0 && commands->command[1][1] && \
			(commands->command[1][0] == '-' || commands->command[1][0] == '+'))
		{
			i++;
			continue ;
		}
		if (commands->command[1][i] < '0' || commands->command[1][i] > '9')
		{
			if (commands->total_commands == 1)
				printf("exit\n");
			printf("exit: %s: numeric argument required\n", \
						commands->command[1]);
			return (true);
		}
		i++;
	}
	return (false);
}

static bool	exit_with_error_from_arguments(t_env *env, t_cmd *commands)
{
	if (is_not_valid_exit_argument(commands))
	{
		if (commands->total_commands == 1)
			exit (255);
		else
			return (true);
	}
	if (commands->no_of_arguments > 2)
	{
		if (commands->total_commands == 1)
			printf("exit\n");
		printf("exit: too many arguments\n");
		add_status_to_env(env, 1);
		return (true);
	}
	return (false);
}

void	ft_exit(t_env *env, t_cmd *commands)
{
	if (commands->no_of_arguments == 1)
	{
		if (commands->total_commands == 1)
		{
			printf("exit\n");
			exit(0);
		}
		else
			return ;
	}
	else
	{
		if (exit_with_error_from_arguments(env, commands))
			return ;
	}
	printf("exit\n");
	exit(ft_atoi(commands->command[1]));
}
