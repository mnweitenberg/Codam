/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   env.h                            	    :+:    :+:          			  */
/*                                                     +:+                    */
/*   By: mweitenb <mweitenb@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/11 14:59:44 by mweitenb      #+#    #+#                 */
/*   Updated: 2022/03/11 14:59:44 by mweitenb      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

typedef struct s_env			t_env;
typedef struct s_env_var		t_env_var;

struct s_env_var
{
	char					*name;
	char					*value;
	t_env_var				*next;
};

struct s_env
{
	int			symbol_count;
	t_env_var	*first;
	t_env_var	*last;
	t_env_var	*export;
};

void	init_export(t_env *env);
t_env	*init_env(void);
int		add_status_to_env(t_env *env, int status);
void	add_status_var_to_env(t_env *env, char *w_status);

#endif
