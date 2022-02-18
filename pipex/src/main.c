/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mweitenb <mweitenb@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/13 13:37:17 by mweitenb      #+#    #+#                 */
/*   Updated: 2022/02/13 13:37:17 by mweitenb      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

static void	init_arguments(int argc, char **argv, char **envp, t_pipex *p)
{
	p->envp = envp;
	p->argc = argc;
	if (ft_strncmp(argv[1], "here_doc", 8) == 0)
	{
		here_doc(argv[2], argc);
		p->offset = 3;
		p->output_file = open(argv[argc - 1],
				O_CREAT | O_RDWR | O_APPEND, 0644);
	}
	else
	{
		p->offset = 2;
		p->input_file = open(argv[1], O_RDONLY);
		p->output_file = open(argv[argc - 1], O_CREAT | O_RDWR | O_TRUNC, 0644);
		if (p->input_file < 0)
		{
			ft_putstr_fd(argv[1], 1);
			ft_putstr_fd(": ", 1);
			ft_putstr_fd(strerror(errno), 1);
			ft_putstr_fd("\n", 1);
			exit(EXIT_FAILURE);
		}
	}
}

static void	execute_child_process(t_pipex *p, int *fd)
{
	char	**commands;
	char	*path;

	if (p->offset == p->argc - 2)
		fd[1] = p->output_file;
	dup2(fd[1], STDOUT_FILENO);
	close(fd[1]);
	commands = split_to_array(p->command, ' ');
	path = create_path(p, *commands);
	if (execve(path, commands, p->envp) == -1)
		handle_perror(commands);
}

static void	create_pipe_and_execute_commands(t_pipex *p)
{
	int		pid;
	int		fd[2];

	if (p->offset == 2)
		fd[0] = p->input_file;
	dup2(fd[0], STDIN_FILENO);
	close(fd[0]);
	if (pipe(fd) == -1)
		exit (EXIT_FAILURE);
	pid = fork();
	if (pid < 0)
		exit (EXIT_FAILURE);
	if (pid == 0)
		execute_child_process(p, fd);
	close(fd[1]);
	waitpid(pid, NULL, 0);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	p;

	if (argc < 5)
	{
		ft_putstr_fd("Error: Too few arguments\n", 1);
		exit(EXIT_FAILURE);
	}
	init_arguments(argc, argv, envp, &p);
	while (p.offset < argc - 1)
	{
		p.command = argv[p.offset];
		create_pipe_and_execute_commands(&p);
		p.offset++;
	}
	return (0);
}
