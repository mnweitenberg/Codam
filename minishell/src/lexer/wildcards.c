/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   wildcards.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: marvin <marvin@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/30 14:44:37 by mweitenb      #+#    #+#                 */
/*   Updated: 2022/05/14 13:42:42 by mweitenb      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <dirent.h>
#include <stdbool.h>
#include "../../inc/lexer/lexer_utils.h"
#include "../../inc/lexer/wildcards_2.h"
#include "../../inc/utils/allocation.h"
#include "../../inc/utils/free.h"
#include "../../inc/utils/utils.h"
#include "../../inc/utils/str_compare.h"

static void	collect_all_filenames(char *filenames[])
{
	DIR				*d;
	struct dirent	*dir;
	int				i;

	i = 0;
	d = opendir(".");
	if (d)
	{
		dir = readdir(d);
		while (dir != NULL)
		{
			if (dir->d_name[0] != '.')
				filenames[i++] = ft_strdup(dir->d_name);
			dir = readdir(d);
		}
		closedir(d);
	}
	filenames[i] = NULL;
}

static bool	create_filename_tokens_and_add_to_list(t_token **new, char *token)
{
	t_token	*new_token;
	char	*filenames[255];
	int		i;
	int		succesfull;

	i = 0;
	collect_all_filenames(filenames);
	succesfull = 0;
	while (filenames[i])
	{
		if (check_filename_wildcard_criteria(filenames[i], token))
		{
			new_token = (t_token *)ft_calloc(sizeof(t_token), 1);
			new_token->text = ft_strdup(filenames[i]);
			add_token_to_back_of_list(new, new_token);
			succesfull++;
		}
		free(filenames[i]);
		i++;
	}
	if (succesfull)
		return (true);
	return (false);
}

t_token	*handle_wildcards(t_token *old)
{
	t_token	*new;
	t_token	*temp;
	t_token	*new_token;

	new = NULL;
	temp = old;
	while (old)
	{
		if (position_of_char_within_str('*', old->text) != -1)
		{
			if (!create_filename_tokens_and_add_to_list(&new, old->text))
			{
				new_token = (t_token *)ft_calloc(sizeof(t_token), 1);
				new_token->text = ft_strdup(old->text);
				add_token_to_back_of_list(&new, new_token);
			}
		}
		else
			add_token_to_back_of_list(&new, copy_token(old));
		old = old->next;
	}
	free_tokens(temp);
	return (new);
}
