/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: marvin <marvin@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/11 14:59:53 by mweitenb      #+#    #+#                 */
/*   Updated: 2022/05/16 21:45:15 by mweitenb      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "../env/env.h"
# include "../lexer/lexer.h"

# define MAX_CMD_SIZE 255 

typedef struct s_cmd	t_cmd;
typedef struct s_pipes	t_pipes;

struct s_cmd
{
	int				pipe_priority;
	unsigned int	index;
	unsigned int	max_command_size;
	char			**command;
	char			operator[3];
	unsigned int	no_of_arguments;
	unsigned int	total_commands;
	char			*path;
	char			*input;
	int				fd_input;
	int				fd_output;
	char			*delimiter;
	t_cmd			*previous;
	t_cmd			*next;
};

struct s_pipes
{
	t_cmd	*command_table;
	t_pipes	*next;
};

t_pipes	*parse_tokens(t_env *env, t_token *token);

#endif
