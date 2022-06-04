/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lexer_utils.h                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: marvin <marvin@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/11 14:59:57 by mweitenb      #+#    #+#                 */
/*   Updated: 2022/05/14 13:30:55 by mweitenb      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_UTILS_H
# define LEXER_UTILS_H

# include "../lexer/lexer.h"

void	add_token_to_back_of_list(t_token **token, t_token *new);
t_token	*copy_token(t_token *old);

#endif
