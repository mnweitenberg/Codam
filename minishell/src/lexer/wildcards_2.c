/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   wildcards_2.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: marvin <marvin@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/30 14:44:37 by mweitenb      #+#    #+#                 */
/*   Updated: 2022/05/16 15:44:15 by mweitenb      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdbool.h>
#include "../../inc/utils/allocation.h"
#include "../../inc/utils/utils.h"
#include "../../inc/utils/str_compare.h"

bool	check_filename_wildcard_criteria(char *file, char *token);

static int	look_for_str_in_str(const char *little, const char *big, size_t len)
{
	unsigned int		i;

	i = 0;
	if (!big[i])
		return (-1);
	while (big[i])
	{
		if (ft_strncmp(&big[i], little, len) == 0)
			return (i + len);
		i++;
	}
	return (0);
}

static char	*get_token_subset_before_dollar_sign(char *token)
{
	int		wildcard_position;
	char	*pre_wildcard;

	wildcard_position = position_of_char_within_str('*', token);
	if (wildcard_position == -1)
		return (NULL);
	pre_wildcard = (char *)ft_calloc(sizeof(char), wildcard_position + 1);
	ft_strlcpy(pre_wildcard, token, wildcard_position + 1);
	return (pre_wildcard);
}

static int	compare_file_with_str_before_dollar(
	char *file, char *token, char *pre_wildcard)
{
	if (ft_strncmp(file, pre_wildcard, ft_strlen(pre_wildcard)) == 0
		&& !ft_strlen(token))
		return (true);
	else if (ft_strncmp(file, pre_wildcard, ft_strlen(pre_wildcard)) == 0
		&& ft_strlen(token))
	{
		file += ft_strlen(pre_wildcard);
		return (check_filename_wildcard_criteria(file,
				&token[position_of_char_within_str('*', token)]));
	}
	return (false);
}

static int	compare_file_with_str_after_dollar(char *file, char *token)
{
	int		wildcard_position;

	wildcard_position = position_of_char_within_str('*', token);
	if (wildcard_position == -1
		&& look_for_str_in_str(token, file,
			ft_max(ft_strlen(file), ft_strlen(token))) > 0)
		return (true);
	else if (wildcard_position >= 0
		&& look_for_str_in_str(token, file, wildcard_position) > 0)
	{
		file += look_for_str_in_str(token, file, wildcard_position);
		return (check_filename_wildcard_criteria(file,
				&token[wildcard_position]));
	}
	return (false);
}

bool	check_filename_wildcard_criteria(char *file, char *token)
{
	char	*pre;
	int		return_value;
	int		wildcard_position;

	return_value = 0;
	if (ft_strncmp(token, "*", 2) == 0 && ft_strlen(file) > 0)
		return (true);
	wildcard_position = position_of_char_within_str('*', token);
	if (wildcard_position == -1)
		return (NULL);
	pre = get_token_subset_before_dollar_sign(token);
	token += wildcard_position + 1;
	if (!ft_strlen(pre) && !ft_strlen(token))
		return_value = false;
	else if (ft_strlen(pre))
		return_value = compare_file_with_str_before_dollar(file, token, pre);
	if (ft_strlen(token)
		&& ((ft_strlen(pre) && return_value)
			|| (!ft_strlen(pre) && !return_value)))
		return_value = compare_file_with_str_after_dollar(file, token);
	free(pre);
	return (return_value);
}
