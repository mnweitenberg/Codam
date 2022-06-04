/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   quotes.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mweitenb <mweitenb@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/19 11:45:55 by mweitenb      #+#    #+#                 */
/*   Updated: 2022/05/19 20:49:17 by mweitenb      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "../../inc/executor/here_doc.h"
#include "../../inc/utils/allocation.h"
#include "../../inc/utils/utils.h"
#include "../../inc/utils/str_compare.h"

static char	*merge_strings(char *line, char *print_line)
{
	int		line_len;
	int		print_len;
	char	*new;

	line_len = ft_strlen(line);
	print_len = ft_strlen(print_line);
	new = (char *)ft_calloc(sizeof(char), line_len + print_len + 1);
	if (!print_line)
	{
		ft_strlcpy(new, line, line_len + 1);
	}
	else
	{
		ft_strlcpy(new, print_line, print_len + 1);
		ft_strlcpy(&new[print_len], line, line_len + 1);
		free(print_line);
	}
	return (new);
}

static void	print_delimiter_string(char *print_line, char delimiter)
{
	int	i;

	i = 0;
	while (print_line[i])
	{
		if (print_line[i] != delimiter)
			write(1, &print_line[i], 1);
		i++;
	}
}

static void	write_input_to_str(char delimiter)
{
	char	*line;
	char	*print_line;
	int		i;

	signal(SIGINT, SIG_DFL);
	print_line = NULL;
	while (1)
	{
		line = readline("> ");
		if (!line)
			exit (78);
		line = append_newline(line);
		i = 0;
		print_line = merge_strings(line, print_line);
		while (line[i])
		{
			if (line[i++] == delimiter)
			{
				if (print_line)
					print_delimiter_string(print_line, delimiter);
				exit (0);
			}
		}
		free(line);
	}
}

static bool	handle_quote_exit(int status, t_env *env, char quote)
{
	if (WIFSIGNALED(status))
	{
		printf("\n");
		add_status_to_env(env, 1);
		return (true);
	}
	else if (WEXITSTATUS(status))
	{
		if (WEXITSTATUS(status) == 78)
		{
			add_status_var_to_env(env, "258");
			printf("unexpected EOF while looking for matching '%c'\n", quote);
			printf("syntax error: unexpected end of file\n");
			return (true);
		}
	}
	return (false);
}

int	here_doc_for_quotes(t_env *env, char *read_line,
	int single_quote_count, int double_quote_count)
{
	pid_t	pid;
	int		status;
	char	quote;

	quote = 0;
	if ((single_quote_count
			&& position_of_char_within_str('\'', read_line)
			< position_of_char_within_str('\"', read_line))
		|| (single_quote_count && !double_quote_count))
		quote = '\'';
	else if ((double_quote_count
			&& position_of_char_within_str('\'', read_line)
			> position_of_char_within_str('\"', read_line))
		|| (!single_quote_count && double_quote_count))
		quote = '\"';
	pid = fork();
	if (!pid)
	{
		signal(SIGINT, SIG_DFL);
		write_input_to_str(quote);
	}
	wait(&status);
	if (handle_quote_exit(status, env, quote))
		return (0);
	return (1);
}
