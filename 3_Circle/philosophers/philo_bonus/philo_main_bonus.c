/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_main_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 03:30:04 by takwak            #+#    #+#             */
/*   Updated: 2025/03/17 17:15:20 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"
#include <pthread.h>

void	philo_main(t_philo *philo)
{
	if (pthread_create(&philo->tid, NULL, monitoring, (void *)philo))
		end_process(philo);
	if (philo->id % 2 == 0)
		philo_think(philo);
	while (1)
	{
		philo_take_fork(philo);
		philo_eat(philo);
		philo_sleep(philo);
		philo_think(philo);
		if (is_iam_end(philo))
			break ;
	}
	pthread_join(philo->tid, NULL);
	end_process(philo);
}
