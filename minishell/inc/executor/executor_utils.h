/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   executor_utils.h                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: marvin <marvin@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/11 14:59:53 by mweitenb      #+#    #+#                 */
/*   Updated: 2022/05/12 13:01:03 by mweitenb      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTOR_UTILS_H
# define EXECUTOR_UTILS_H

# include "../env/env_utils.h"
# include "../parser/parser.h"

int		*init_pipes(int no_of_commands);
void	close_pipes(int *pipes, int no_of_commands);
char	*here_doc_expansion(t_env *env, char *line);

#endif
