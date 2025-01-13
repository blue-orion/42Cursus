/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_process.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 23:19:42 by takwak            #+#    #+#             */
/*   Updated: 2025/01/14 01:49:17 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	destroy_all_mutex(t_info *info, t_common *common)
{
	int	i;

	i = 0;
	while (i < info->num_of_philo)
	{
		pthread_mutex_unlock(&common->fork[i]);
		pthread_mutex_unlock(&common->fork[i]);
		pthread_mutex_unlock(&common->fork[i]);
		pthread_mutex_unlock(&common->fork[i]);
		pthread_mutex_unlock(&common->fork[i]);
		usleep(10000);
		pthread_mutex_destroy(&common->fork[i++]);
	}
	pthread_mutex_unlock(&common->die);
	pthread_mutex_destroy(&common->die);
	pthread_mutex_unlock(&common->log);
	pthread_mutex_destroy(&common->log);
}

void	end_process(t_philo *philo)
{
	int	i;

	destroy_all_mutex(philo->info, philo->common);
	printf("all mutex destory\n");
	free(philo->common->fork);
	printf("free fork\n");
	i = 0;
	while (i < philo->info->num_of_philo)
	{
		if (pthread_join(philo[i].tid, NULL))
			perror("join error");
		printf("join thread = %d\n", philo[i].id);
		i++;
	}
	printf("all process join\n");
	free(philo);
	printf("free philo\n");
}
