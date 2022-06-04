/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minishell.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: marvin <marvin@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/11 14:53:28 by mweitenb      #+#    #+#                 */
/*   Updated: 2022/05/16 22:09:57 by mweitenb      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "../inc/parser/parser.h"
#include "../inc/executor/executor.h"
#include "../inc/utils/free.h"

static char	*read_line_from_prompt(void)
{
	static char	*line_read;

	if (line_read)
	{
		free (line_read);
		line_read = NULL;
	}
	line_read = readline ("minishell: ");
	if (line_read && *line_read)
		add_history (line_read);
	if (!line_read)
	{
		printf("exit\n");
		exit(0);
	}
	return (line_read);
}

static void	ignore_signals(void)
{
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
}

static void	parse_and_execute(t_env *env, char *read_line)
{
	t_token			*tokens;
	t_pipes			*pipes;
	t_pipes			*pipes_start;

	if (!*read_line)
		return ;
	ignore_signals();
	tokens = lexer_tokens(env, read_line);
	if (!tokens)
		return ;
	pipes = parse_tokens(env, tokens);
	pipes_start = pipes;
	while (pipes)
	{
		execute(env, pipes->command_table);
		pipes = pipes->next;
	}
	unlink("FD_TEMP");
	free_tokens(tokens);
	free_pipes(pipes_start);
}

static void	sig_handle(int signal)
{
	if (signal == SIGINT)
	{
		printf("\n");
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
	}
}

int	main(void)
{
	char	*read_line;
	t_env	*env;

	env = init_env();
	init_export(env);
	while (1)
	{
		signal(SIGINT, sig_handle);
		signal(SIGQUIT, SIG_IGN);
		read_line = read_line_from_prompt();
		parse_and_execute(env, read_line);
	}
	return (EXIT_SUCCESS);
}
