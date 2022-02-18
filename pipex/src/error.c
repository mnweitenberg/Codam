/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mweitenb <mweitenb@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/13 13:37:12 by mweitenb      #+#    #+#                 */
/*   Updated: 2022/02/13 13:37:12 by mweitenb      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	free_strings_in_array(char **str_array)
{
	int	i;

	i = 0;
	while (1)
	{
		if (!str_array[i])
			break ;
		free(str_array[i]);
		str_array[i] = NULL;
		i++;
	}
	free(str_array);
	str_array = NULL;
}

void	handle_perror(char **argument)
{
	perror(argument[0]);
	exit(errno);
}

void	handle_malloc_str(char *str)
{
	perror("Error: malloc failure");
	free(str);
	str = NULL;
	exit(errno);
}

void	handle_malloc_array(char **array)
{
	perror("Error: malloc failure");
	free(array);
	array = NULL;
	exit(errno);
}

void	handle_command_not_found(char *command)
{
	ft_putstr_fd(command, 2);
	ft_putstr_fd(": command not found\n", 2);
	exit(errno);
}
