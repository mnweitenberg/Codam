/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mweitenb <mweitenb@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/25 13:23:19 by mweitenb      #+#    #+#                 */
/*   Updated: 2022/02/25 13:23:19 by mweitenb      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/utils.h"

unsigned long	ft_atoi(const char *str)
{
	unsigned long	nbr;

	nbr = 0;
	while (*str >= '0' && *str <= '9')
	{
		nbr *= 10;
		nbr += *str++ - '0';
	}
	return (nbr);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*ret;

	ret = malloc(count * size);
	if (!ret)
		exit(EXIT_FAILURE);
	return (memset(ret, 0, count * size));
}

unsigned int	get_time(void)
{
	static struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * (unsigned int)1000) + (tv.tv_usec / 1000));
}

unsigned int	get_timestamp(unsigned int time_start)
{
	unsigned int	time_now;
	unsigned int	time_elapsed;

	time_now = get_time();
	time_elapsed = time_now - time_start;
	return (time_elapsed);
}

void	ft_usleep(unsigned int time_in_ms)
{
	unsigned int	start_time;

	start_time = get_time();
	while ((get_time() - start_time) < time_in_ms)
		usleep(250);
}
