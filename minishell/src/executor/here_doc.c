/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   here_doc.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mweitenb <mweitenb@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/13 13:37:15 by mweitenb      #+#    #+#                 */
/*   Updated: 2022/02/13 13:37:15 by mweitenb      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <sys/wait.h>
#include <fcntl.h>
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "../../inc/parameter_expansion/parameter_expansion.h"
#include "../../inc/utils/allocation.h"
#include "../../inc/utils/utils.h"
#include "../../inc/utils/str_compare.h"
#include "../../inc/executor/executor_utils.h"

static void	sig_here_doc(int signal)
{
	if (signal == SIGINT)
	{
		printf("\n");
		exit(0);
	}
}

char	*append_newline(char *line)
{
	int		i;
	int		len;
	char	*line_with_newline;

	if (!line)
		return (NULL);
	i = 0;
	len = ft_strlen(line);
	line_with_newline = ft_calloc(sizeof(char), len + 2);
	while (line[i])
	{
		line_with_newline[i] = line[i];
		i++;
	}
	line_with_newline[i] = '\n';
	free(line);
	return (line_with_newline);
}

static int	there_are_parameters(const char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i] == '$' && !(!str[1 + i] || str[1 + i] == ' '
				|| str[i + 1] == '\'' || str[i + 1] == '\"'))
			return (1);
		i++;
	}
	return (0);
}

static void	write_input_to_fd(t_env *env, char *delimiter, int *fd)
{
	char	*line;

	*fd = open("FD_TEMP", O_CREAT | O_RDWR | O_APPEND, 0644);
	line = NULL;
	while (1)
	{
		line = readline("> ");
		if (!line)
			return ;
		if (there_are_parameters(line))
			line = here_doc_expansion(env, line);
		line = append_newline(line);
		if (ft_strncmp(line, delimiter, ft_strlen(delimiter)) == 0
			&& line[ft_strlen(delimiter)] == '\n')
		{
			free(line);
			return ;
		}
		ft_putstr_fd(line, *fd);
		free(line);
	}
}

int	here_doc(t_env *env, t_cmd *cmd)
{
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, sig_here_doc);
	if (cmd->delimiter)
		write_input_to_fd(env, cmd->delimiter, &cmd->fd_input);
	else
		return (0);
	return (1);
}
