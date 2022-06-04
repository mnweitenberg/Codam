/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   env.h                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mweitenb <mweitenb@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/11 14:59:08 by mweitenb      #+#    #+#                 */
/*   Updated: 2022/03/11 14:59:08 by mweitenb      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_UTILS_H
# define ENV_UTILS_H

# include "../env/env.h"

char		*get_variable_from_env(t_env *env, char *name, int len);
void		add_var_to_env(t_env *env, char *name, char *value);
t_env_var	*do_lookup(char *name, t_env *env);
t_env_var	*add_to_back_of_list(t_env_var *first, t_env_var *add);

#endif