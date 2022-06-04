/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   handle_environment_variables.c                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mweitenb <mweitenb@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/14 12:26:33 by mweitenb      #+#    #+#                 */
/*   Updated: 2022/03/14 12:26:33 by mweitenb      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "../../inc/parameter_expansion/parameter_expansion.h"
#include "../../inc/parameter_expansion/parameter_expansion_2.h"
#include "../../inc/parameter_expansion/parameter_expansion_3.h"
#include "../../inc/utils/allocation.h"
#include "../../inc/utils/utils.h"

static char	*get_string_that_follows_var(char *src)
{
	int		length_of_var;
	int		len_of_str_post_var;
	char	*dst;

	length_of_var = get_length_of_var(src);
	len_of_str_post_var = ft_strlen(src) - length_of_var + 1;
	if (len_of_str_post_var <= 0)
		return (NULL);
	dst = (char *)ft_calloc(sizeof(char), len_of_str_post_var);
	ft_strlcpy(dst, &src[length_of_var], len_of_str_post_var);
	return (dst);
}

static char	*merge_strings(char *old, char *buffer)
{
	int		old_len;
	int		buf_len;
	char	*new;

	old_len = ft_strlen(old);
	buf_len = ft_strlen(buffer);
	new = (char *)ft_calloc(sizeof(char), old_len + buf_len + 1);
	if (!old)
	{
		ft_strlcpy(new, buffer, buf_len + 1);
		free(buffer);
	}
	else if (!buffer)
	{
		ft_strlcpy(new, old, old_len + 1);
		free(old);
	}
	else
	{
		ft_strlcpy(new, old, old_len + 1);
		ft_strlcpy(&new[old_len], buffer, buf_len + 1);
		free(old);
		free(buffer);
	}
	return (new);
}

char	*handle_parameter_expansion(t_env *env, char *src)
{
	int		start_of_var;
	char	*var;
	char	*post;
	char	*dst;

	start_of_var = position_of_char_within_str('$', src);
	var = expanse_parameter(env, &src[start_of_var]);
	if (!var)
	{
		free(src);
		return (NULL);
	}
	post = get_string_that_follows_var(src);
	dst = (char *)ft_calloc(sizeof(char),
			start_of_var + ft_strlen(var) + ft_strlen(post) + 1);
	if (start_of_var > 0)
		ft_strlcpy(dst, src, start_of_var + 1);
	dst = merge_strings(dst, var);
	dst = merge_strings(dst, post);
	free(src);
	return (dst);
}
