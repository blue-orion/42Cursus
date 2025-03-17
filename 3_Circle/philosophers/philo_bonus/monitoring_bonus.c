/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 03:33:54 by takwak            #+#    #+#             */
/*   Updated: 2025/03/17 17:15:23 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	is_philo_dead(t_philo *philo)
{
	int	runtime;

	runtime = get_runtime(philo, philo->last_eat_time);
	if (runtime > philo->info->time_to_die)
	{
		runtime = get_runtime(philo, philo->info->start_time);
		philo->status = DIE;
		print_log(runtime, philo);
		sem_wait(philo->flag_sem->adr);
		philo->flag = DIE;
		sem_post(philo->flag_sem->adr);
		sem_post(philo->common->fork_sem->adr);
		sem_post(philo->common->fork_sem->adr);
		return (1);
	}
	return (0);
}

int	is_philo_eat_finish(t_philo *philo)
{
	sem_wait(philo->eat_cnt_sem->adr);
	if (philo->eat_cnt == philo->info->must_eat_time)
	{
		sem_wait(philo->flag_sem->adr);
		philo->flag = FINISH;
		sem_post(philo->flag_sem->adr);
		sem_post(philo->eat_cnt_sem->adr);
		return (1);
	}
	sem_post(philo->eat_cnt_sem->adr);
	return (0);
}

void	*monitoring(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	while (1)
	{
		usleep(100);
		if (is_philo_dead(philo))
			break ;
		if (is_philo_eat_finish(philo))
			break ;
	}
	return (0);
}
