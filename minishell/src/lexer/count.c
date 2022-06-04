/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   count.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mweitenb <mweitenb@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/19 17:52:02 by mweitenb      #+#    #+#                 */
/*   Updated: 2022/05/19 19:27:18 by mweitenb      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/utils/free.h"
#include "../../inc/utils/str_compare.h"

static t_token	*count_pipe_and_priority(t_token *tokens)
{
	t_token	*t;
	int		pipe_priority;
	int		pipe_count;

	t = tokens;
	pipe_count = 1;
	pipe_priority = 1;
	while (t)
	{
		if (ft_strncmp(t->text, "(", 2) == 0)
			pipe_priority++;
		if (ft_strncmp(t->text, ")", 2) == 0)
			pipe_priority--;
		t->pipe_priority = pipe_priority;
		if (ft_strncmp(t->text, "&&", 3) == 0
			|| ft_strncmp(t->text, "||", 3) == 0
			|| ft_strncmp(t->text, "(", 2) == 0)
			pipe_count++;
		t->pipe = pipe_count;
		t = t->next;
	}
	return (tokens);
}

static void	delete_token(t_token **token)
{
	t_token	*temp;

	temp = (*token);
	if (!(*token)->previous && (*token)->next)
		(*token)->next->previous = NULL;
	else if ((*token)->previous && (*token)->next)
	{
		(*token)->previous->next = (*token)->next;
		(*token)->next->previous = (*token)->previous;
	}
	else if ((*token)->previous && !(*token)->next)
		(*token)->previous->next = NULL;
	(*token) = (*token)->next;
	free(temp->text);
	free(temp);
}

static t_token	*delete_parenthesis(t_token *tokens)
{
	t_token	*t;
	t_token	*tmp;

	t = tokens;
	while (ft_strncmp(tokens->text, "(", 2) == 0)
		tokens = tokens->next;
	while (t)
	{
		if (t->next && (ft_strncmp(t->text, "&&", 3) == 0
				|| ft_strncmp(t->text, "||", 3) == 0)
			&& ft_strncmp(t->next->text, "(", 2) == 0)
		{
			tmp = t;
			while (tmp->next && ft_strncmp(tmp->next->text, "(", 2) == 0)
				tmp = tmp->next;
			t->pipe = tmp->pipe;
			t->pipe_priority = tmp->pipe_priority;
		}
		if (ft_strncmp(t->text, "(", 2) == 0
			|| ft_strncmp(t->text, ")", 2) == 0)
			delete_token(&t);
		else
			t = t->next;
	}
	return (tokens);
}

t_token	*count_pipes(t_token *tokens)
{
	tokens = count_pipe_and_priority(tokens);
	tokens = delete_parenthesis(tokens);
	return (tokens);
}
