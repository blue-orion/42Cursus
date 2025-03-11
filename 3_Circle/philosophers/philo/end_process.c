/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_process.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 23:19:42 by takwak            #+#    #+#             */
/*   Updated: 2025/03/11 22:07:01 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	end_process(t_philo *philo)
{
	int	i;

	i = 0;
	unlock_all_mutex(philo->info, philo->common);
	while (i < philo->info->num_of_philo)
	{
		if (philo[i].status == EXIT)
		{
			i++;
			continue ;
		}
		pthread_join(philo[i].tid, NULL);
		i++;
	}
	destroy_all_mutex(philo->info, philo->common);
	free(philo->common->fork);
	free(philo);
}
