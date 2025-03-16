/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_resources.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyoengsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 19:07:39 by takwak            #+#    #+#             */
/*   Updated: 2025/03/16 20:09:17 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_resources(t_philo *philo)
{
	fork_mutex_destroy(philo->common->fork, philo->info->num_of_philo - 1);
	pthread_mutex_destroy(&philo->common->print.lock);
	pthread_mutex_destroy(&philo->common->stop.lock);
	free(philo);
}

void	fork_mutex_destroy(t_mutex *fork, int i)
{
	while (i >= 0)
	{
		pthread_mutex_destroy(&fork[i].lock);
		i--;
	}
	free(fork);
}
