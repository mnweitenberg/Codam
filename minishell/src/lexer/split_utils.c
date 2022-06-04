/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   split_utils.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: marvin <marvin@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/11 14:53:54 by mweitenb      #+#    #+#                 */
/*   Updated: 2022/05/14 14:56:12 by mweitenb      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/utils/str_compare.h"
#include "../../inc/utils/utils.h"

int	deal_with_quotation_marks(const char *str)
{
	int		i;
	char	quote_sign;

	quote_sign = str[0];
	i = 1;
	i += position_of_char_within_str(quote_sign, &str[1]);
	if (str[i] != ' ')
	{
		while (str[i] && str[i] != ' ')
			i++;
	}
	return (i);
}

int	deal_with_dollar_sign(const char *str)
{
	int	i;

	if (ft_strncmp(str, "${", 2) == 0)
		return (position_of_char_within_str('}', str) + 1);
	i = 1;
	while ((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z')
		|| str[i] == '*' || str[i] == '_' || str[i] == '?' || str[i] == ':'
		|| str[i] == '$')
		i++;
	return (i);
}

int	deal_with_delimiters(const char *str)
{
	int	i;

	i = 2;
	if (ft_strncmp(str, "<<", 2) == 0
		|| ft_strncmp(str, ">>", 2) == 0
		|| ft_strncmp(str, "&&", 2) == 0
		|| ft_strncmp(str, "||", 2) == 0)
	{
		while (str[i] == '<' || str[i] == '>'
			|| str[i] == '&' || str[i] == '|')
		i++;
		return (i);
	}
	return (1);
}

int	is_delimiter(char c)
{
	if (is_space(c) || c == '"' || c == '\'' || c == '$' || c == '|'
		|| c == '<' || c == '>' || c == '&' || c == '(' || c == ')')
		return (1);
	return (0);
}
