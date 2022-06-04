/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_cmd_table.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 18:28:22 by marvin            #+#    #+#             */
/*   Updated: 2022/04/27 18:28:22 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "../../inc/lexer/lexer.h"
#include "../../inc/parser/parser.h"
#include "../../inc/parser/parser_utils.h"
#include "../../inc/utils/allocation.h"
#include "../../inc/utils/utils.h"
#include "../../inc/utils/str_compare.h"

static char	*parse_command_name(char *src, int command_nb)
{
	char	*dst;

	dst = ft_strdup(src);
	if (position_of_char_within_str('\'', dst) >= 0
		|| position_of_char_within_str('\"', dst) >= 0)
	{
		if ((ft_strncmp(src, "\"\"", ft_strlen(src)) == 0
				|| ft_strncmp(src, "\'\'", ft_strlen(src)) == 0)
			&& command_nb == 0)
			return (NULL);
		if (!dst)
			return (NULL);
		dst = remove_quotes(dst, 1);
	}
	return (dst);
}

static int	skip_brackets_and_filenames(t_token **token)
{
	if ((*token)->text[0] == '<'
		|| (*token)->text[0] == '>'
		|| ((*token)->previous
			&& ((*token)->previous->text[0] == '<'
				|| (*token)->previous->text[0] == '>')))
	{
		(*token) = (*token)->next;
		return (1);
	}
	return (0);
}

static char	**reallocate_command(t_cmd *cmd)
{
	char	**new_command;
	int		old_size;

	old_size = cmd->max_command_size;
	cmd->max_command_size *= 2;
	new_command = (char **)ft_calloc(sizeof(char *), cmd->max_command_size);
	while (0 < old_size)
	{
		old_size -= 1;
		new_command[old_size] = cmd->command[old_size];
	}
	free(cmd->command);
	return (new_command);
}

void	parse_commands(t_token **token, t_cmd *cmd)
{
	unsigned int	i;

	i = 0;
	while ((*token) && !is_operator((*token)->text[0]))
	{
		if (skip_brackets_and_filenames(token))
			continue ;
		cmd->command[i] = parse_command_name((*token)->text, i);
		i++;
		(*token) = (*token)->next;
		if (i == cmd->max_command_size - 1)
			cmd->command = reallocate_command(cmd);
	}
	if (!cmd->command[0] && (cmd->input || cmd->fd_output))
		cmd->command[i++] = ft_strdup("cat");
	cmd->command[i] = NULL;
	cmd->no_of_arguments = i;
}
