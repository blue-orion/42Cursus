/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_process.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 23:19:42 by takwak            #+#    #+#             */
/*   Updated: 2025/01/15 15:36:40 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	end_process(t_philo *philo)
{
	int	i;

	destroy_all_mutex(philo->info, philo->common);
	free(philo->common->fork);
	i = 0;
	while (i < philo->info->num_of_philo)
	{
		if (pthread_join(philo[i].tid, NULL))
			perror("join error");
		i++;
	}
	free(philo);
}
