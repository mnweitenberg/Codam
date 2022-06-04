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
#include "../../inc/utils/free.h"
#include "../../inc/utils/str_compare.h"

static t_token	*print_error(t_token *tokens, char *str)
{
	printf("syntax error near unexpected token '%s'\n", str);
	free_tokens(tokens);
	return (NULL);
}

int	check_for_empty_parenthesis(t_token *tokens)
{
	t_token	*t;

	t = tokens;
	if (ft_strncmp(t->text, "(", 2) != 0)
		return (0);
	if (!t->next)
		return (1);
	t = t->next;
	if (ft_strncmp(t->text, ")", 1) == 0
		|| ft_strncmp(t->text, "&", 1) == 0
		|| ft_strncmp(t->text, "|", 1) == 0
		|| ft_strncmp(t->text, "<", 1) == 0
		|| ft_strncmp(t->text, ">", 1) == 0)
		return (1);
	return (0);
}

int	check_for_multiple_operators_following_eachother(t_token *tokens)
{
	t_token	*t;

	t = tokens;
	if (((ft_strncmp(t->text, ">>", 2) == 0
				|| ft_strncmp(t->text, "<<", 2) == 0)
			&& t->text[2] && (t->text[2] == '>' || t->text[2] == '<'
				|| t->text[2] == '&' || t->text[2] == '|'))
		|| ((ft_strncmp(t->text, "&&", 2) == 0
				|| ft_strncmp(t->text, "||", 2) == 0)
			&& t->text[2] && (t->text[2] == '&' || t->text[2] == '|')))
		return (1);
	return (0);
}

t_token	*handle_unexpected_input(t_token *tokens)
{
	t_token	*t;

	t = tokens;
	if (ft_strncmp(t->text, ")", 1) == 0
		|| ft_strncmp(t->text, "&", 1) == 0
		|| ft_strncmp(t->text, "|", 1) == 0)
		return (print_error(tokens, t->text));
	while (t->next)
	{
		if (check_for_empty_parenthesis(t))
			return (print_error(tokens, t->text));
		if (ft_strncmp(t->text, "&", 2) == 0)
			return (print_error(tokens, t->text));
		if (check_for_multiple_operators_following_eachother(t))
			return (print_error(tokens, &t->text[2]));
		t = t->next;
	}
	if (t->text[0] == '<' || t->text[0] == '>'
		|| t->text[0] == '|' || t->text[0] == '&'
		|| t->text[0] == '(')
		return (print_error(tokens, &t->text[0]));
	return (tokens);
}
