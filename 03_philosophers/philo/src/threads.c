/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   threads.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mweitenb <mweitenb@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/23 18:08:50 by mweitenb      #+#    #+#                 */
/*   Updated: 2022/02/23 18:08:50 by mweitenb      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/threads.h"
#include "../inc/utils.h"

static void	print_message(t_philo *p, int action)
{
	int	elapsed_time;

	pthread_mutex_lock(&p->m->mutex_alive);
	if (!p->m->everyone_is_alive)
		exit(EXIT_SUCCESS);
	elapsed_time = get_time_elapsed(p->m->start_time);
	if (action == EAT)
	{
		printf("%d\t%d has taken a fork\n", elapsed_time, p->id);
		printf("%d\t%d is eating\n", elapsed_time, p->id);
	}
	if (action == SLEEP)
		printf("%d\t%d is sleeping\n", elapsed_time, p->id);
	if (action == THINK)
		printf("%d\t%d is thinking\n", elapsed_time, p->id);
	pthread_mutex_unlock(&p->m->mutex_alive);
}

static void	*check_if_everyone_is_alive(void *arg)
{
	unsigned int	time_since_last_meal;
	unsigned int	i;
	t_main			*m;

	m = (t_main *)arg;
	while (1)
	{
		i = 0;
		while (i < m->no_of_philo)
		{
			pthread_mutex_lock(&m->p[i]->mutex_time_last_meal);
			time_since_last_meal = get_time_elapsed(m->p[i]->time_of_last_meal);
			pthread_mutex_unlock(&m->p[i]->mutex_time_last_meal);
			if (time_since_last_meal >= m->time_to_die)
			{
				printf("%d\t%d died\n", get_time_elapsed(m->start_time),
					m->p[i]->id);
				exit(EXIT_SUCCESS);
			}
			i++;
		}
		usleep(5 * 1000);
	}
	return (NULL);
}

static void	*routine(void *arg)
{
	t_philo	*p;

	p = (t_philo *)arg;
	if (p->id % 2 == 1)
		usleep(500);
	while (p->count_meals_eaten != p->m->min_no_of_meals
		|| p->m->min_no_of_meals < 0)
	{
		pthread_mutex_lock(&p->m->p[p->left_fork]->mutex_eating);
		pthread_mutex_lock(&p->m->p[p->right_fork]->mutex_eating);
		print_message(p, EAT);
		pthread_mutex_lock(&p->mutex_time_last_meal);
		p->time_of_last_meal = get_time();
		pthread_mutex_unlock(&p->mutex_time_last_meal);
		usleep(p->m->time_to_eat * 1000);
		pthread_mutex_unlock(&p->m->p[p->left_fork]->mutex_eating);
		pthread_mutex_unlock(&p->m->p[p->right_fork]->mutex_eating);
		p->count_meals_eaten += 1;
		print_message(p, SLEEP);
		usleep(p->m->time_to_sleep * 1000);
		print_message(p, THINK);
		usleep(120);
	}
	exit(EXIT_SUCCESS);
}

static void	destroy_mutexes_and_join_threads_and_free_mallocs(t_main *m)
{
	unsigned int	i;

	i = 0;
	while (i < m->no_of_philo)
	{
		pthread_mutex_destroy(&m->p[i]->mutex_eating);
		pthread_mutex_destroy(&m->p[i]->mutex_time_last_meal);
		if (pthread_join(*m->p[i]->pthread_id, NULL) != 0)
			perror("Failed to join threath");
		free(m->p[i]->pthread_id);
		free(m->p[i]);
		i++;
	}
	if (pthread_join(*m->pthread_id_alive, NULL) != 0)
		perror("Failed to join threath");
	free(m->p);
}

void	start_threads(t_main *m)
{
	unsigned int	i;

	i = 0;
	if (pthread_create(m->pthread_id_alive, NULL,
			check_if_everyone_is_alive, (void *)m) != 0)
		perror("Failed to create threath");
	while (i < m->no_of_philo)
	{
		if (pthread_create(m->p[i]->pthread_id, NULL,
				routine, (void *)m->p[i]) != 0)
			perror("Failed to create threath");
		i++;
		usleep(75);
	}
	destroy_mutexes_and_join_threads_and_free_mallocs(m);
}
