/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   threads.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mweitenb <mweitenb@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/28 13:50:07 by mweitenb      #+#    #+#                 */
/*   Updated: 2022/02/28 13:50:07 by mweitenb      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef THREADS_H
# define THREADS_H

# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdio.h>
# include <unistd.h>

typedef struct s_main	t_main;
typedef struct s_philo	t_philo;

struct s_philo
{
	t_main			*m;
	int				id;
	int				count_meals_eaten;
	unsigned int	left_fork;
	unsigned int	right_fork;
	unsigned int	time_of_last_meal;
	pthread_t		*pthread_id;
	pthread_mutex_t	mutex_eating;
	pthread_mutex_t	mutex_time_last_meal;
};

struct s_main
{
	t_philo			**p;
	unsigned int	no_of_philo;
	unsigned int	time_to_die;
	unsigned int	time_to_eat;
	unsigned int	time_to_sleep;
	unsigned int	start_time;
	int				min_no_of_meals;
	unsigned long	timestamp_in_ms;
	pthread_mutex_t	mutex_message;
};

enum e_actions
{
	EAT		= 0,
	SLEEP	= 1,
	THINK	= 2,
	DIE		= 3
};

void			start_threads(t_main *m);

#endif
