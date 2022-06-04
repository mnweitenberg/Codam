/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   allocation.h                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: marvin <marvin@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/11 14:58:59 by mweitenb      #+#    #+#                 */
/*   Updated: 2022/05/11 16:34:42 by mweitenb      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALLOCATION_H
# define ALLOCATION_H

# include <stdlib.h>
# include "../../inc/lexer/lexer.h"
# include "../../inc/parser/parser.h"

void	*ft_calloc(size_t size, size_t count);
char	*ft_strdup(const char *s);
void	*ft_memset(void *s, int c, size_t n);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
char	*ft_itoa(int num);

#endif