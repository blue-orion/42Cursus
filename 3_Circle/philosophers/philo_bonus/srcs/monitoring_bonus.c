/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 03:33:54 by takwak            #+#    #+#             */
/*   Updated: 2024/12/29 20:09:35 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo_bonus.h>

int	is_philo_dead(t_philo *philo)
{
	int	runtime;

	runtime = get_runtime(philo);
	if (runtime > philo->info->time_to_die)
	{
		sem_wait(philo->flag_sem->adr);
		philo->flag = DIE;
		philo->status = DIE;
		print_log(runtime, philo);
		sem_post(philo->flag_sem->adr);
		return (1);
	}
	return (0);
}

int	is_philo_eat_finish(t_philo *philo)
{
	sem_wait(philo->eat_cnt_sem->adr);
	printf("%d eat cnt = %d\n", philo->id, philo->eat_cnt);
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
		usleep(3000000);
		if (is_philo_dead(philo))
			break ;
		if (is_philo_eat_finish(philo))
			break ;
	}
	return (0);
}
