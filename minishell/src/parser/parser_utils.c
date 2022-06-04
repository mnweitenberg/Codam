/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser_utils.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: marvin <marvin@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/11 14:54:11 by mweitenb      #+#    #+#                 */
/*   Updated: 2022/05/12 13:48:54 by mweitenb      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/parser/parser.h"
#include "../../inc/utils/allocation.h"
#include "../../inc/utils/str_compare.h"
#include "../../inc/utils/utils.h"

void	add_cmd_to_back_of_list(t_cmd **cmd, t_cmd *new)
{
	t_cmd	*temp;

	if (!*cmd)
		*cmd = new;
	else
	{	
		temp = *cmd;
		while (temp->next)
			temp = temp->next;
		temp->next = new;
		new->previous = temp;
	}
}

static char	*copy_string_without_char(char *src, char c)
{
	char	*dst;
	int		i;
	int		j;

	i = 0;
	j = 0;
	dst = (char *)ft_calloc(sizeof(char), ft_strlen(src) + 1);
	while (src[i])
	{
		if (src[i] == c)
			i++;
		else
			dst[j++] = src[i++];
	}
	return (dst);
}

char	*remove_quotes(char *src, int free_source)
{
	char	*dst;
	int		single_pos;
	int		double_pos;
	int		contains_parameter;

	dst = NULL;
	single_pos = position_of_char_within_str('\'', src);
	double_pos = position_of_char_within_str('"', src);
	contains_parameter = position_of_char_within_str('$', src);
	if (single_pos >= 0 && double_pos >= 0
		&& ((contains_parameter && single_pos > double_pos)
			|| (!contains_parameter && single_pos < double_pos)))
		dst = copy_string_without_char(src, '"');
	else if ((single_pos >= 0 && double_pos >= 0
			&& ((contains_parameter && single_pos < double_pos)
				|| (!contains_parameter && single_pos > double_pos)))
		|| (single_pos >= 0 && double_pos == -1))
		dst = copy_string_without_char(src, '\'');
	else if (single_pos == -1 && double_pos >= 0)
		dst = copy_string_without_char(src, '"');
	else
		dst = ft_strdup(src);
	if (free_source)
		free(src);
	return (dst);
}

void	add_pipe_to_back_of_list(t_pipes **pipe, t_pipes *new)
{
	t_pipes	*temp;

	if (!*pipe)
		*pipe = new;
	else
	{	
		temp = *pipe;
		while (temp->next)
			temp = temp->next;
		temp->next = new;
	}
}

int	get_total_amount_of_pipes(t_token *tokens)
{
	int		total_amount_of_pipes;
	t_token	*token;

	total_amount_of_pipes = 0;
	token = tokens;
	while (token->next)
		token = token->next;
	total_amount_of_pipes = token->pipe;
	return (total_amount_of_pipes);
}
