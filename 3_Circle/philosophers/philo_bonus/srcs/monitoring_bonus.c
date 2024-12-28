/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 03:33:54 by takwak            #+#    #+#             */
/*   Updated: 2024/12/29 04:25:39 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo_bonus.h>

int	is_philo_dead(t_philo *philo)
{
	int	runtime;

	pthread_mutex_lock(&philo->mutex->time_mutex);
	gettimeofday(&philo->cur_time, NULL);
	runtime = get_runtime(philo->cur_time, philo->last_eat_time);
	if (runtime > philo->info->time_to_die)
	{
		runtime = get_runtime(philo->cur_time, philo->info->start_time);
		pthread_mutex_lock(&philo->mutex->status_mutex);
		set_status(philo, DIE);
		print_log(runtime, philo->id, philo->status, philo->common->print_sem);
		pthread_mutex_unlock(&philo->mutex->status_mutex);
		pthread_mutex_unlock(&philo->mutex->time_mutex);
		return (1);
	}
	pthread_mutex_unlock(&philo->mutex->time_mutex);
	return (0);
}

void	*monitoring(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	while (1)
	{
		if (is_philo_dead(philo))
			break ;
		pthread_mutex_lock(&philo->mutex->eat_cnt_mutex);
		if (philo->eat_cnt == philo->info->must_eat_time)
		{
			pthread_mutex_unlock(&philo->mutex->eat_cnt_mutex);
			break ;
		}
		pthread_mutex_unlock(&philo->mutex->eat_cnt_mutex);
	}
	return (0);
}
