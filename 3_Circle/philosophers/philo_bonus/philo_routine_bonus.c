/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 19:44:45 by takwak            #+#    #+#             */
/*   Updated: 2025/03/20 13:05:07 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	end_process(t_philo *philo, int idx);
void	*check_die_thread(void *data);
int		get_die_value(t_philo *philo);

void	philo_routine(t_philo *philos, int idx)
{
	t_philo		*philo;
	int			status;
	pthread_t	tid;

	philo = &philos[idx];
	pthread_create(&tid, NULL, check_die_thread, philo);
	if (philo->id % 2 == 0)
	{
		philo_think(philo);
		usleep(100 * philo->info->num_of_philo);
	}
	while (1)
	{
		status = have_to_stop(philo);
		if (status)
			break ;
		philo_fork(philo);
		philo_eat(philo);
		philo_sleep(philo);
		philo_think(philo);
	}
	pthread_join(tid, NULL);
	end_process(philos, idx);
	free(philos);
	exit(status);
}

void	end_process(t_philo *philos, int idx)
{
	int	i;

	sem_close(philos->common->fork);
	sem_close(philos->common->print);
	i = 0;
	while (i <= idx)
		sem_close(philos[i++].die);
}

void	*check_die_thread(void *data)
{
	t_philo	*philo;
	int		runtime;
	int		value;

	philo = (t_philo *)data;
	while (1)
	{
		value = get_die_value(philo);
		if (value)
			break ;
		sem_wait(philo->die);
		runtime = get_runtime(philo->last_eat_time);
		sem_post(philo->die);
		if (runtime >= philo->info->time_to_die)
		{
			sem_wait(philo->die);
			philo->die_value = DIE;
			sem_post(philo->die);
			print_log(philo, get_runtime(philo->info->start_time), DIE);
			sem_wait(philo->common->print);
			exit(DIE);
		}
		usleep(200);
	}
	return (NULL);
}

int	get_die_value(t_philo *philo)
{
	int	value;

	sem_wait(philo->die);
	value = philo->die_value;
	sem_post(philo->die);
	return (value);
}
