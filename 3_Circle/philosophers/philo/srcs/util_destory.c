/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_destory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 15:15:25 by takwak            #+#    #+#             */
/*   Updated: 2025/01/15 16:00:29 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int	destory_fork_mutex(pthread_mutex_t *forks, int num)
{
	int	i;

	i = 0;
	while (i < num)
	{
		pthread_mutex_destroy(&forks[i]);
		i++;
	}
	return (-1);
}

int	destroy_all_mutex(t_info *info, t_common *common)
{
	int	i;

	i = 0;
	usleep(1000000);
	while (i < info->num_of_philo)
	{
		pthread_mutex_unlock(&common->fork[i]);
		pthread_mutex_destroy(&common->fork[i++]);
	}
	pthread_mutex_destroy(&common->die);
	pthread_mutex_destroy(&common->log);
	return (-1);
}

void	*detach_all(t_philo *philos, int num)
{
	int	i;

	i = 0;
	while (i < num)
	{
		pthread_detach(philos[i].tid);
		i++;
	}
	return (NULL);
}
