/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 19:44:45 by takwak            #+#    #+#             */
/*   Updated: 2025/03/17 21:17:52 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	end_process(t_philo *philo);

void	philo_routine(t_philo *philo)
{
	if (philo->id % 2 == 0)
		philo_think(philo);
	while (1)
	{
		if (get_value(&philo->common->end))
			break ;
		printf("\nend = %d\n", get_value(&philo->common->end));
		philo_fork(philo);
		philo_eat(philo);
		philo_sleep(philo);
		philo_think(philo);
	}
	end_process(philo);
}

void	end_process(t_philo *philo)
{
	ft_sem_destroy(philo->common->fork, "/fork");
	ft_sem_destroy(philo->common->print, "/print");
	ft_sem_destroy(philo->common->end.lock, "/end");
	ft_sem_destroy(philo->stop.lock, philo->stop_sem_name);
	exit(EXIT_SUCCESS);
}
