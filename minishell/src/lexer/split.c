/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   split.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: marvin <marvin@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/11 14:53:54 by mweitenb      #+#    #+#                 */
/*   Updated: 2022/04/19 16:45:31 by mweitenb      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../../inc/lexer/split.h"
#include "../../inc/lexer/split_utils.h"
#include "../../inc/utils/allocation.h"
#include "../../inc/utils/str_compare.h"

static int	count_no_of_strings(const char *str)
{
	int		count;
	int		i;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (is_operator(str[i]) || str[i] == '<' || str[i] == '>')
		{
			count++;
			i += deal_with_delimiters(&str[i]);
			continue ;
		}
		while (is_space(str[i]))
			i++;
		if (str[i] && !is_space(str[i]))
			count++;
		while (str[i] && !is_delimiter(str[i]))
			i++;
		if (str[i] == '"' || str[i] == '\'')
			i += deal_with_quotation_marks(&str[i]);
		if (str[i] == '$')
			i += deal_with_dollar_sign(&str[i]);
	}
	return (count);
}

static int	count_length_of_string(const char *str)
{
	int		i;

	i = 0;
	while (is_space(str[i]))
		i++;
	while (str[i] && !is_space(str[i]))
	{
		if (is_operator(str[i]) || str[i] == '<' || str[i] == '>')
		{
			if (i == 0)
				i += deal_with_delimiters(&str[i]);
			return (i);
		}
		if (str[i] == '"' || str[i] == '\'')
			return (i + deal_with_quotation_marks(&str[i]));
		if (str[i] == '$')
			return (i + deal_with_dollar_sign(&str[i]));
		i++;
	}
	return (i);
}

static char	*allocate_space_and_copy_str(const char **src, int len)
{
	char	*dst;
	int		i;
	int		j;

	if (!(*src))
		return (NULL);
	dst = (char *)ft_calloc(sizeof(char), (len + 1));
	i = 0;
	j = 0;
	while (is_space((*src)[i]))
		i++;
	while ((*src)[i] && i < len)
		dst[j++] = (*src)[i++];
	while (is_space((*src)[i]))
		i++;
	*src += i;
	return (dst);
}

char	**split_to_array(const char *str)
{
	char	**str_array;
	int		total_no_of_strings;
	int		i;
	int		len;

	if (!str)
		return (0);
	total_no_of_strings = count_no_of_strings(str);
	str_array = (char **)ft_calloc(sizeof(char *), (total_no_of_strings + 1));
	i = 0;
	while (i < total_no_of_strings)
	{
		if (is_space(str[0]))
			str++;
		len = count_length_of_string(str);
		if (len == 0)
			str_array[i] = NULL;
		else
			str_array[i] = allocate_space_and_copy_str(&str, len);
		i++;
	}
	str_array[i] = NULL;
	return (str_array);
}
