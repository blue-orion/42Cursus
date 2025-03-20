/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyoengsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 21:02:12 by takwak            #+#    #+#             */
/*   Updated: 2025/03/20 13:03:53 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philo_routine(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	if (philo->id % 2 == 0)
	{
		philo_think(philo);
		usleep(100 * philo->info->num_of_philo);
	}
	while (1)
	{
		if (get_value(&philo->common->stop))
			break ;
		philo_fork(philo);
		philo_eat(philo);
		philo_sleep(philo);
		philo_think(philo);
	}
	pthread_mutex_destroy(&philo->stop.lock);
	return (NULL);
}
