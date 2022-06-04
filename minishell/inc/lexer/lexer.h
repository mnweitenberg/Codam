/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lexer.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: marvin <marvin@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/11 14:59:57 by mweitenb      #+#    #+#                 */
/*   Updated: 2022/05/16 22:30:53 by mweitenb      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# include "../env/env.h"

typedef struct s_token	t_token;

struct s_token
{
	char		*text;
	int			pipe;
	int			pipe_priority;
	t_token		*previous;
	t_token		*next;
};

t_token	*lexer_tokens(t_env *env, char *read_line);

#endif
