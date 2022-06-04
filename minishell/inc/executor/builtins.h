/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   builtins.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: marvin <marvin@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/11 14:00:39 by mweitenb      #+#    #+#                 */
/*   Updated: 2022/05/11 13:45:22 by mweitenb      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include "../../inc/env/env.h"
# include "../../inc/parser/parser.h"

int		execute_builtins(t_env *env, t_cmd *commands);

#endif
