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

	elapsed_time = get_timestamp(p->m->start_time);
	pthread_mutex_lock(&p->m->mutex_message);
	if (action == EAT)
	{
		printf("%d\t%d has taken a fork\n", elapsed_time, p->id + 1);
		printf("%d\t%d is eating\n", elapsed_time, p->id + 1);
	}
	if (action == SLEEP)
		printf("%d\t%d is sleeping\n", elapsed_time, p->id + 1);
	if (action == THINK)
		printf("%d\t%d is thinking\n", elapsed_time, p->id + 1);
	if (action == DIE)
	{
		if (p->count_meals_eaten != p->m->min_no_of_meals)
			printf("%d\t%d died\n", elapsed_time, p->id + 1);
		return ;
	}
	pthread_mutex_unlock(&p->m->mutex_message);
}

static void	check_if_everyone_is_alive(t_main *m)
{
	unsigned int	time_since_last_meal;
	unsigned int	i;

	while (1)
	{
		i = 0;
		while (i < m->no_of_philo)
		{
			pthread_mutex_lock(&m->p[i]->mutex_time_last_meal);
			time_since_last_meal = get_timestamp(m->p[i]->time_of_last_meal);
			pthread_mutex_unlock(&m->p[i]->mutex_time_last_meal);
			if (time_since_last_meal > m->time_to_die)
			{
				print_message(m->p[i], DIE);
				return ;
			}
			i++;
		}
		ft_usleep(5);
	}
}

static void	*routine(void *arg)
{
	t_philo	*p;

	p = (t_philo *)arg;
	if (p->id % 2 == 1)
		usleep(250);
	while (p->count_meals_eaten != p->m->min_no_of_meals
		|| p->m->min_no_of_meals < 0)
	{
		pthread_mutex_lock(&p->m->p[p->left_fork]->mutex_eating);
		pthread_mutex_lock(&p->m->p[p->right_fork]->mutex_eating);
		print_message(p, EAT);
		pthread_mutex_lock(&p->mutex_time_last_meal);
		p->time_of_last_meal = get_time();
		pthread_mutex_unlock(&p->mutex_time_last_meal);
		ft_usleep(p->m->time_to_eat);
		p->count_meals_eaten += 1;
		pthread_mutex_unlock(&p->m->p[p->left_fork]->mutex_eating);
		pthread_mutex_unlock(&p->m->p[p->right_fork]->mutex_eating);
		print_message(p, SLEEP);
		ft_usleep(p->m->time_to_sleep);
		print_message(p, THINK);
		usleep(20);
	}
	return (NULL);
}

static void	destroy_mutexes_and_join_threads_and_free_mallocs(t_main *m)
{
	unsigned int	i;

	i = 0;
	ft_usleep(10);
	while (i < m->no_of_philo)
	{
		pthread_mutex_destroy(&m->p[i]->mutex_eating);
		pthread_mutex_destroy(&m->p[i]->mutex_time_last_meal);
		free(m->p[i]->pthread_id);
		free(m->p[i]);
		i++;
	}
	free(m->p);
}

void	start_threads(t_main *m)
{
	unsigned int	i;

	i = 0;
	m->start_time = get_time();
	while (i < m->no_of_philo)
	{
		if (pthread_create(m->p[i]->pthread_id, NULL,
				routine, (void *)m->p[i]) != 0)
			perror("Failed to create threath");
		i++;
	}
	if (i == m->no_of_philo)
		check_if_everyone_is_alive(m);
	destroy_mutexes_and_join_threads_and_free_mallocs(m);
}
