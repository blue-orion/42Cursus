/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyoengsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 21:02:12 by takwak            #+#    #+#             */
/*   Updated: 2025/03/14 18:31:12 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philo_routine(void *data)
{
	t_philo	*philo;
	int		status;

	philo = (t_philo *)data;
	if (philo->id % 2)
		usleep(100);
	printf("id = %d\n", philo->id);
	status = get_value(&philo->stop);
	while (status != DIE)
	{
		philo_fork(philo);
		philo_eat(philo);
		philo_sleep(philo);
		philo_think(philo);
	}
	//memory
	return (NULL);
}
