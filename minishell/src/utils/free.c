/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: marvin <marvin@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/31 15:19:12 by mweitenb      #+#    #+#                 */
/*   Updated: 2022/05/16 16:04:04 by mweitenb      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/lexer/lexer.h"
#include "../../inc/parser/parser.h"
#include <stdlib.h>

void	free_strings_in_array(char **str_array)
{
	int	i;

	i = 0;
	while (1)
	{
		if (!str_array[i])
			break ;
		free(str_array[i]);
		str_array[i] = NULL;
		i++;
	}
	free(str_array);
	str_array = NULL;
}

void	free_tokens(t_token *token)
{
	t_token	*temp;

	while (token)
	{
		temp = token;
		token = token->next;
		free(temp->text);
		temp->text = NULL;
		free(temp);
		temp = NULL;
	}
}

void	free_single_command_table(t_cmd *cmd)
{
	unsigned int	i;

	if (!cmd)
		return ;
	i = 0;
	while (i < cmd->no_of_arguments)
	{
		free(cmd->command[i]);
		cmd->command[i] = NULL;
		i++;
	}
	free(cmd->command);
	free(cmd->path);
	free(cmd->delimiter);
	free(cmd);
	cmd = NULL;
}

void	free_pipes(t_pipes *pipes)
{
	t_cmd	*tmp_cmd;
	t_pipes	*tmp_pipe;

	while (pipes)
	{
		while (pipes->command_table)
		{
			tmp_cmd = pipes->command_table;
			pipes->command_table = pipes->command_table->next;
			free_single_command_table(tmp_cmd);
		}
		tmp_pipe = pipes;
		pipes = pipes->next;
		free(tmp_pipe);
	}
}

void	free_env(t_env *env)
{
	t_env_var	*var;
	t_env_var	*next;

	if (env == NULL)
		return ;
	var = env->first;
	while (var)
	{
		if (var->name)
			free(var->name);
		if (var->value)
			free(var->value);
		next = var->next;
		free(var);
		var = next;
	}
	free(env);
}
