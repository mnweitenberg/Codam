/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mweitenb <mweitenb@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/25 13:23:24 by mweitenb      #+#    #+#                 */
/*   Updated: 2022/02/25 13:23:24 by mweitenb      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/main.h"
#include "../inc/threads.h"
#include "../inc/utils.h"

static int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

static int	every_argv_is_digits(char **argv)
{
	int		i;
	int		j;

	i = 1;
	while (argv[i])
	{
		if (ft_atoi(argv[i]) > INT_MAX)
			return (0);
		j = 0;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static void	init_philosophers(t_main *m)
{
	unsigned int	i;

	i = 0;
	while (i < m->no_of_philo)
	{
		m->p[i] = (t_philo *)ft_calloc(sizeof(t_philo), 1);
		m->p[i]->pthread_id = ft_calloc(sizeof(pthread_t), 1);
		m->p[i]->id = i;
		m->p[i]->m = m;
		sem_unlink("time_last_meal");
		m->p[i]->sem_time_last_meal = sem_open("time_last_meal", O_CREAT, 0644, 1);
		if (m->p[i]->sem_time_last_meal == SEM_FAILED)
			exit(EXIT_FAILURE);
		i++;
	}
}

static void	init_main(t_main *m, int argc, char **argv)
{
	m->no_of_philo = ft_atoi(argv[1]);
	m->time_to_die = ft_atoi(argv[2]);
	m->time_to_eat = ft_atoi(argv[3]);
	m->time_to_sleep = ft_atoi(argv[4]);
	m->min_no_of_meals = -1;
	m->everyone_is_alive = true;
	if (argc == 6)
		m->min_no_of_meals = ft_atoi(argv[5]);
	sem_unlink("forks");
	m->sem_forks = sem_open("forks", O_CREAT, 0644, m->no_of_philo);
	if (m->sem_forks == SEM_FAILED)
		exit(EXIT_FAILURE);
	sem_unlink("alive");
	m->sem_alive = sem_open("alive", O_CREAT, 0644, 1);
	if (m->sem_alive == SEM_FAILED)
		exit(EXIT_FAILURE);
	m->p = (t_philo **)ft_calloc(m->no_of_philo, sizeof(t_philo));
}

int	main(int argc, char **argv)
{
	t_main	m;

	if (argc < 5 || argc > 6 || !every_argv_is_digits(argv))
	{
		printf("Error: please provide the right amount of arguments in the ");
		printf("following format: \n./philo_bonus [number_of_philosophers] ");
		printf("[time_to_die] [time_to_eat] [time_to_sleep] ");
		printf("[number_of_times_each_philosopher_must_eat] \n");
		printf("All arguments are in miliseconds, ");
		printf("the last argument is optional.\n");
		exit(EXIT_FAILURE);
	}
	init_main(&m, argc, argv);
	init_philosophers(&m);
	start_threads(&m);
	return (0);
}
