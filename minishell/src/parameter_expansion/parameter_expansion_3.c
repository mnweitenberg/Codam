/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parameter_expansion_3.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 21:58:05 by mweitenb          #+#    #+#             */
/*   Updated: 2022/05/13 17:34:17 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/env/env_utils.h"
#include "../../inc/parameter_expansion/parameter_expansion_3.h"
#include "../../inc/utils/allocation.h"
#include "../../inc/utils/utils.h"

char	*get_parameter_name(t_env *env, char *src)
{
	int	i;
	int	start;

	i = 0;
	while (src[i]
		&& (src[i] == '$' || src[i] == '{' || src[i] == '\'' || src[i] == '\"'))
		i++;
	start = i;
	while (src[i] && src[i] != '}' && src[i] != ':' && src[i] != '-'
		&& src[i] != '=' && src[i] != '?' && src[i] != '+'
		&& src[i] != '\'' && src[i] != '\"'
		&& src[i] != '$')
		i++;
	return (get_variable_from_env(env, &src[start], i - start));
}

void	get_symbol(char symbol[3], char *src)
{
	int	i;
	int	j;

	ft_memset(symbol, '\0', 3);
	i = 0;
	j = 0;
	while (src[i] && src[i] != ':' && src[i] != '-'
		&& src[i] != '=' && src[i] != '?' && src[i] != '+')
		i++;
	while (src[i] && (src[i] == ':' || src[i] == '-'
			|| src[i] == '=' || src[i] == '?' || src[i] == '+'))
		symbol[j++] = src[i++];
}

char	*get_word_value(char *src)
{
	int		i;

	i = 0;
	while (src[i] && src[i] != ':' && src[i] != '-'
		&& src[i] != '=' && src[i] != '?' && src[i] != '+')
		i++;
	while (src[i] && (src[i] == ':' || src[i] == '-'
			|| src[i] == '=' || src[i] == '?' || src[i] == '+'))
		i++;
	return (&src[i]);
}

char	*duplicate_without_ending_curly_bracket(const char *src)
{
	char	*dst;
	int		i;

	i = 0;
	while (src[i] && src[i] != '}')
		i++;
	dst = (char *)ft_calloc(i + 1, sizeof(char));
	i = 0;
	while (src[i] && src[i] != '}')
	{
		dst[i] = src[i];
		i++;
	}
	return (dst);
}

int	get_length_of_var(char *str)
{
	int	j;
	int	i;

	i = 0;
	j = position_of_char_within_str(':', str);
	while (str[i] && str[i] != '$')
		i++;
	if (str[i] == '$')
		i++;
	if (j >= 0 && str[j + 1] != '-' && str[j + 1] != '+'
		&& str[j + 1] != '?' && str[j + 1] != '=')
	{
		while (str[i] && str[i] != ':' && str[i] != '}'
			&& str[i] != '"' && str[i] != '\'')
			i++;
	}
	else
	{
		while (str[i] && str[i] != '}' && str[i] != '"' && str[i] != '\''
			&& str[i] != '$')
			i++;
	}
	if (str[i] == '}')
		i++;
	return (i);
}
