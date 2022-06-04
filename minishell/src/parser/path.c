/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   path.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mweitenb <mweitenb@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/11 14:54:23 by mweitenb      #+#    #+#                 */
/*   Updated: 2022/03/11 14:54:23 by mweitenb      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../../inc/utils/allocation.h"
#include "../../inc/utils/ft_split.h"
#include "../../inc/utils/utils.h"
#include "../../inc/utils/free.h"
#include "../../inc/env/env_utils.h"

static char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		len_s1;
	int		len_s2;

	if (!s1 || !s2)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	str = (char *)ft_calloc((len_s1 + len_s2 + 1), sizeof(char));
	ft_strlcpy(str, s1, len_s1 + 1);
	ft_strlcpy(&str[len_s1], s2, len_s2 + 1);
	return (str);
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

char	*create_path(t_env *env, char *command)
{
	char	**base_paths;
	char	*path;

	path = command;
	if (access(command, X_OK) == 0)
		return (ft_strdup(path));
	base_paths = ft_split(get_variable_from_env(env, "PATH", 4), ':');
	if (!base_paths)
		return (NULL);
	path = try_possible_paths_until_one_works(base_paths, command);
	free_strings_in_array(base_paths);
	return (path);
}
