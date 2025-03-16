/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyoengsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 21:02:12 by takwak            #+#    #+#             */
/*   Updated: 2025/03/16 21:06:14 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philo_routine(void *data)
{
	t_philo	*philo;
	int		status;

	philo = (t_philo *)data;
	if (philo->id % 2 == 0)
		philo_think(philo);
	while (1)
	{
		if (get_value(&philo->common->stop))
			break ;
		philo_fork(philo);
		philo_eat(philo);
		philo_sleep(philo);
		philo_think(philo);
	}
	//memory
	pthread_mutex_destroy(&philo->stop.lock);
	return (NULL);
}
