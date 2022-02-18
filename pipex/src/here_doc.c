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

#include "../inc/pipex.h"

static char	*add_buffer_to_line(char *old, char buffer)
{
	char	*new;
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (old[len])
		len++;
	new = (char *)malloc(sizeof(char) * (len + 2));
	if (!new)
		handle_malloc_str(new);
	while (i < len)
	{
		new[i] = old[i];
		i++;
	}
	new[i++] = buffer;
	new[i] = 0;
	free(old);
	return (new);
}

static char	*get_next_line(void)
{
	char	buffer;
	char	*line;

	line = (char *)malloc(sizeof(char));
	if (!line)
		handle_malloc_str(line);
	line[0] = 0;
	while (read(0, &buffer, 1) && buffer != '\n')
	{
		line = add_buffer_to_line(line, buffer);
	}
	if (buffer == '\n')
		line = add_buffer_to_line(line, '\n');
	return (line);
}

static void	write_input_to_fd(char *delimiter, int *fd)
{
	char	*line;

	close(fd[0]);
	while (1)
	{
		line = get_next_line();
		if (ft_strncmp(line, delimiter, ft_strlen(delimiter)) == 0)
		{
			free(line);
			exit(EXIT_SUCCESS);
		}
		ft_putstr_fd(line, fd[1]);
		free(line);
	}
}

void	here_doc(char *delimiter, int argc)
{
	pid_t	pid;
	int		fd[2];

	if (argc < 6)
	{
		ft_putstr_fd("Error: Too few arguments\n", 1);
		exit(EXIT_FAILURE);
	}
	if (pipe(fd) == -1)
		exit(EXIT_FAILURE);
	pid = fork();
	if (pid == 0)
		write_input_to_fd(delimiter, fd);
	close(fd[1]);
	dup2(fd[0], STDIN_FILENO);
	wait(NULL);
}
