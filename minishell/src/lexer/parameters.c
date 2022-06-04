/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lexer.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: marvin <marvin@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/11 14:54:17 by mweitenb      #+#    #+#                 */
/*   Updated: 2022/05/16 22:37:20 by mweitenb      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../../inc/env/env.h"
#include "../../inc/parameter_expansion/parameter_expansion.h"
#include "../../inc/utils/utils.h"
#include "../../inc/utils/str_compare.h"

static int	position_of_parameter(const char *str)
{
	int	i;

	if (!str)
		return (-1);
	i = 0;
	while (str[i])
	{
		if (str[i] == '$' && !(!str[1 + i] || str[1 + i] == ' '))
			return (i);
		i++;
	}
	return (-1);
}

static int	there_are_parameters(const char *str)
{
	int	single_pos;
	int	double_pos;
	int	contains_parameter;

	if (!str)
		return (0);
	single_pos = position_of_char_within_str('\'', str);
	double_pos = position_of_char_within_str('"', str);
	contains_parameter = position_of_parameter(str);
	if (contains_parameter == -1)
		return (0);
	if (single_pos >= 0 && double_pos >= 0)
	{
		if (single_pos > double_pos)
			return (1);
		if (single_pos < double_pos)
			return (0);
	}
	if (str[contains_parameter + 1] == '"')
		return (0);
	if (single_pos == -1 && double_pos >= 0)
		return (1);
	if (single_pos == -1 && double_pos == -1 && contains_parameter >= 0)
		return (1);
	return (0);
}

t_token	*deal_with_parameters(t_env *env, t_token *tokens)
{
	t_token	*token;

	token = tokens;
	while (token)
	{
		while (there_are_parameters(token->text))
			token->text = handle_parameter_expansion(env, token->text);
		if (token->text == NULL)
		{
			printf("no value\n");
			exit(EXIT_FAILURE);
		}
		token = token->next;
	}
	return (tokens);
}
