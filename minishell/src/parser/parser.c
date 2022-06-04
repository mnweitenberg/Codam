/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: marvin <marvin@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/11 14:54:11 by mweitenb      #+#    #+#                 */
/*   Updated: 2022/05/16 22:38:22 by mweitenb      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "../../inc/lexer/lexer.h"
#include "../../inc/parser/path.h"
#include "../../inc/parser/parser.h"
#include "../../inc/parser/parse_commands.h"
#include "../../inc/parser/parser_utils.h"
#include "../../inc/utils/allocation.h"
#include "../../inc/utils/utils.h"
#include "../../inc/utils/str_compare.h"

static void	parse_file_descriptors(t_token *token, t_cmd *cmd)
{
	char	*filename;

	cmd->input = NULL;
	cmd->fd_output = 0;
	cmd->delimiter = NULL;
	if (token->next && token->pipe && is_operator(token->text[0]))
		token = token->next;
	while (token->next && !is_operator(token->text[0]))
	{
		filename = token->next->text;
		if (ft_strncmp(token->text, "<<\0", 3) == 0)
			cmd->delimiter = remove_quotes(filename, 0);
		else if (ft_strncmp(token->text, "<\0", 2) == 0)
			cmd->input = filename;
		else if (ft_strncmp(token->text, ">>\0", 3) == 0)
			cmd->fd_output = open(filename, O_CREAT | O_RDWR | O_APPEND, 0644);
		else if (ft_strncmp(token->text, ">\0", 2) == 0)
			cmd->fd_output = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0644);
		token = token->next;
	}
}

static void	parse_operator(t_token **token, t_cmd *cmd)
{
	char			tmp_operator[3];

	if (!(*token))
		return ;
	ft_memset(tmp_operator, '\0', 3);
	if ((*token) && ((*token)->text[0] == '|' || (*token)->text[0] == '&'))
		ft_strlcpy(tmp_operator, (*token)->text, 3);
	if (!(*token))
		return ;
	while ((*token) && is_operator((*token)->text[0]))
		(*token) = (*token)->next;
	ft_strlcpy(cmd->operator, tmp_operator, ft_strlen(tmp_operator) + 1);
}

static t_cmd	*parse_command_tables(t_env *env, t_token **token, int pipe)
{
	t_cmd			*command_table;
	t_cmd			*new_table;

	command_table = NULL;
	while ((*token) && (*token)->pipe == pipe)
	{
		new_table = (t_cmd *)ft_calloc(sizeof(t_cmd), 1);
		new_table->max_command_size = MAX_CMD_SIZE;
		new_table->command = (char **)ft_calloc(sizeof(char *), MAX_CMD_SIZE);
		parse_file_descriptors (*token, new_table);
		parse_operator(token, new_table);
		new_table->pipe_priority = (*token)->pipe_priority;
		parse_commands(token, new_table);
		if (!new_table->command[0] && command_table)
		{
			free(new_table->command);
			free(new_table);
			break ;
		}
		new_table->path = create_path(env, new_table->command[0]);
		add_cmd_to_back_of_list(&command_table, new_table);
	}
	return (command_table);
}

static void	count_total_commands_and_update_command_table(t_pipes *pipes)
{
	t_cmd			*temp;
	int				no_of_commands;
	int				i;

	while (pipes)
	{
		no_of_commands = 0;
		temp = pipes->command_table;
		while (temp)
		{
			no_of_commands++;
			temp = temp->next;
		}
		i = 0;
		temp = pipes->command_table;
		while (temp)
		{
			temp->index = i++;
			temp->total_commands = no_of_commands;
			temp = temp->next;
		}
		pipes = pipes->next;
	}
}

t_pipes	*parse_tokens(t_env *env, t_token *token)
{
	int		i;
	int		total_amount_of_pipes;
	t_pipes	*pipes;
	t_pipes	*new_pipe;

	pipes = NULL;
	i = 0;
	total_amount_of_pipes = get_total_amount_of_pipes(token);
	while (i < total_amount_of_pipes)
	{
		new_pipe = (t_pipes *)ft_calloc(sizeof(t_pipes), 1);
		new_pipe->command_table = parse_command_tables(env, &token, i + 1);
		add_pipe_to_back_of_list(&pipes, new_pipe);
		i++;
	}
	count_total_commands_and_update_command_table(pipes);
	return (pipes);
}
