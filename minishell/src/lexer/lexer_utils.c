/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lexer_utils.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mweitenb <mweitenb@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/12 13:44:32 by mweitenb      #+#    #+#                 */
/*   Updated: 2022/05/16 22:31:30 by mweitenb      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../../inc/lexer/lexer.h"
#include "../../inc/utils/allocation.h"

static t_token	*ft_lstlast_token(t_token *token)
{
	if (!token)
		return (0);
	while (token->next)
		token = token->next;
	return (token);
}

void	add_token_to_back_of_list(t_token **token, t_token *new)
{
	t_token	*temp;

	if (!*token)
		*token = new;
	else
	{
		temp = ft_lstlast_token(*token);
		temp->next = new;
		new->previous = temp;
	}
}

t_token	*copy_token(t_token *old)
{
	t_token	*new;

	new = (t_token *)ft_calloc(sizeof(t_token), 1);
	new->text = ft_strdup(old->text);
	new->previous = NULL;
	new->next = NULL;
	return (new);
}
