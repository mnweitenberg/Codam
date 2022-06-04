/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   executor.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: marvin <marvin@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/11 14:58:31 by mweitenb      #+#    #+#                 */
/*   Updated: 2022/05/16 22:38:32 by mweitenb      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>
#include <string.h>
#include <sys/wait.h>
#include "../../inc/executor/executor.h"
#include "../../inc/executor/here_doc.h"
#include "../../inc/executor/executor_utils.h"
#include "../../inc/executor/export_unset_exit/export_unset_exit.h"
#include "../../inc/executor/builtins.h"
#include "../../inc/executor/builtins_cd.h"
#include "../../inc/utils/utils.h"
#include "../../inc/utils/str_compare.h"
#include "../../inc/utils/allocation.h"

extern char	**environ;

static int	check_if_pipe_should_be_executed(t_env *env, t_cmd *cmd)
{
	int			previous_exit_code;
	static int	forbidden_pipe = -1;

	if (!cmd)
		return (0);
	if (!cmd->operator[0])
		forbidden_pipe = -1;
	previous_exit_code = ft_atoi(get_variable_from_env(env, "?", 1));
	if (cmd->pipe_priority >= forbidden_pipe && forbidden_pipe != -1)
		return (0);
	if ((ft_strncmp(cmd->operator, "&&", 3) == 0 && previous_exit_code != 0)
		|| (ft_strncmp(cmd->operator, "||", 3) == 0 && previous_exit_code == 0))
	{
		forbidden_pipe = cmd->pipe_priority + 1;
		if (cmd->pipe_priority > 1)
			forbidden_pipe = cmd->pipe_priority;
		return (0);
	}
	forbidden_pipe = -1;
	return (1);
}

static void	redirections(t_env *env, t_cmd *cmd, int *pipes)
{
	if (here_doc(env, cmd))
		cmd->input = ft_strdup("FD_TEMP");
	if (cmd->input)
	{
		cmd->fd_input = open(cmd->input, O_RDONLY);
		if (cmd->fd_input == -1)
		{
			printf("%s: %s\n", cmd->input, strerror(errno));
			exit(0);
		}
	}
	if (cmd->fd_input)
		dup2(cmd->fd_input, STDIN_FILENO);
	else if (cmd->index > 0)
		dup2(pipes[cmd->index * 2 - 2], STDIN_FILENO);
	if (cmd->fd_output)
		dup2(cmd->fd_output, STDOUT_FILENO);
	else if (cmd->index < cmd->total_commands - 1)
		dup2(pipes[cmd->index * 2 + 1], STDOUT_FILENO);
}

static void	execute_command(t_env *env, t_cmd *commands, pid_t *pid, int *pipes)
{
	*pid = fork();
	if (*pid == 0)
	{
		redirections(env, commands, pipes);
		close_pipes(pipes, commands->total_commands);
		signal(SIGINT, SIG_DFL);
		signal(SIGQUIT, SIG_DFL);
		if (execute_builtins(env, commands))
			exit(EXIT_SUCCESS);
		signal(SIGQUIT, SIG_DFL);
		if (execve(commands->path, commands->command, environ) == -1)
		{
			if (!commands->path)
			{
				if (!commands->delimiter)
				{
					ft_putstr_fd(commands->command[0], 2);
					ft_putstr_fd(": command not found\n", 2);
				}
				exit(127);
			}
			perror(commands->command[0]);
			exit(errno);
		}
	}
}

int	execute(t_env *env, t_cmd *commands)
{
	pid_t	pid;
	int		*pipes;
	int		status;
	int		total_commands;

	if (!commands || !check_if_pipe_should_be_executed(env, commands))
		return (0);
	total_commands = commands->total_commands;
	pipes = init_pipes(total_commands);
	status = 0;
	while (commands)
	{
		if (ft_cd(env, commands))
			break ;
		if (export_unset_exit(env, commands))
			execute_command(env, commands, &pid, pipes);
		commands = commands->next;
	}
	close_pipes(pipes, total_commands);
	while (total_commands--)
		waitpid(-1, &status, 0);
	add_status_to_env(env, status);
	return (status);
}
