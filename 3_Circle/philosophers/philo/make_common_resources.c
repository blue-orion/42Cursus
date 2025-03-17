/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_common_resources.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyoengsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 16:35:20 by takwak            #+#    #+#             */
/*   Updated: 2025/03/17 16:23:56 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int		make_forks(t_common *common, t_info info);

int	make_common_resources(t_common *common, t_info info)
{
	if (make_forks(common, info))
		return (1);
	if (pthread_mutex_init(&common->stop.lock, NULL))
	{
		destroy_fork_mutex(common->fork, info.num_of_philo);
		return (1);
	}
	if (pthread_mutex_init(&common->print.lock, NULL))
	{
		destroy_fork_mutex(common->fork, info.num_of_philo);
		pthread_mutex_destroy(&common->stop.lock);
		return (1);
	}
	common->print.value = 0;
	common->stop.value = 0;
	return (0);
}

int	make_forks(t_common *common, t_info info)
{
	int	i;

	common->fork = (t_mutex *)malloc(sizeof(t_mutex) * info.num_of_philo);
	if (!common->fork)
		return (-1);
	i = 0;
	while (i < info.num_of_philo)
	{
		common->fork[i].value = 1;
		if (pthread_mutex_init(&common->fork[i].lock, NULL))
			return (destroy_fork_mutex(common->fork, i), -1);
		i++;
	}
	return (0);
}
