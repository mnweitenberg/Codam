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

#ifndef PARAMETERS_H
# define PARAMETERS_H

# include "../lexer/lexer.h"

t_token	*deal_with_parameters(t_env *env, t_token *tokens);

#endif
