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
# include <sys/wait.h>
# include <stdio.h>
# include <unistd.h>
# include <semaphore.h>
# include <signal.h>
# include <stdbool.h>

typedef struct s_main	t_main;
typedef struct s_philo	t_philo;

struct s_philo
{
	t_main			*m;
	int				id;
	int				count_meals_eaten;
	unsigned int	pid;
	pthread_t		*pthread_id;
	int				time_of_last_meal;
	sem_t			*sem_time_last_meal;
};

struct s_main
{
	t_philo			**p;
	unsigned int	no_of_philo;
	unsigned int	time_to_die;
	unsigned int	time_to_eat;
	unsigned int	time_to_sleep;
	unsigned int	pid_alive;
	unsigned int	start_time;
	int				min_no_of_meals;
	pthread_t		*pthread_alive;
	bool			everyone_is_alive;
	sem_t			*sem_alive;
	sem_t			*sem_forks;
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
