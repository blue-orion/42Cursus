/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_act_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 01:00:46 by takwak            #+#    #+#             */
/*   Updated: 2024/12/29 01:26:48 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo_bonus.h>

int	check_dead(t_philo *philo)
{
	pthread_mutex_lock(philo->flag_mutex);
	if (philo->flag)
	{
		pthread_mutex_unlock(philo->flag_mutex);
		return (1);
	}
	pthread_mutex_unlock(philo->flag_mutex);
	return (0);
}

void	*monitoring(void *data)
{
	t_philo *philo;

	philo = (t_philo *)data;
	while (1)
	{
		usleep(100);
		pthread_mutex_lock(philo->flag_mutex);
		if (is_philo_dead(philo))
		{
			philo->flag = DIE;
			break ;
		}
		if (philo->eat_cnt == philo->info->must_eat_count)
		{
			philo->flag = COMPLETE;
			break ;
		}
		pthread_mutex_unlock(philo->flag_mutex);
	}
	pthread_mutex_unlock(philo->flag_mutex);
	return (NULL);
}

void	start_action(t_philo *philo)
{
	int	end_status;

	pthread_create(&philo->tid, NULL, monitoring, (void *)philo);
	if (philo->id % 2 == 0)
		philo_think(philo);
	while (1)
	{
		while (philo->having_fork_num < 2)
			philo_take_fork(philo);
		if (philo->having_fork_num == 2)
			philo_eat(philo);
		if (philo->status == EAT)
			philo_sleep(philo);
		philo_think(philo);
		pthread_mutex_lock(philo->flag_mutex);
		if (philo->flag)
		{
			pthread_mutex_unlock(philo->flag_mutex);
			break ;
		}
		pthread_mutex_unlock(philo->flag_mutex);
	}
	if (philo->flag == DIE)
		exit(1);
	if (philo->flag == COMPLETE)
		exit(0);
}
