/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lexer.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: marvin <marvin@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/11 14:54:17 by mweitenb      #+#    #+#                 */
/*   Updated: 2022/05/19 21:19:57 by mweitenb      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../../inc/env/env.h"
#include "../../inc/parameter_expansion/parameter_expansion.h"
#include "../../inc/lexer/parameters.h"
#include "../../inc/lexer/unexpected_input.h"
#include "../../inc/lexer/count.h"
#include "../../inc/lexer/lexer_utils.h"
#include "../../inc/lexer/quotes.h"
#include "../../inc/lexer/split.h"
#include "../../inc/lexer/wildcards.h"
#include "../../inc/utils/allocation.h"
#include "../../inc/utils/free.h"

static int	check_quotes(char *read_line, t_env *env)
{
	int		i;
	int		single_quote_count;
	int		double_quote_count;

	i = 0;
	single_quote_count = 0;
	double_quote_count = 0;
	while (read_line[i])
	{
		if (read_line[i] == '\'')
			single_quote_count += 1;
		if (read_line[i++] == '"')
			double_quote_count += 1;
	}
	single_quote_count = single_quote_count % 2;
	double_quote_count = double_quote_count % 2;
	if (single_quote_count || double_quote_count)
		return (here_doc_for_quotes(env, read_line, single_quote_count, \
		double_quote_count));
	return (1);
}

static int	check_parantheses(char *read_line)
{
	int		i;
	int		parantheses_count;

	i = 0;
	parantheses_count = 0;
	while (read_line[i])
	{
		if (read_line[i] == '(')
			parantheses_count += 1;
		if (read_line[i] == ')')
			parantheses_count -= 1;
		i++;
	}
	if (parantheses_count != 0)
	{
		printf("syntax error near unexpected token\n");
		return (0);
	}
	return (1);
}

t_token	*tokenize(char *read_line)
{
	t_token		*tokens;
	t_token		*new_token;
	char		**splitted_string;
	int			i;

	splitted_string = split_to_array(read_line);
	if (!splitted_string)
		return (NULL);
	tokens = NULL;
	i = 0;
	while (splitted_string[i])
	{
		new_token = (t_token *)ft_calloc(sizeof(t_token), 1);
		new_token->text = ft_strdup(splitted_string[i++]);
		add_token_to_back_of_list(&tokens, new_token);
	}
	free_strings_in_array(splitted_string);
	return (tokens);
}

t_token	*lexer_tokens(t_env *env, char *read_line)
{
	t_token		*tokens;

	if (!check_parantheses(read_line) || !check_quotes(read_line, env))
		return (NULL);
	tokens = tokenize(read_line);
	if (!tokens)
		return (NULL);
	tokens = handle_unexpected_input(tokens);
	if (!tokens)
		return (NULL);
	tokens = handle_wildcards(tokens);
	if (!tokens)
		return (NULL);
	tokens = deal_with_parameters(env, tokens);
	if (!tokens)
		return (NULL);
	tokens = count_pipes(tokens);
	return (tokens);
}
