/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   threads.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mweitenb <mweitenb@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/25 13:23:21 by mweitenb      #+#    #+#                 */
/*   Updated: 2022/02/25 13:23:21 by mweitenb      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/threads.h"
#include "../inc/utils.h"

static void	print_message(t_philo *p, int action)
{
	int	elapsed_time;

	sem_wait(p->m->sem_alive);
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
	sem_post(p->m->sem_alive);
}

static void	*check_if_philo_is_alive(void *arg)
{
	unsigned int	time_since_last_meal;
	t_philo			*p;

	p = (t_philo *)arg;
	while (1)
	{
		sem_wait(p->sem_time_last_meal);
		time_since_last_meal = get_time_elapsed(p->time_of_last_meal);
		if (time_since_last_meal > p->m->time_to_die)
		{
			sem_wait(p->m->sem_alive);
			p->m->everyone_is_alive = false;
			printf("%d\t%d died\n", get_time_elapsed(p->m->start_time), p->id);
			exit(EXIT_SUCCESS);
		}
		sem_post(p->sem_time_last_meal);
		usleep(1000);
	}
	return (NULL);
}

static void	routine(t_philo *p)
{
	while (p->count_meals_eaten != p->m->min_no_of_meals
		|| p->m->min_no_of_meals < 0)
	{
		sem_wait(p->m->sem_forks);
		sem_wait(p->m->sem_forks);
		print_message(p, EAT);
		sem_wait(p->sem_time_last_meal);
		p->time_of_last_meal = get_time();
		sem_post(p->sem_time_last_meal);
		usleep(p->m->time_to_eat * 1000);
		sem_post(p->m->sem_forks);
		sem_post(p->m->sem_forks);
		p->count_meals_eaten += 1;
		print_message(p, SLEEP);
		usleep(p->m->time_to_sleep * 1000);
		print_message(p, THINK);
		usleep(500);
	}
	exit(EXIT_SUCCESS);
}

static void	waitpid_and_kill_processes_and_free_mallocs(t_main *m)
{
	int				status;
	unsigned int	i;

	i = 0;
	waitpid(-1, &status, 0);
	if (WIFEXITED(status) || WIFSIGNALED(status))
	{
		while (i < m->no_of_philo)
		{
			kill(m->p[i]->pid, SIGKILL);
			free(m->p[i]->pthread_id);
			free(m->p[i]);
			i++;
		}
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
		m->p[i]->pid = fork();
		m->p[i]->time_of_last_meal = get_time();
		if (m->p[i]->pid == 0)
		{
			if (pthread_create(m->p[i]->pthread_id, NULL,
					check_if_philo_is_alive, (void *)m->p[i]) != 0)
				perror("Failed to create threath");
			routine(m->p[i]);
		}
		i++;
		usleep(75);
	}
	waitpid_and_kill_processes_and_free_mallocs(m);
}
