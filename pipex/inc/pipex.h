/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mweitenb <mweitenb@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/13 20:54:41 by mweitenb      #+#    #+#                 */
/*   Updated: 2022/02/13 20:54:41 by mweitenb      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <errno.h>

typedef struct s_pipex
{
	int		offset;
	int		argc;
	char	**envp;
	int		input_file;
	int		output_file;
	char	*command;
}	t_pipex;

//	path.c
char	*create_path(t_pipex *p, char *commands);

//	split.c
char	**split_to_array(char const *s, char c);

//	utils.c
int		ft_strlen(const char *str);
void	ft_putstr_fd(char *s, int fd);
char	*ft_strnstr(const char *big, const char *little, size_t len);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);

//	error.c
void	free_strings_in_array(char **str_array);
void	handle_perror(char **argument);
void	handle_malloc_str(char *str);
void	handle_malloc_array(char **array);
void	handle_command_not_found(char *command);

//	heredoc
void	here_doc(char *delimiter, int argc);

#endif
