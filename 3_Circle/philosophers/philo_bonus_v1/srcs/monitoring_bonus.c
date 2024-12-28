/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 18:15:05 by takwak            #+#    #+#             */
/*   Updated: 2024/12/29 01:41:13 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo_bonus.h>

int	is_philo_dead(t_philo *philo)
{
	int	tmp;
	int	runtime;

	pthread_mutex_lock(philo->time_mutex);
	gettimeofday(&philo->dead_time, NULL);
	runtime = get_runtime(philo->dead_time, philo->last_eat_time);
	if (runtime > philo->info->time_to_die)
	{
		philo->status = DIE;
		runtime = get_runtime(philo->dead_time, philo->common->start_time);
		print_log(philo, runtime);
		pthread_mutex_unlock(philo->time_mutex);
		return (-1);
	}
	pthread_mutex_unlock(philo->time_mutex);
	return (0);
}

void	kill_all_philo(t_philo *philos)
{
	int	i;

	i = 0;
	while (i < philos->info->num_of_philo)
	{
		kill(philos[i].pid, SIGKILL);
		i++;
	}
	// sem_post(philos->common->print_sem);
}

int	wait_end_philo(t_philo *philos)
{
	int	i;
	int	status;

	i = 0;
	while (i < philos->info->num_of_philo)
	{
		waitpid(0, &status, 0);
		if (status)
		{
			kill_all_philo(philos);
			return (1);
		}
		i++;
	}
	return (1);
}
