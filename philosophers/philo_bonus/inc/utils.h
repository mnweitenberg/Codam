/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: marvin <marvin@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/28 13:50:09 by mweitenb      #+#    #+#                 */
/*   Updated: 2022/05/02 19:01:22 by mweitenb      ########   odam.nl         */
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
unsigned int	get_timestamp(unsigned int time_start);
void			ft_usleep(unsigned int time_in_ms);

#endif
