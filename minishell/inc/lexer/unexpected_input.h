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

#ifndef UNEXPECTED_INPUT_H
# define UNEXPECTED_INPUT_H

# include "../lexer/lexer.h"

t_token	*handle_unexpected_input(t_token *tokens);

#endif
