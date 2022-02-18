/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   split.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: marvin <marvin@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/13 13:37:21 by mweitenb      #+#    #+#                 */
/*   Updated: 2022/02/17 16:53:29 by mweitenb      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

static int	str_contains_quotation_marks(const char *str, char delimiter)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != delimiter)
	{
		if (str[i] == '\'' || str[i] == '\"')
			return (1);
		i++;
	}
	return (0);
}

static int	count_no_of_strings(const char *str, char delimiter)
{
	int		count;

	count = 0;
	while (*str)
	{
		while (*str == delimiter)
			str++;
		if (*str != delimiter && *str)
			count++;
		if (*str == '\'' || *str == '\"')
		{
			str++;
			while (*str != '\'' && *str != '\"' && *str)
			{
				str++;
			}
			str++;
		}
		while (*str != delimiter && *str)
			str++;
	}
	return (count);
}

static int	count_length_of_string(const char *str, char delimiter)
{
	int	i;

	i = 0;
	if (str_contains_quotation_marks(str, delimiter))
	{
		while (str[i] && (str[i] == '\'' || str[i] == '\"'))
			i++;
		while (str[i] && str[i] != '\'' && str[i] != '\"')
			i++;
		while (str[i] && (str[i] == '\'' || str[i] == '\"'))
			i++;
	}
	while (str[i] && str[i] != delimiter)
		i++;
	return (i);
}

static char	*allocate_space_and_copy_str(char const *str, char delimiter)
{
	int		i;
	int		j;
	int		len;
	char	*ptr;
	char	quotation_char;

	len = count_length_of_string(str, delimiter);
	ptr = (char *)malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (NULL);
	i = 0;
	j = 0;
	if (str[0] == '\'' || str[0] == '\"')
		quotation_char = str[0];
	while (j < len)
	{
		if (str[j] == quotation_char)
			j++;
		ptr[i] = str[j];
		i++;
		j++;
	}
	ptr[i] = 0;
	return (ptr);
}

char	**split_to_array(char const *str, char delimiter)
{
	char	**str_array;
	int		total_no_of_strings;
	int		i;

	if (!str)
		return (0);
	total_no_of_strings = count_no_of_strings(str, delimiter);
	str_array = (char **)malloc(sizeof(char *) * (total_no_of_strings + 1));
	if (!str_array)
		handle_malloc_array(str_array);
	i = 0;
	while (i < total_no_of_strings)
	{
		if (str[0] == delimiter)
			str++;
		str_array[i] = allocate_space_and_copy_str(str, delimiter);
		if (!(str_array[i]))
			handle_malloc_array(str_array);
		if (str_contains_quotation_marks(str, delimiter))
			str += 2;
		str += ft_strlen(str_array[i++]);
	}
	str_array[i] = NULL;
	return (str_array);
}
