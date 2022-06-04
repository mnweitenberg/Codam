/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parameter_expansion_2.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: marvin <marvin@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/23 20:30:36 by mweitenb      #+#    #+#                 */
/*   Updated: 2022/05/12 12:45:32 by mweitenb      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../../inc/utils/allocation.h"
#include "../../inc/utils/str_compare.h"
#include "../../inc/parameter_expansion/parameter_expansion_3.h"
#include "../../inc/env/env_utils.h"

static char	*handle_minus(char *parameter, char *symbol, char *word)
{
	if (ft_strncmp(symbol, ":-", 2) == 0 && parameter && *parameter)
		return (ft_strdup(parameter));
	if (ft_strncmp(symbol, "-", 1) == 0 && parameter)
		return (ft_strdup(parameter));
	return (duplicate_without_ending_curly_bracket(word));
}

static char	*handle_equal(t_env *env, char *parameter, char *symbol, char *word)
{
	if (ft_strncmp(symbol, ":=", 2) == 0 && parameter && *parameter)
		return (ft_strdup(parameter));
	if (ft_strncmp(symbol, "=", 1) == 0 && parameter)
		return (ft_strdup(parameter));
	add_var_to_env(env, parameter, word);
	return (duplicate_without_ending_curly_bracket(word));
}

static char	*handle_questionmark(char *parameter, char *symbol)
{
	if (ft_strncmp(symbol, ":?", 2) == 0 && parameter && *parameter)
		return (ft_strdup(parameter));
	if (ft_strncmp(symbol, "?", 1) == 0 && parameter)
		return (ft_strdup(parameter));
	return (NULL);
}

static char	*handle_plus(char *parameter, char *symbol, char *word)
{
	if (ft_strncmp(symbol, ":+", 2) == 0 && parameter && *parameter)
		return (duplicate_without_ending_curly_bracket(word));
	if (ft_strncmp(symbol, "+", 1) == 0)
	{
		if (parameter)
			return (ft_strdup(parameter));
		if (!parameter)
			return (NULL);
	}
	if (parameter)
		return (ft_strdup(parameter));
	return (ft_strdup(""));
}

char	*expanse_parameter(t_env *env, char *src)
{
	char	symbol[3];
	char	*parameter;
	char	*word;

	parameter = get_parameter_name(env, src);
	if (!parameter && !src[1])
		return (ft_strdup("$"));
	get_symbol(symbol, src);
	word = get_word_value(src);
	if (parameter && !symbol[0])
		return (ft_strdup(parameter));
	if (src[1] == '{')
	{
		if (symbol[0] == '-' || symbol[1] == '-')
			return (handle_minus(parameter, symbol, word));
		else if (symbol[0] == '=' || symbol[1] == '=')
			return (handle_equal(env, parameter, symbol, word));
		else if (symbol[0] == '?' || symbol[1] == '?')
			return (handle_questionmark(parameter, symbol));
		else if (symbol[0] == '+' || symbol[1] == '+')
			return (handle_plus(parameter, symbol, word));
	}
	if (parameter)
		return (ft_strdup(parameter));
	return (ft_strdup(""));
}
