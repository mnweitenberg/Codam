/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 13:50:09 by mweitenb          #+#    #+#             */
/*   Updated: 2022/03/05 13:38:14 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>
# include <string.h>

unsigned long	ft_atoi(const char *str);
void			*ft_calloc(size_t count, size_t size);
unsigned int	get_time(void);
unsigned int	get_time_elapsed(unsigned int time_start);
#endif
