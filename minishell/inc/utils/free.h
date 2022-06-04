/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free.h                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: marvin <marvin@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/11 14:58:59 by mweitenb      #+#    #+#                 */
/*   Updated: 2022/05/16 16:04:19 by mweitenb      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FREE_H
# define FREE_H

# include "../../inc/lexer/lexer.h"
# include "../../inc/parser/parser.h"

void	free_strings_in_array(char **str_array);
void	free_tokens(t_token *tokens);
void	free_single_command_table(t_cmd *cmd);
void	free_pipes(t_pipes *pipes);
void	free_env(t_env *env);

#endif