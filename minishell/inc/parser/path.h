/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   path.h                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mweitenb <mweitenb@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/11 15:00:00 by mweitenb      #+#    #+#                 */
/*   Updated: 2022/04/13 19:15:05 by mweitenb      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PATH_H
# define PATH_H

# include "../env/env_utils.h"

char	*create_path(t_env *env, char *command);

#endif
