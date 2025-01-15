/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 18:17:42 by takwak            #+#    #+#             */
/*   Updated: 2025/01/15 15:47:15 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	*philo_routine(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	if (!(philo->id & 1))
	{
		philo_think(philo);
		usleep(500);
	}
	while (1)
	{
		if (philo_fork(philo))
			break ;
		if (philo_eat(philo))
			break ;
		if (philo_sleep(philo))
			break ;
		if (philo_think(philo))
			break ;
	}
	return (NULL);
}
