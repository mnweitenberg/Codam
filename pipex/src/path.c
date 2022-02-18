/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   path.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mweitenb <mweitenb@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/13 13:37:19 by mweitenb      #+#    #+#                 */
/*   Updated: 2022/02/13 13:37:19 by mweitenb      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

static char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		len_s1;
	int		len_s2;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	str = (char *)malloc((len_s1 + len_s2 + 1) * sizeof(char));
	if (!str)
		handle_malloc_str(str);
	ft_strlcpy(str, s1, len_s1 + 1);
	ft_strlcpy(&str[len_s1], s2, len_s2 + 1);
	return (&str[0]);
}

static char	**create_array_of_possible_paths(char **envp)
{
	int		i;
	char	**possible_paths;

	i = 0;
	while (ft_strnstr(envp[i], "PATH", 4) == 0)
		i++;
	possible_paths = split_to_array(envp[i] + 5, ':');
	return (possible_paths);
}

static char	*try_possible_paths_until_one_works(char **base_paths,
	char *command)
{
	int		i;
	char	*path;
	char	*base_of_path;

	i = 0;
	while (base_paths[i])
	{
		base_of_path = ft_strjoin(base_paths[i], "/");
		path = ft_strjoin(base_of_path, command);
		free(base_of_path);
		if (access(path, X_OK) == 0)
			break ;
		free(path);
		path = NULL;
		i++;
	}
	return (path);
}

char	*create_path(t_pipex *p, char *command)
{
	char	**base_paths;
	char	*path;

	if (access(command, X_OK) == 0)
	{
		path = command;
		return (path);
	}
	base_paths = create_array_of_possible_paths(p->envp);
	path = try_possible_paths_until_one_works(base_paths, command);
	free_strings_in_array(base_paths);
	if (!path)
		handle_command_not_found(command);
	return (path);
}
