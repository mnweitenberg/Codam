/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   executor_utils.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: marvin <marvin@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/11 14:54:11 by mweitenb      #+#    #+#                 */
/*   Updated: 2022/05/16 21:44:51 by mweitenb      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../../inc/parser/parser.h"
#include "../../inc/utils/allocation.h"
#include "../../inc/utils/utils.h"

int	*init_pipes(int no_of_commands)
{
	int	*pipes;
	int	i;

	pipes = ft_calloc(sizeof(int), no_of_commands * 2);
	i = 0;
	while (i < no_of_commands * 2)
	{
		if (pipe(pipes + i) == -1)
			perror("pipe error: ");
		i += 2;
	}
	return (pipes);
}

void	close_pipes(int *pipes, int no_of_commands)
{
	int	i;

	i = 0;
	while (i <= no_of_commands - 2)
	{
		close(pipes[i * 2]);
		close(pipes[i * 2 + 1]);
		i++;
	}
	free(pipes);
}

static char	*merge_strings(char *old, char *buffer)
{
	int		old_len;
	int		buf_len;
	char	*new;

	old_len = ft_strlen(old);
	buf_len = ft_strlen(buffer);
	new = (char *)ft_calloc(sizeof(char), old_len + buf_len + 2);
	if (!old[0])
	{
		ft_strlcpy(new, buffer, buf_len + 1);
		new[buf_len + 1] = ' ';
		free(buffer);
	}
	else
	{
		ft_strlcpy(new, old, old_len + 1);
		new[old_len] = ' ';
		ft_strlcpy(&new[old_len + 1], buffer, buf_len + 1);
		free(old);
		free(buffer);
	}
	return (new);
}

char	*here_doc_expansion(t_env *env, char *line)
{
	t_token	*doc_token;
	char	*return_line;

	doc_token = lexer_tokens(env, line);
	return_line = ft_calloc(1, 1);
	while (doc_token)
	{
		return_line = merge_strings(return_line, doc_token->text);
		doc_token = doc_token->next;
	}
	return (return_line);
}
