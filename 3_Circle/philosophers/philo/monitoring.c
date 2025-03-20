/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyoengsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 18:48:48 by takwak            #+#    #+#             */
/*   Updated: 2025/03/19 18:05:37 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
			if (status == EAT)
			{
				finish++;
				set_value(&philo[i].stop, COUNTED);
			}
			if (status == DIE)
				break ;
			i++;
		}
		if (status == DIE || finish == philo->info->num_of_philo)
			break ;
		usleep(100);
	}
	set_value(&philo->common->stop, 1);
}
