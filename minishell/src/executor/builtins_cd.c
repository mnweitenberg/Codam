/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   builtins_cd.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mweitenb <mweitenb@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/31 19:19:44 by mweitenb      #+#    #+#                 */
/*   Updated: 2022/05/16 14:25:28 by mweitenb      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdbool.h>
#include "../../inc/parser/parser.h"
#include "../../inc/env/env_utils.h"
#include "../../inc/utils/allocation.h"
#include "../../inc/utils/str_compare.h"
#include "../../inc/utils/utils.h"

static char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (0);
	ret = (char *) ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, 1);
	if (!ret)
		return (0);
	i = 0;
	while (s1[i])
	{
		ret[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		ret[i] = s2[j];
		i++;
		j++;
	}
	return (ret);
}

static void	cd_to_home(t_env *env)
{
	t_env_var	*home_entry;
	char		*target_path;

	home_entry = do_lookup("HOME", env);
	if (!home_entry)
		write(2, "cd: HOME not set\n", 18);
	else
	{
		target_path = ft_strjoin(home_entry->value, "/");
		chdir(target_path);
		free(target_path);
	}
}

static void	print_cd_error(char *command)
{
	write(2, "cd: ", 4);
	write(2, command, ft_strlen(command));
	write(2, ": ", 2);
	perror("");
}

static int	execute_cd(t_env *env, char *command)
{
	char	*current_path;
	char	*target_path;

	if (!command)
	{
		cd_to_home(env);
		return (1);
	}
	current_path = getcwd(NULL, 0);
	target_path = ft_strjoin(current_path, "/");
	target_path = ft_strjoin(target_path, command);
	target_path = ft_strjoin(target_path, "/");
	free(current_path);
	if (!chdir(target_path))
	{
		free(target_path);
		return (1);
	}
	free(target_path);
	if (!chdir(command))
		return (1);
	print_cd_error(command);
	return (0);
}

bool	ft_cd(t_env *env, t_cmd *commands)
{
	if (!commands)
		return (true);
	if (commands->total_commands > 1)
		return (false);
	if ((ft_strncmp(commands->command[0], "cd",
				ft_strlen(commands->command[0])) == 0))
	{
		execute_cd(env, commands->command[1]);
		return (true);
	}
	return (false);
}
