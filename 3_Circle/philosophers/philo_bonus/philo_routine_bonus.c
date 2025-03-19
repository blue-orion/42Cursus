/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 19:44:45 by takwak            #+#    #+#             */
/*   Updated: 2025/03/19 16:52:34 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	end_process(t_philo *philo);
void	*philo_monitor(void *data);

void	philo_routine(t_philo *philos, int idx)
{
	t_philo	*philo;
	int		status;

	philo = &philos[idx];
	philo->died = 0;
	if (philo->id % 2 == 0)
		philo_think(philo);
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
	end_process(philo);
	free(philos);
	exit(status);
}

void	end_process(t_philo *philo)
{
	sem_close(philo->common->fork);
	sem_close(philo->common->print);
}
