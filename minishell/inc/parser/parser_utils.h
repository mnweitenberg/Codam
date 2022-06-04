/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser_utils.h                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: marvin <marvin@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/11 14:59:53 by mweitenb      #+#    #+#                 */
/*   Updated: 2022/05/12 13:48:59 by mweitenb      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_UTILS_H
# define PARSER_UTILS_H

# include "../parser/parser.h"

void	add_cmd_to_back_of_list(t_cmd **cmd, t_cmd *new);
char	*remove_quotes(char *src, int free_source);
void	add_pipe_to_back_of_list(t_pipes **pipe, t_pipes *new);
int		get_total_amount_of_pipes(t_token *tokens);

#endif
