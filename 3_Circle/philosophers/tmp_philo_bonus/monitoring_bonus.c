/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 20:58:23 by takwak            #+#    #+#             */
/*   Updated: 2025/03/17 21:20:30 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	monitoring(t_philo *philo)
{
	int	i;
	int	finish;
	int	status;

	finish = 0;
	while (1)
	{
		i = 0;
		while (i < philo->info->num_of_philo)
		{
			status = get_value(&philo[i].stop);
			printf("\n%d status = %d\n", philo[i].id, status);
			if (status == DIE)
				break ;
			if (status == EAT)
			{
				set_value(&philo[i].stop, COUNTED);
				finish++;
			}
			i++;
		}
		if (status == DIE || finish == philo->info->num_of_philo)
			break ;
		usleep(500000);
	}
	set_value(&philo->common->end, 1);
}
