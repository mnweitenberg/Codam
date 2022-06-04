/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mweitenb <mweitenb@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/14 12:28:37 by mweitenb      #+#    #+#                 */
/*   Updated: 2022/03/14 21:55:45 by mweitenb      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../../inc/utils/allocation.h"
#include "../../inc/utils/utils.h"

int	count_no_of_strings(const char *str, char delimiter)
{
	int		count;

	count = 0;
	while (*str)
	{
		while (*str == delimiter)
			str++;
		if (*str != delimiter && *str)
			count++;
		while (*str != delimiter && *str)
			str++;
	}
	return (count);
}

static int	count_length_of_string(const char *str, char delimiter)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != delimiter)
		i++;
	return (i);
}

static char	*allocate_space_and_copy_str(char const *str, char delimiter)
{
	int		len;
	char	*ptr;

	len = count_length_of_string(str, delimiter);
	ptr = (char *)ft_calloc(sizeof(char), (len + 1));
	ft_strlcpy(ptr, str, len + 1);
	return (ptr);
}

char	**ft_split(char const *str, char delimiter)
{
	char	**str_array;
	int		total_no_of_strings;
	int		i;

	if (!str)
		return (0);
	total_no_of_strings = count_no_of_strings(str, delimiter);
	str_array = (char **)ft_calloc(sizeof(char *), (total_no_of_strings + 1));
	i = 0;
	while (i < total_no_of_strings)
	{
		if (str[0] == delimiter)
			str++;
		str_array[i] = allocate_space_and_copy_str(str, delimiter);
		str += ft_strlen(str_array[i++]);
	}
	str_array[i] = NULL;
	return (str_array);
}
