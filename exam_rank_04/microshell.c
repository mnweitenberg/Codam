#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int ft_strlen(char *str) {
	int i = 0;
	while (str[i])
		i++;
	return (i);
}

void ft_write(char *str) {
	write(2, str, ft_strlen(str));
}

void print_error(char *cmd) {
	ft_write("cd bad arguments\n");
	ft_write(cmd);
	ft_write("cd bad arguments\n");
	exit(1);
}

void print_fatal_error() {
	ft_write("cd bad arguments\n");
	exit(1);
}

void ft_cd(char *cmds[]) {
	int i = 0;
	while (cmds[i])
		i++;
	if (i != 2)
		ft_write("cd bad arguments\n");
	else if (chdir(cmds[1]) < 0) {
		ft_write("cd bad arguments\n");
		ft_write(cmds[1]);
		ft_write("cd bad arguments\n");
	}
}

int there_is_pipe(char *cmds[]) {
	int i = 0;
	while (cmds[i]) {
		if (strncmp(cmds[i], "|", 2) == 0) {
			cmds[i] = NULL;
			return (1);
		}
		if (strncmp(cmds[i], ";", 2) == 0) {
			cmds[i] = NULL;
			return (0);
		}
		i++;
	}
	return (0);
}

char **skip_executed_commands(int *argc, char *cmds[]) {
	int i = 0;
	while (cmds[i])
		i++;
	i++;
	argc -= i;
	return (&cmds[i]);
}

void execute_commands(int argc, char *cmds[], char *envp[],
	int this_is_not_the_first_command, int *fd) {
	int exit_code;
	int fd_next[2];
	pid_t pid;
	if (argc <= 1)
		exit(0);
	int there_is_another_pipe = there_is_pipe(cmds);
	if (cmds[0]) {
		if (there_is_another_pipe && pipe(fd_next) < 0)
			print_fatal_error();
		if (strncmp(cmds[0], "cd", 3) == 0)
			ft_cd(cmds);
		else if ((pid = fork()) < 0)
			print_fatal_error();
		else if (pid == 0) {
			if (this_is_not_the_first_command)
				dup2(fd[0], 0);
			if (there_is_another_pipe)
				dup2(fd_next[1], 1);
			if (execve(cmds[0], cmds, envp) < 0)
				print_error(cmds[0]);
		}
		else {
			waitpid(pid, &exit_code, 0);
			if (exit_code < 0 || exit_code / 256 == 255)
				print_fatal_error();
			if (this_is_not_the_first_command)
				close(fd[0]);
			if (there_is_another_pipe)
				close(fd_next[1]);
		}
	}
	cmds = skip_executed_commands(&argc, cmds);
	execute_commands(argc, cmds, envp, there_is_another_pipe, fd_next);
}

int main(int argc, char *argv[], char *envp[]) {
	int fd[2] = {0,1};
	execute_commands(argc, argv + 1, envp, 0, fd);
	return (0);
}
